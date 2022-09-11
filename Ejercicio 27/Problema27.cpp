// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>

struct solucion{
    bool inter;
    long long int sumaAnterior;
};
// función que resuelve el problema
solucion interesante(bool inter, long long int num,long long int sumaPosterior) {
    if(num<10) {
        if(num==0 || sumaPosterior%(num%10)!=0) return {false,0};
        else return {true,num};
    }
    else{
        solucion sol=interesante(inter,num/10,sumaPosterior+(num%10));
        if(sol.inter){
            if(num%10==0||sumaPosterior%(num%10)!=0||sol.sumaAnterior%(num%10)!=0) return {false,0};
            else return {true,sol.sumaAnterior+((num%10))};
        }
        else return {false,0};       
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num;
    solucion sol=interesante(true,num,0);
    if(sol.inter) std::cout<<"SI"<<"\n";   
    else  std::cout<<"NO"<<"\n";   
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