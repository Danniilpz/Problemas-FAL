// Daniel López Marqués
// A41

#include <iostream>
#include <fstream>
#include <vector>


//*******************************
// Aqui explicacion de la función que resuelve el problema. 
// Utilizo una ventana de tamaño la longitud fija del intervalo, y la desplazo hasta el final del array buscando el intervalo maximo.
//
//
// Aqui la justificación del coste de la función que resuelve el problema
// Tiene coste lineal, de orden n puntos kilometricos, aproximadamente 8+6n
// 
// 
//*******************************


// Aqui la función implementada por el alumno para resolver el problema
int resolver(std::vector<int> const& v,int const& long_t,int& pos1,int&pos2) {
    int actual=0,max;
    for(int i=0;i<long_t;i++){
        actual+=v[i];
    }
    max=actual;
    pos1=0;
    for(int i=long_t;i<v.size();i++){
        actual-=v[i-long_t];
        actual+=v[i];
        
        if(actual>max){
            max=actual;
            pos1=i-long_t+1;
        } 
        else if(actual==max){
            pos2=i-long_t+1;
        }         
    }    
    if(pos2==-1||pos2<pos1) pos2=pos1;
    return max;    
}


// Resuelve cada caso de la entrada
bool resuelveCaso() {
    // Lectura de los datos
    int numKilometros, longitudTramo;
    std::cin >> numKilometros >> longitudTramo;
    if (numKilometros == 0 && longitudTramo == 0) return false;
    std::vector<int> v(numKilometros); // nombre y altura
    for (int & n : v) {
        std::cin  >> n;
    }
    int pos1,pos2=-1;
    // LLamada a la funcion que resuelve el problema
    int max=resolver(v,longitudTramo,pos1,pos2);
    
    
    // Escribir el resultado
    std:: cout<<max<<" "<<pos1<<" "<<pos2<<"\n";   

    return true;
}


int main() {
    // Para la entrada por fichero.
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); 
#endif
    
    while (resuelveCaso())
        ;
    
    // Para restablecer entrada. 
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

