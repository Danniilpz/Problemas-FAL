// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritme recorre el array y mediante 3 variables guarda el numero maximo de 
// repeticiones, el actual y el valor que mas se ha repetido

// Coste del algoritmo utilizado
// El coste es lineal a n accidentes, concretamente 5+5n

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
int resolver(std::vector<int> & v) {
    std::sort (v.begin(), v.end());
    int max=1, actual=1, valor=v[0];
    for(int i=0;i<v.size();i++){        
        if(i>0&&v[i]==v[i-1]) {
            actual++;
            if(actual>max){
                max++;
                valor=v[i];
            }            
        }
        else actual=1;
    }
    return valor;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num_acc;    
    std::cin>>num_acc;
    if (num_acc==-1)
        return false;
    std::vector<int> v(num_acc);
    for(int& n:v) std::cin>>n;

    int sol = resolver(v);
    
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
