// Daniel López Marqués 
// A41 


#include <iostream>
#include <iomanip>
#include <fstream>


using lli = long long int;
// función que resuelve el problema
lli fibonacci(int pos,lli num1,lli num2) {
    if(pos==0) return num2;
    else if(pos==1) return num1;
    else return fibonacci(pos-1, num1+num2,num1);
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num;
    if (! std::cin) return false;   
    std::cout<<fibonacci(num,1,0)<<"\n";    
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