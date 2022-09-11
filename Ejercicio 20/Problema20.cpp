// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int ninos, int alturaMax, int interval, std::vector<int> alturas) {
    std::vector<int> aux(alturaMax, 0);
    for (int i = 0; i < alturas.size(); i++) {
        aux[alturas[i]-1]++;
    }
    int maxNinos = 0, ninosActuales = 0;
    for (int i = 0; i < interval; i++) {
        ninosActuales += aux[i];
    }
    if (ninosActuales >= maxNinos) maxNinos = ninosActuales;
    for (int i = interval; i < aux.size(); i++) {
        ninosActuales -= aux[i - interval];
        ninosActuales += aux[i];
        if (ninosActuales >= maxNinos) maxNinos = ninosActuales;
    }
    return maxNinos;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int ninos, alturaMax, interval;
    std::cin >> ninos >> alturaMax >> interval;
    if (ninos == -1)
        return false;

    std::vector<int> alturas(ninos);
    for (int i = 0; i < ninos; i++) {
        std::cin >> alturas[i];
    }

    std::cout << resolver(ninos, alturaMax, interval, alturas);
    std::cout << "\n";

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
