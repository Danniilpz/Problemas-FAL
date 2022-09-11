// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

// función que resuelve el problema
std::vector<int> resolver(std::vector<int>& v1, std::vector<int>& v2) {
    std::vector<int> sol;
    std::sort (v1.begin(), v1.end());
    std::sort (v2.begin(), v2.end());
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size()){
        if(v1[i]<v2[j]) i++;
        else if(v1[i]>v2[j]) j++;
        else if(v1[i]==v2[j]){
            sol.push_back(v1[i]);
            i++;
            j++;
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v1,v2;
    bool first=false;
    int valor;
    std::cin>>valor;
    do{
        if(valor==0) first=true;
        else if(!first) v1.push_back(valor);
        else if(first) v2.push_back(valor);
        std::cin>>valor;
    } while(!first||valor!=0);
    
    std::vector<int> sol = resolver(v1,v2);
    for (int & x : sol) std :: cout << x << " ";
    std:: cout<<"\n";    
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