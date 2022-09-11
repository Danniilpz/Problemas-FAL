// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritmo llama recursivamente a una función pasandole como parametro el numero/10 en cada llamada, 
// hasta llegar al ultimo digito. En cada llamada selecciona el digito actual y comprueba su paridad, devolviendo un string con o sin ese digito.

// Coste del algoritmo utilizado
// El coste es lineal de orden n número de dígitos del número, aproximadamente 3n


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using lli = long long int;

// función que resuelve el problema
std::string resolverNoFinal(lli num) {

    int aux;
    if(num<10) {
        if(num%2!=0) return std::to_string(num);
        else return "";
    }
    else{                
        aux=num%10;
        if(aux%2!=0) return resolverNoFinal(num/10)+std::to_string(aux);
        else return resolverNoFinal(num/10); 
   
    }
}
lli resolverFinal(lli num,lli actual,int pot) {
    int aux;
     if(num<10) {
        if(num%2!=0) return num*pot+actual;
        else return actual;
    }
    else{                
        aux=num%10;
        if(aux%2!=0) return resolverFinal(num/10,aux*pot+actual,pot*10);
        else return resolverFinal(num/10,actual,pot); 
   
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
    lli sol;
    sol=resolverFinal(num,0,1);
    //if(sol=="") sol="0";
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