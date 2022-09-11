// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritme recorre el array del final al principio y 
//mediante variables va contando los intervalos de valores iguales que sean mayores que el mínimo, y la longitud maxima.

// Coste del algoritmo utilizado
// El coste es lineal a n accidentes, concretamente 14n+9

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using psi = std::pair<int,std::vector<int>>;


// función que resuelve el problema
psi resolver(std::vector<int> const& v, int const& min) {

    int long_max=0, long_actual=1, valorMax=0,valorActual=-1;
    std::vector<int> v2;
    for(int i=v.size()-1;i>=0;i--){          
        if(v[i]>valorMax) valorMax=v[i];
        if(v[i]!=valorActual) {                
            valorActual=v[i];
            if(long_actual>=min){
                if(long_actual>long_max) long_max=long_actual;
                v2.push_back(i+long_actual);
            }
            long_actual=1;
        }
        else if(v[i]>=valorMax){
            long_actual++;            
        }
        if(i==0){
            if(long_actual>=min){
                if(long_actual>long_max) long_max=long_actual;
                v2.push_back(i+long_actual-1);
            }
        }
    }
    psi sol;
    sol.first=long_max;
    sol.second=v2;
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num,min;
    std::cin>>num;
    if (! std::cin)
        return false;   

    std::cin>>min;
    std::vector<int> v(num);
    for(int& n:v) std::cin>>n;
    psi sol = resolver(v,min);
    
    // escribir sol
    std::cout<<sol.first<<" "<<sol.second.size()<<" ";
    for(int& n:sol.second) std::cout<<n<<" ";
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