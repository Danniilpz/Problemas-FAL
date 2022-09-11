// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritmo llama recursivamente a una función pasandole como parametro el numero/10 en cada llamada, 
// hasta llegar al ultimo caso. En cada llamada va construyendo el numero en orden inverso.

// Coste del algoritmo utilizado
// El coste es lineal de orden n número de dígitos del número


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema

std::pair<int,int> resolverNoFinal(int num) {
    if(num<10) return {num,10};
    else {        
        std::pair<int,int> sol=resolverNoFinal(num/10);
        return {sol.first+(num%10*sol.second),sol.second*10};
    }
}
int resolverFinal(int num,int sol) {
    if(num<10) {
        return sol*10+num;
    }
    else{
       return resolverFinal(num/10,sol*10+(num%10));
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num;
    if (num==0)
        return false;
    int sol=resolverNoFinal(num).first;
    
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