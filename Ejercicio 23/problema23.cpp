// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritmo llama recursivamente a una función pasandole como parametro el numero/10 en cada llamada, 
// hasta llegar al ultimo caso. En cada llamada incrementa el contador de la solucion.

// Coste del algoritmo utilizado
// El coste es lineal de orden n número de dígitos del número, aproximadamente 3n


#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
int resolverNoFinal(lli num) {
    if(num<10) {
        return 1;
    }
    else{
       return resolverNoFinal(num/10)+1;
    }
}
int resolverFinal(lli num,int sol) {
    if(num<10) {
        return sol+1;
    }
    else{
       return resolverFinal(num/10,sol+1);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    lli num;
    std::cin>>num;
    if (! std::cin)
        return false;
    int sol=resolverFinal(num,0);
    
    std::cout<<sol<<"\n";
    
    
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