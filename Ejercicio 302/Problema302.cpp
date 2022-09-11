// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolverNoFinal(int num,int max) {
    if(num<10){
        if(num<max) return 0;
        else return num;
    }
    else{
        if(num%10<max) return resolverNoFinal(num/10,max);
        else return resolverNoFinal(num/10,num%10)*10+num%10;
    }
}

int resolverFinal(int num,int nuevo,int pot,int max) {
    if(num<10){
        if(num<max) return nuevo;
        else return num*pot+nuevo;
    }
    else{
        if(num%10<max) return resolverFinal(num/10,nuevo,pot,max);
        else return resolverFinal(num/10,num%10*pot+nuevo,pot*10,num%10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num; 
    std::cout<<resolverNoFinal(num,0)<<" ";
    std::cout<<resolverFinal(num,0,1,0);  
    std::cout<<"\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}