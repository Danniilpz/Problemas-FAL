// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritmo recorre el array de datos y controla variables
//para encontrar la secuencia de mayor suma, de forma que cuando la suma es negativa descarta la secuencia.

// Coste del algoritmo utilizado
// El coste es lineal de orden n datos, exactamente 2+9n

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>




// función que resuelve el problema
void resolver(std::vector<int> const& v,int& sumaMax,int& longSegMax,int& posSegMax) {
    int sumaActual=0,longSegActual=0;
    for(int i=0;i<v.size();i++){
        sumaActual+=v[i];
        if(sumaActual>0){
            longSegActual++;
            if(sumaActual>sumaMax||(sumaActual==sumaMax&&longSegActual<longSegMax)){
                sumaMax=sumaActual;                
                posSegMax=i-longSegActual+1;
                longSegMax=longSegActual;
            } 
        }
        else{
            sumaActual=0;
            longSegActual=0;
        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int length,sumaMax=0,longSegMax=0,posSegMax;
    std::cin>>length;
    if (! std::cin)
        return false;   

    std::vector<int> v(length);
    for(int& n:v) std::cin>>n;
    resolver(v,sumaMax,longSegMax,posSegMax);
    std::cout<<sumaMax<<" "<<posSegMax<<" "<<longSegMax<<"\n";
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