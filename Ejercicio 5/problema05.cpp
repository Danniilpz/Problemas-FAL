// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
std::vector<int> resolver(std::vector<int> const& datos, int const& initial_year) {
    int max=datos[0];
    std::vector<int> sol;
    for(int i=1;i<datos.size();i++){
        if(datos[i]>max){
            max=datos[i];
            sol.push_back(initial_year+i);
        }
    }
    return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int anio_inicial, anio_final, length, num;
    std::vector<int> v;
    std::cin>> anio_inicial;
    std::cin>> anio_final;
    length=anio_final-anio_inicial+1;
    for(int i=0;i<length;i++){
        std::cin >> num;
        v.push_back(num);
    }
    std::vector<int> sol = resolver(v,anio_inicial);
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