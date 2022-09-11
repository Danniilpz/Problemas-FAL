// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(int interval, std::vector<int> const& puntuaciones) {
    int puntuacionMax=puntuaciones[0], indiceMax, maxPuntuacionTotal, puntuacionActual = puntuaciones[0], indice;
    for (int i = 1; i < interval; i++) {
        puntuacionActual += puntuaciones[i];
        if (puntuaciones[i]>= puntuacionMax) {
            puntuacionMax=puntuaciones[i];
            indiceMax=i;
        }
    }
    maxPuntuacionTotal=puntuacionActual;
    indice=0;
    for (int i = interval; i < puntuaciones.size(); i++) {
        puntuacionActual -= puntuaciones[i - interval];
        puntuacionActual += puntuaciones[i];
        if(puntuaciones[i]>puntuacionMax){
            puntuacionMax=puntuaciones[i];
            indice = i - interval + 1;
            maxPuntuacionTotal=puntuacionActual;
            indiceMax=i;
        }
        else if(puntuaciones[i]==puntuacionMax){
            indiceMax=i;
            if(puntuacionActual>=maxPuntuacionTotal){
                indice = i - interval + 1;
                maxPuntuacionTotal=puntuacionActual;
            }            
        }
        else{
            if(indiceMax>i-interval && puntuacionActual>=puntuacionMax){
                indice = i - interval + 1;
                maxPuntuacionTotal=puntuacionActual;
            }
        }
    }
    return indice;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int paginas, interval;
    std::cin >> paginas >> interval;
    if (paginas == 0)
        return false;

    std::vector<int> puntuaciones(paginas);
    for (int i = 0; i < puntuaciones.size(); i++) {
        std::cin >> puntuaciones[i];
    }

    std::cout << resolver(interval, puntuaciones);
    std::cout << "\n";

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
