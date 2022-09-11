// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    std::vector<int> sol;
    std::vector<int> solMejor;
    std::vector<int> marcas;
    int cont;
    int contMejor;
    int propinaMejor;
    int propinaActual;
    int tiempo;
    int tAux;
};

bool esValida(tSol& s,int& tiempoMax,int& i){
    bool marcado=s.marcas[i]>1;
    bool suficienteTiempo=s.tiempo<=tiempoMax;
    return !marcado&&suficienteTiempo;
}

void escribirSolucion(std::vector<int> v,int n) {
    for(int i=0;i<n;i++){
        std::cout << v[i] << " ";
    }
    std::cout << "\n";
}
// función que resuelve el problema
void resolver(int m, int n, int k, tSol& s, int& tiempoMax, std::vector<int> const& propinas, std::vector<int> const& tiempos) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        s.cont++;
        s.marcas[i]++;
        s.propinaActual+=propinas[i];
        s.tiempo+=tiempos[i]*2;
        if(esValida(s,tiempoMax,i)){
            //std::cout<<s.tiempo<<" "<<i<<" "<<s.propinaActual<<" "<<s.propinaMejor<<"\n";
            if(s.propinaActual>s.propinaMejor){
                    //std::cout<<s.propinaMejor<<"==>"<<s.propinaActual<<"\n";
                    s.propinaMejor=s.propinaActual;
                    s.solMejor=s.sol;
                    s.contMejor=s.cont;
                    s.tAux=s.tiempo;
            }           
            if(k<(n-1)){
                //ESTIMACION
                resolver(m,n,k+1,s,tiempoMax,propinas,tiempos);
            }

        }
        s.tiempo-=tiempos[i]*2;
        s.propinaActual-=propinas[i];
        s.marcas[i]--;
        s.cont--;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int paquetes, tiempoMax;
    std::cin >> paquetes >> tiempoMax;
    if (!std::cin) return false;
    std::vector<int> propinas(paquetes), tiempos(paquetes);
    for (int i = 0; i < paquetes; i++) {
        std::cin >> propinas[i];
    }
    for (int i = 0; i < paquetes; i++) {
        std::cin >> tiempos[i];
    }
    tSol s;
    s.sol.resize(paquetes);
    s.solMejor.resize(paquetes);
    s.marcas.resize(paquetes);
    s.propinaActual = 0;
    s.propinaMejor = 0;
    s.cont = 0;
    s.contMejor = 0;
    s.tiempo = 0;
    //Inicializo una solución
    int tiempoAux=0;
    for (int i = 0; i < paquetes; i++) {
        if (tiempos[i] <= tiempoMax && (tiempoAux+ tiempos[i]*2) <= tiempoMax) {
            s.solMejor[s.contMejor] = i;
            s.contMejor++;
            
            s.propinaMejor += propinas[i];
            tiempoAux += tiempos[i]*2;
        }
    }
    //calculo el máximo

    resolver(paquetes,paquetes,0,s,tiempoMax,propinas,tiempos);

    escribirSolucion(s.solMejor,s.contMejor);
    /*std::cout<<s.contMejor<<"\n";
    std::cout<<s.propinaMejor<<"\n";
    std::cout<<s.tAux<<"\n";*/

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