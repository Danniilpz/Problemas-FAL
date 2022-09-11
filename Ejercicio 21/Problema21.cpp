// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::pair<int, int> resolver(std::vector<int> marcas) {
    int maxInterval = 0, actualInterval = 0, iniInterval = 0, iniActual = 1, pruebaMax = marcas[0];
    for (int i = 1; i < marcas.size(); i++) {
        if (marcas[i] > pruebaMax) {
            pruebaMax = marcas[i];

            iniActual = i + 1;
            actualInterval = 0;
        }
        else {
            actualInterval++;
            if (maxInterval <= actualInterval) {
                maxInterval = actualInterval;
                iniInterval = iniActual;
            }
            
        }
    }
    if (maxInterval == 0) iniInterval = iniActual;
    return { maxInterval,iniInterval };
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin >> len;
    if (len == 0)
        return false;

    std::vector<int> marcas(len);
    for (int i = 0; i < len; i++) {
        std::cin >> marcas[i];
    }

    std::cout << resolver(marcas).first << " " << resolver(marcas).second;
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
