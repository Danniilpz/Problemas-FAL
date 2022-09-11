// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tSol {
    std::vector<bool> sol;
    std::vector<bool> solMejor;
    int superficieActual;
    int superficieMejor;
    int costeActual;
};

int estimar(std::vector<std::pair<int, int>> const& datosLuces,tSol& s,int k,int costeMax){
    int costeActual=s.costeActual,sumaSuperficie=0,i;
    for (i = k+1; i < datosLuces.size() && costeActual + datosLuces[i].first <= costeMax; i++) {
        sumaSuperficie += datosLuces[i].second;
        costeActual += datosLuces[i].first;
    }
    //La parte sin completar
    if (i < datosLuces.size() && costeActual< costeMax) {
        int superficieCoste=datosLuces[i].second/(float)datosLuces[i].first;
        sumaSuperficie+=datosLuces[i].second*(costeMax-costeActual)/(float)datosLuces[i].first;
    }
    return sumaSuperficie;

}

// función que resuelve el problema
void resolver(int n, int k, tSol& s, std::vector<std::pair<int, int>> const& datosLuces, int& costeMax) {
    //Cojo el objeto
    s.sol[k] = true;
    s.costeActual += datosLuces[k].first;
    s.superficieActual += datosLuces[k].second;
    if (s.costeActual <= costeMax) {
        if (k == n - 1) {
            if (s.superficieMejor < s.superficieActual) {
                s.superficieMejor = s.superficieActual;
                s.solMejor = s.sol;
            }
        }
        else {            
            resolver(n, k+1, s, datosLuces, costeMax);
        }
    }
    s.superficieActual -= datosLuces[k].second;
    s.costeActual -= datosLuces[k].first;
    //No cojo el objeto
    s.sol[k] = false;
    //Siempre es valido
    if (k == n - 1) {
        if (s.superficieMejor < s.superficieActual) {
            s.superficieMejor = s.superficieActual;
            s.solMejor = s.sol;
        }
    }
    else {        
        if(estimar(datosLuces,s,k,costeMax)+s.superficieActual>s.superficieMejor){
            resolver(n, k+1, s, datosLuces, costeMax);
        }
    }
}

int inicializar(std::vector<std::pair<int, int>> const& datosLuces,int costeMax){
    int superficieMejor=0,costeActual=0;
    for (int i = 0; i < datosLuces.size() && costeActual + datosLuces[i].first <= costeMax; i++) {
        superficieMejor += datosLuces[i].second;
        costeActual += datosLuces[i].first;
    }
    return superficieMejor;
}
class comparador {
public:
    bool operator ()(std::pair <int, int > p1, std::pair <int, int > p2) {
        return (float)p1.second / p1.first > (float)p2.second / p2.first;
    }
};

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int luces, costeMax;
    std::cin >> luces >> costeMax;
    if (!std::cin)
        return false;
    std::vector<std::pair<int, int>> datosLuces;
    for (int i = 0; i < luces; i++) {
        std::pair<int, int> p;
        std::cin >> p.first >> p.second;
        datosLuces.push_back(p);
    }
    tSol s;
    s.sol.resize(luces);
    s.solMejor.resize(luces);
    s.costeActual = 0;
    s.superficieActual = 0;
    s.superficieMejor = 0;
    for(std::pair<int,int> p:datosLuces) std::cout<<p.first<<" "<<p.second<<"\n";
    std::cout<<"\n";
    std::sort(datosLuces.begin(), datosLuces.end(), comparador());
    for(std::pair<int,int> p:datosLuces) std::cout<<p.first<<" "<<p.second<<"\n";
    std::cout<<"\n";
    //Inicializo la superficieMejor    
    s.superficieMejor=inicializar(datosLuces,costeMax);

    resolver(luces, 0, s, datosLuces, costeMax);

    std::cout << s.superficieMejor << "\n";
    // escribir sol


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