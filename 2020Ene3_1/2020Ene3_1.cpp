// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v) {
    int segMax=1,segActual=1,crecientes=1;
    for(int i=1;i<v.size();i++){
        segActual++;
        if(v[i]>v[i-1]) crecientes++;
        else crecientes=1;

        if(crecientes==3){
            segActual=2;
            crecientes=2;
        }
        else{
            if(segActual>segMax) segMax=segActual;
        }
    }
    return segMax;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    std::vector<int> v(len);
    for(int& n:v) std::cin>>n;
    std::cout<< resolver(v);
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