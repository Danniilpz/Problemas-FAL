// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

struct tDatos {
    std::vector<int> salarios;
    tMatriz puntuaciones;
    int puntuacionMinima;
    int presupuesto;
};
struct tSol {
    std::vector<int> sol;
    std::vector<int> solMejor;
    std::vector<int> marcas;
    int puntuacion;
    int puntuacionMejor;
    int gasto;
    int gastoMejor;
};

bool esValida(int i, int k, tDatos& d, tSol& s) {
    
    bool suficientePuntuacion = d.puntuacionMinima <= d.puntuaciones[i][k];
    bool actorRepetido = s.marcas[i] > 1;
    return suficientePuntuacion && !actorRepetido;
}

bool esSolucion(tSol& s, tDatos& d) {
    bool presupuestoSuficiente = s.gasto <= d.presupuesto;
    return presupuestoSuficiente;
}
// función que resuelve el problema
void resolver(int m, int n, int k, tDatos& d, tSol& s,std::vector<int> acum,int valorMax) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        s.gasto += d.salarios[i];
        s.marcas[i]++;
        s.puntuacion += d.puntuaciones[i][k];
        if (esValida(i, k, d, s)) {
            if (k == n - 1) {
                if (esSolucion(s, d)) {
                    if (s.puntuacionMejor < s.puntuacion) {
                        s.solMejor = s.sol;
                        s.puntuacionMejor = s.puntuacion;
                        s.gastoMejor = s.gasto;
                    }
                }                
            }
            else {
                if (valorMax + s.puntuacion > s.puntuacionMejor)
                    resolver(m, n, k + 1, d, s,acum,valorMax);
            }
        }
        s.puntuacion -= d.puntuaciones[i][k];
        s.marcas[i]--;
        s.gasto -= d.salarios[i];
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int papeles, actores, presupuesto, puntuacionMinima;
    std::cin >> papeles >> actores >> presupuesto >> puntuacionMinima;
    if (papeles == 0)
        return false;
    std::vector<int> salarios(actores);
    for (int& n : salarios) std::cin >> n;
    tMatriz puntuaciones;
    int valorMax=0;
    for (int i = 0; i < actores; i++) {
        std::vector<int> aux(papeles);
        for (int& j : aux) {
            std::cin >> j;
            if(j>valorMax) valorMax=j;
        }
        puntuaciones.push_back(aux);
    }
    tDatos d;
    d.presupuesto = presupuesto;
    d.puntuaciones = puntuaciones;
    d.puntuacionMinima = puntuacionMinima;
    d.salarios = salarios;
    tSol s;
    s.sol.resize(papeles);
    s.solMejor.resize(papeles);
    s.marcas.resize(actores);
    s.puntuacionMejor = 0;
    s.puntuacion = 0;
    s.gasto = 0;
    s.gastoMejor = 0;
    //Vector de maximos
    std::vector<int> acum(actores);
    for (int i = 0; i < actores; i++) {
        int max = 0;
        for (int j = 0; j < papeles; j++) {
            if (puntuaciones[i][j] > max) max = puntuaciones[i][j];
        }
        acum[i] = max;
    }
    //Vector de acumulados
    for (int i = acum.size() - 1; i > 0; i--) {
        acum[i - 1] += acum[i];
    }
    resolver(actores, papeles, 0, d, s, acum,valorMax);
    std::cout << s.puntuacionMejor << " " << s.gastoMejor << "\n";
    for (int i = 0; i < s.solMejor.size(); i++) {
        std::cout << i << " " << s.solMejor[i] << "\n";
    }
    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
