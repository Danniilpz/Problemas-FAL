// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>

using lli=long long int;
using psi=std::pair<bool,lli>;

// función que resuelve el problema
psi resolver(lli num) {
    if(num==0||num==1) return {false,1};
    else if(num<10) return {true,num};
    else{
        psi sol=resolver(num/10);
        int aux=num%10;
        if(sol.first){
            if(aux==0) return {true,sol.second*9-8};
            else if(aux==1) return {false,sol.second*9-8};
            else if(aux>1) return {true,sol.second*9-(9-aux)};   
        }
        else return {false,sol.second*9};
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
    std::cout<<resolver(num).second<<"\n";
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