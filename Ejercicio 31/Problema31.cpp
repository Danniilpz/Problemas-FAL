// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char binarySearch(std::vector<char> const& v,int ini,int fin) {
    if(ini==fin) return v[ini]-1;
    else if((ini+1)==fin) return v[ini]+1;
    else{
        int mitad=(ini+fin)/2;
        if((v[mitad]-v[0])!=((mitad)-0)) return binarySearch(v,ini,mitad);
        else if((v[fin]-v[mitad+1])!=(fin-(mitad+1))) return binarySearch(v,mitad+1,fin);
        else return v[mitad]+1;
    }   
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini,fin;
    int len;
    std::vector<char> datos;
    std::cin>>ini>>fin;
    len=fin-ini;
    char n;
    for(int i=0;i<len;i++){
        std::cin>>n;
        datos.push_back(n);        
    }
    if(datos[0]!=ini) std::cout<<ini<<"\n";
    else if(datos[len-1]!=fin) std::cout<<fin<<"\n";
    else std::cout<<binarySearch(datos,0,datos.size()-1)<<"\n";   
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