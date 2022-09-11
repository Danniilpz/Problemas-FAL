// Nombre y apellidos del alumno
// Usuario del juez de clase

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>

// Explicación del algoritmo utilizado

// Coste del algoritmo utilizado



// Función que resuelve el problema
// Recibe un vector con los datos
// Devuelve suma de los valores y número de sumandos de la suma
void resolver(std::vector<int> const& datos,int& suma, int& numero) {
    // Inicialización de variables
    // Codigo del alumno
    int min=datos[0],nummin=1;
    for (int i = 1; i < datos.size(); ++i) {
        
        // Aqui el código del alumno
        // No deben hacerse más bucles
        if(datos[i]<min){            
            suma=suma+(nummin*min); //sumo el anterior min el numero de veces que habia aparecido
            numero+=nummin;
            min=datos[i];
            nummin=1;
        } 
        else if(datos[i]==min){
            nummin++;
        }
        else if(datos[i]!=min){
            suma+=datos[i];
            numero++;
        }     
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // Lectura de los datos
    int numElem, suma=0, numero=0;
    std::cin >> numElem;
    std::vector<int> v(numElem);
    for (int& i : v) std::cin >> i;
    // LLamar a la función resolver
    resolver(v,suma,numero);
    // Escribir los resultados
    std::cout << suma << ' ' << numero << '\n';
}

int main() {
    // Para la entrada por fichero. Comentar para mandar a acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("sample03.in");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
 
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i) resuelveCaso();
    
    // Para restablecer entrada. Comentar para mandar a acepta el reto

#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}
