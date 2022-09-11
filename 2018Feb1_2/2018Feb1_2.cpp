// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int>const& v, int ini, int fin) {    
    if (ini == fin) return v[ini];
    else {
        int mitad = (ini + fin) / 2;
        if (v[mitad] % 2 != 0) return v[mitad];
        else if (v[mitad]-v[0]==mitad*2) return resolver(v, mitad + 1, fin);
        else return resolver(v, ini, mitad);
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin >> len;
    if (len == 0)
        return false;
    std::vector<int> v(len);
    for (int& n : v) std::cin >> n;

    std::cout << resolver(v, 0, len - 1);
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
