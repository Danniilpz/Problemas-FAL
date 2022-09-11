// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz = std::vector<std::vector<int>>;

struct tSol {
    std::vector<int> sol;
    std::vector<int> solMejor;
    std::vector<int> basuraPlaya;
    int basura;
    int basuraMejor;
    int contPlayas;
    int contMejor;
};

struct tDatos {
    int minimoPlayas;
    tMatriz basuraPersonaPlaya;
};


bool esValida(int i, tSol& s, tDatos& d) {
    bool playaTieneBasura = s.basuraPlaya[i] > 0;
    return playaTieneBasura;
}
bool esSolucion(tSol& s, tDatos& d) {
    bool suficientesPlayas = s.contPlayas >= d.minimoPlayas;
    return suficientesPlayas;
}
// función que resuelve el problema
void resolver(int m, int n, int k, tSol& s, tDatos& d) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        s.basura += d.basuraPersonaPlaya[k][i];
        if (esValida(i, s, d)) {
            s.basuraPlaya[i] -= d.basuraPersonaPlaya[k][i];
            if (s.basuraPlaya[i] <= 0) {
                s.basura -= (-s.basuraPlaya[i]);
                s.contPlayas++;
            }

            if (k == n - 1) {
                if (esSolucion(s, d)) {
                    if (s.basura > s.basuraMejor) {
                        s.basuraMejor = s.basura;
                        s.sol = s.solMejor;
                        s.contMejor = s.contPlayas;
                    }
                }
            }
            else {
                resolver(m, n, k + 1, s, d);
            }

            if (s.basuraPlaya[i] <= 0) {
                s.basura += (-s.basuraPlaya[i]);
                s.contPlayas--;
            }
            s.basuraPlaya[i] += d.basuraPersonaPlaya[k][i];
        }
        s.basura -= d.basuraPersonaPlaya[k][i];
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int personas, playas, minimoPlayas;
    std::cin >> personas>> playas>> minimoPlayas;
    std::vector<int> basuraPlaya(playas);
    for (int& n : basuraPlaya) std::cin >> n;
    tMatriz basuraPersonaPlaya(personas);
    for (int i = 0; i < personas; i++) {
        std::vector<int> aux(playas);
        for (int& n : aux) std::cin >> n;
        basuraPersonaPlaya[i] = aux;
    }
    tSol s;
    s.sol.resize(personas);
    s.solMejor.resize(personas);
    s.contPlayas = 0;
    s.basuraPlaya = basuraPlaya;
    s.basuraMejor = 0;
    s.basura = 0;
    tDatos d;
    d.basuraPersonaPlaya = basuraPersonaPlaya;
    d.minimoPlayas = minimoPlayas;

    /*//Inicializacion
    int correcto=false;
    while(!correcto){
        for(int i=0;i<personas;i++){
            bool asignado=false;
            for(int j;j<playas&&!asignado;j++){
                if(s.basuraPlaya[j]>0){
                    s.solMejor[i]=j;
                    asignado=true;
                    s.contMejor++;
                } 
            }
        }
        if(s.contMejor>=d.minimoPlayas) correcto=true;
    }*/


    resolver(playas, personas, 0, s, d);
    if (s.contMejor>=d.minimoPlayas) std::cout << s.basuraMejor << " " << s.contMejor;
    else std::cout << "IMPOSIBLE";
    std::cout << "\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}