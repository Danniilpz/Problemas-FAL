// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tSol {
    std::vector<bool> sol;
    std::vector<bool> solMejor;
    int propinaMejor;
    int propinaActual;
    int tiempo;
};

bool esValida(tSol& s, int& tiempoMax) {
    bool suficienteTiempo = s.tiempo <= tiempoMax;
    return suficienteTiempo;
}

void escribirSolucion(std::vector<bool> v) {
    for (int i = 0; i < v.size(); i++) {
        if (v[i]) std::cout << i << " ";
    }
    std::cout << "\n";
}
int estimar(tSol& s, int k, std::vector<std::pair<int, int>> const& tiempoPropina, int& tiempoMax) {
    int tiempoAux = s.tiempo, propinaAux = 0, i;
    for (i = k + 1; i < s.sol.size() && (tiempoAux + (tiempoPropina[i].first * 2)) <= tiempoMax; i++) {
        tiempoAux += tiempoPropina[i].first * 2;
        propinaAux += tiempoPropina[i].second;
    }
    if (i < s.sol.size() && tiempoAux < tiempoMax) {
        propinaAux += (tiempoPropina[i].second * (tiempoMax - tiempoAux)) / (tiempoPropina[i].first * 2);
    }
    return propinaAux;
}
// función que resuelve el problema
void resolver(int n, int k, tSol& s, int& tiempoMax, std::vector<std::pair<int, int>> const& tiempoPropina) {

    s.sol[k] = true;
    s.propinaActual += tiempoPropina[k].second;
    s.tiempo += tiempoPropina[k].first * 2;
    if (esValida(s, tiempoMax)) {
        if (k == n - 1) {
            if (s.propinaActual > s.propinaMejor) {
                s.propinaMejor = s.propinaActual;
                s.solMejor = s.sol;
            }
        }

        else {
            resolver(n, k + 1, s, tiempoMax, tiempoPropina);
        }

    }
    s.tiempo -= tiempoPropina[k].first * 2;
    s.propinaActual -= tiempoPropina[k].second;

    s.sol[k] = false;
    //Siempre es valido
    if (k == n - 1) {
        if (s.propinaActual > s.propinaMejor) {
            s.propinaMejor = s.propinaActual;
            s.solMejor = s.sol;
        }
    }

    else {
        if (estimar(s, k, tiempoPropina, tiempoMax) + s.propinaActual > s.propinaMejor) {
            resolver(n, k + 1, s, tiempoMax, tiempoPropina);
        }
    }

}
class comparador {
public:
    bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};
int inicializar(std::vector<std::pair<int, int>> const& tiempoPropina, int tiempoMax, tSol& s) {
    int propinaMejor = 0, tiempoActual = 0;
    for (int i = 0; i < tiempoPropina.size(); i++) {
        if (tiempoPropina[i].first <= tiempoMax && (tiempoActual + tiempoPropina[i].first * 2) <= tiempoMax) {
            s.solMejor[i] = true;
            propinaMejor += tiempoPropina[i].second;
            tiempoActual += tiempoPropina[i].first * 2;
        }
        else {
            s.solMejor[i] = false;
        }
    }
    return propinaMejor;
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int paquetes, tiempoMax;
    std::cin >> paquetes >> tiempoMax;
    if (!std::cin) return false;
    std::vector<std::pair<int, int>> tiempoPropina(paquetes);
    for (int i = 0; i < paquetes; i++) {
        std::cin >> tiempoPropina[i].second;
    }
    for (int i = 0; i < paquetes; i++) {
        std::cin >> tiempoPropina[i].first;
    }
    tSol s;
    s.sol.resize(paquetes);
    s.solMejor.resize(paquetes);
    s.propinaActual = 0;
    s.propinaMejor = 0;
    s.tiempo = 0;

    //Ordeno el vector por propina/tiempo
    std::sort(tiempoPropina.begin(), tiempoPropina.end(), comparador());

    //Inicializo la propina mejor
    s.propinaMejor = inicializar(tiempoPropina, tiempoMax, s);
    //s.propinaMejor=0;

    resolver(paquetes, 0, s, tiempoMax, tiempoPropina);

    escribirSolucion(s.solMejor);

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("casosPequenios.in");
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