// Daniel López Marqués
// A41

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>

// Explicación del algoritmo utilizado

//El algoritmo crea un array auxiliar del tamaño del rango de valores, 
//y recorre el array de tiradas utilizando el auxiliar como contador(si aparece un 5, suma 1 a la pos 5 del auxiliar)

// Coste del algoritmo utilizado

// El coste es lineal, siendo como máximo numTiradas+maximoValores


// Recibe un vector con los datos de entrada del problema
// Debe contar el número de veces que aparece cada valor usando un vector auxiliar.
// Devuelve un vector con los valores que se repiten el número máximo de veces
// para que la función resuelveCaso solo tenga que escribirlos. 
// Si solo hay un valor que se repite el número máximo de veces el vector de salida
// tendrá solo ese valor 
std::vector<int> resolver(std::vector<int> const& v, int maximoValores){
   // Aqui codigo del estudiante
    std::vector<int> contador(maximoValores),sol;
    int max=0;
    for (int i : v){
        contador[i-1]+=1;
        if(contador[i-1]>max) max=contador[i-1];
    }
    for (int i=contador.size()-1;i>=0;i--){
        if(contador[i]==max) sol.push_back(i+1);
    }
    return sol;    
}

// Entrada y salida de datos
bool resuelveCaso() {
    int numTiradas, valorMax;
    std::cin >> numTiradas >> valorMax;
    if (numTiradas == -1) return false;  // Entrada con centinela
    std::vector<int> v(numTiradas);
    for (int& i : v) std::cin >> i;
    // LLamada a la funcion resolver para calcular los valores que 
    // aparecen más veces
    std::vector<int> sol=resolver(v,valorMax);    
    // Escribir los valores del vector que ha calculado resolver
    for (int & x : sol) std :: cout << x << " ";
    std:: cout<<"\n";
    
    return true;
}

int main() {
    
#ifndef DOMJUDGE
    std::ifstream in("1.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt    
#endif
    
    while (resuelveCaso()) 
        ;
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}

