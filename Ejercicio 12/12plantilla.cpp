// Daniel López Marqués
// A41

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


// Explicación del algoritmo utilizado
// Utilizo el algoritmo de partición explicado en clase
// Coste del algoritmo utilizado
// El coste es lineal al numero de cintas, 9n+3

using psi = std::pair<char, int>;

// Recibe un vector con los datos de entrada del problema
// Modifica este vetor dejando en las primeras posiciones 
// las cintas azules, luego las verdes y uego las rojas
// NO se puede utilizar sort
// p es la primera posicion de una cinta verde, q es la ultima posicion de una cinta verde
void particion (std::vector<psi> & v, int &p, int &q) {
    // Aqui codigo del estudiante
    int k=0;
    p=0;
    q=(int) v.size()-1;
    while(k<=q){
        if(v[k].first == 'v') k++;
        else if(v[k].first == 'a') {
            swap(v[k],v[p]);
            p++;
            k++;
        }
        else if(v[k].first == 'r'){
            swap(v[q],v[k]);
            q--;
        }
    }
}


// Entrada y salida de datos
bool resuelveCaso() {
    // Lectura de los datos de entrada
    int numCintas;
    std::cin >> numCintas;
    if (!std::cin) return false;
    std::vector<psi> v(numCintas); // nombre y altura
    for (psi & n : v) {
        std::cin  >> n.first >> n.second;
    }
    // LLamada a la función paticion
    int p, q;
    particion(v, p, q);
    // Ordena cada parte para la salida de datos
    std::sort(v.begin(), v.begin()+p);
    std::sort(v.begin()+p, v.begin()+(q+1));
    std::sort(v.begin()+(q+1), v.end());
    // Escribe las cintas azules
    std::cout << "Azules:";
    for (int i = 0; i < p; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la segunda parte
    std::cout << "Verdes:";
    for (int i = p; i <= q; ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    // Escribe la tercera parte
    std::cout << "Rojas:";
    for (int i = q+1; i < v.size(); ++i){
        std::cout << ' ' << v[i].second ;
    }
    std::cout << '\n';
    return true;
}



int main() {

#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso()) {} //Resolvemos todos los casos
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif   
    return 0;
}
