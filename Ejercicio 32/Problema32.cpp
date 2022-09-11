// Daniel López Marqués
// A41



#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> const& v1,std::vector<int> const& v2,int ini,int fin) {
    if((ini+1)==fin) {
        return v2[ini]==v1[ini+1]?v1[ini+2]:v1[ini+1];
    }
    else if(ini==fin){        
        return v2[ini]==v1[ini]?v1[ini+1]:v1[ini];
    }
    else{
        int mitad=(ini+fin)/2;
        if(v1[mitad]!=v2[mitad]) return resolver(v1,v2,ini,mitad);
        else if(v1[mitad+2]!=v2[mitad+1]) return resolver(v1,v2,mitad+1,fin);
        else return v1[mitad+1];
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    std::vector<int> v1,v2;
    int n;
    for(int i=0;i<len;i++){
        std::cin>>n;
        v1.push_back(n);        
    }
    for(int i=0;i<len-1;i++){
        std::cin>>n;
        v2.push_back(n);        
    }
    if(v2.size()==0) std::cout<<v1[0];
    else if(v2[0]!=v1[0]) std::cout<<v1[0];
    else if(v2[len-2]!=v1[len-1]) std::cout<<v1[len-1];
    else std::cout<<resolver(v1,v2,0,v2.size()-1);
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