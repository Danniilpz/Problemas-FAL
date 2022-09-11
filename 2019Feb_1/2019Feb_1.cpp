// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v,int& intervalMin) {
    int contador=0,actualInterval=1,i=1;
    while(i<v.size()){
        int diff=v[i-1]-v[i];
        if(diff<=1&&diff>=-1&&actualInterval>=intervalMin){
            contador++;
            actualInterval=0;
        }
        else actualInterval++;
        i++;
    }
    return contador;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,intervalMin;
    std::cin>>len>>intervalMin;
    if (len==0)
        return false;
    std::vector<int> serie(len);
    for (int &n:serie) std::cin>>n;
    std::cout<<resolver(serie,intervalMin);

    std::cout<<"\n";
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
