// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado
// El algoritmo recorre el array y cada vez que encuentra un valor par, incrementa un contador 
//y lo asigna a la posicion correspondiente al contador. Finalmente, acorta el array hasta el número de pares que haya.


// Coste del algoritmo utilizado
//El coste es lineal, en el caso peor exactamente 2+3n, siendo n el tamaño del array de numeros de matricula.


// Esta función recibe un vector con los números de matricula de los alumnos
// Modifica el vector de entrada eliminando los valores impares
void resolver (std::vector<int> & v) {
    // Codigo del alumno
    int  pares=0;
    for (int i=0;i<v.size();i++) {
        if (v[i]%2 ==0 ){ 
            v[pares] = v[i];   
            pares++;  
        }
    }
    v.resize(pares);  
}

// Funcion que lee de la entrada, 
// LLama a la función que resuelve el problema
// Escribe la salida
bool resuelveCaso() {
    // Leer datos de entrada
    int numElem;
    std::cin >> numElem;
    if (numElem == -1) return false;
    std::vector<int> v(numElem);
    for (int i = 0; i < numElem; ++i) {
        std::cin >> v[i];
    }
    // LLamada a la función resolver
    resolver(v);
    // Escribir el vector resultado
    if (v.size() > 0) std::cout << v[0];
    for (int i = 1; i < v.size(); ++i)
        std::cout << ' ' << v[i];
    std::cout << '\n';
    return true;
}

int main() {
    // Para la entrada por fichero. Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif

    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
