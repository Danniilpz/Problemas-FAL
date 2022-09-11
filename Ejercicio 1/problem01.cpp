
// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado


// Funcion que lee de la entrada, resuelve el problema y escribe la salida
void resuelveCaso() {
    int n;
    std::cin >> n;
    // Declaración de variables
    // Codigo del alumno
    int max,rep=0;
    max=n;
    while (n != 0) {
        
        // Aqui codigo del alumno
        if(n>max) {
            max=n;
            rep=1;
        } else if(n==max){
            rep++;
        }
        
        std::cin >> n;
    }
std::cout << max <<" "<< rep <<std::endl;    
    // Escribir el resultado
    // Codigo del alumno
    
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("datos.txt");
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
