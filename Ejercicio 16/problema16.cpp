// Daniel López Marqués
// A41

// Explicación del algoritmo utilizado
// El algoritmo recorre el array de numeros y tiene dos variables indicando la proxima 
//posicion par e impar, en función de si el valor actual es par o impar y la posicion es par o impar, reordena los valores.

// Coste del algoritmo utilizado
// El coste es lineal de orden n datos

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>




// función que resuelve el problema
void resolver(std::vector<int>& v) {
    int nextOdd=1,nextPair=0;
    for(int i=0;i<v.size();i++){
        if(v[i]%2!=0){
            if(i%2!=0){
                if(i==nextOdd){
                    nextOdd+=2;
                } 
                else if(i>nextOdd){
                    if(nextOdd<v.size()) std::swap(v[i],v[nextOdd]);
                    nextOdd+=2;
                }
            }
            else{
                if(nextOdd<v.size()) std::swap(v[i],v[nextOdd]);
                nextOdd+=2;
                if(v[i]%2==0&&nextPair<v.size()) {
                    std::swap(v[i],v[nextPair]);
                    nextPair+=2;
                }
            }
        }
        else{
            if(i%2==0){
                if(i==nextPair){
                    nextPair+=2;
                } 
                else if(i>nextPair){
                    if(nextPair<v.size()) std::swap(v[i],v[nextPair]);
                    nextPair+=2;
                }
            }
            else{
                if(nextPair<v.size()) std::swap(v[i],v[nextPair]);
                nextPair+=2;
                if(v[i]%2!=0&&nextOdd<v.size()) {
                    std::swap(v[i],v[nextOdd]);
                    nextOdd+=2;
                }
            }
        }
    }
    if(nextPair>nextOdd) v.resize(nextOdd-1);
    else v.resize(nextPair);
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
    resolver(v);
    for (int i = 0; i < v.size(); ++i)
        std::cout <<v[i]<<' ';
    std::cout << '\n';
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