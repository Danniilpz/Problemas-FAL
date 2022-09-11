// Daniel López Marqués
// A41

//O(n)= c1 n=1
//      c2 n=2
//      O(n/2)+c3 n>2

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> const& v,int ini,int fin) {
    if(ini==fin) return v[ini];
    else if(ini+1==fin) return v[ini]<=v[fin]?v[ini]:v[fin]; 
    else{
        int mitad=(ini+fin)/2;
        if(v[mitad]<v[mitad+1]) return v[mitad];
        else if(v[mitad]>v[mitad-1]) return v[mitad-1];
        else if(v[ini]<v[mitad]) return resolver(v,ini,mitad);
        else return resolver(v,mitad+1,fin);
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,num;
    std::vector<int> v;
    std::cin>>len;
    if (! std::cin)
        return false;
    for(int i=0;i<len;i++){
        std::cin>>num;
        v.push_back(num);
    }
    std::cout<<resolver(v,0,v.size()-1)<<"\n";
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