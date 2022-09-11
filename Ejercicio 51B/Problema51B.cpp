// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz=std::vector<std::vector<int>>;

// Solucion que se va construyendo
struct tSol {
    std::vector <int> sol;
    int sumaSatis;
};
// Parametros :
// datos de entrada
// m - numJuguetes
// n - numNinos
// k - etapa
// s - Solucion que se va construyendo
// asignados - Vector de dimension el numero de juguetes marca los juguetes ya asignados
// acum - vector con la satisfaccion acumulada desde cada ninno hasta el ultimo
// satisMejor - la satisfacion maxima
void resolver(int m, int n, tmatriz const& satis, int k, tSol& s, std::vector <bool>& asignados, int& satisMejor, std::vector<int>  const& acum) {
  for (int i=0;i<m;i++) {
    s.sol[k]=i;
    if (!asignados[i]) { // esValida
        s.sumaSatis+=satis[k][i];
        asignados[i]=true; // marca
        if (k == n-1) { // es solucion
            if (s.sumaSatis > satisMejor) satisMejor = s.sumaSatis; // solucion mejor
        } else { // No es solucion
            if (s.sumaSatis+acum[k+1]>satisMejor) // Estimacion
                resolver(m,n,satis, k + 1, s, asignados, satisMejor, acum);
        }
        asignados[i]=false; // desmarca
        s.sumaSatis-=satis[k][i];
    }
  }
}
bool resuelveCaso() {
  // Lectura de los datos de entrada
    int numJuguetes,numNinos;
    tmatriz satis;
    std::cin>>numJuguetes>>numNinos;
    if (!std::cin) return false;
      // Lee la satisfaccion que les proporcionan los juguetes a los ninnos
    for (int i = 0; i < numNinos; i++) {
        std::vector <int> aux(numJuguetes);
        for (int j = 0; j < numJuguetes; ++j) std::cin >> aux[j];
        satis.push_back(aux);
    }
    // Calcula el vector de maximos
    std::vector <int> acum(numNinos);
    for (int i = 0; i < numNinos; i++) {
        int auxMax = satis[i][0];
        for (int j=1; j<numJuguetes; j++)
            if (auxMax < satis[i][j]) auxMax = satis[i][j];
        acum[i] = auxMax;
    }
    // Vector acumulados
    for (int i = acum.size()-1; i>0; i--) {
        acum[i-1] += acum[i];
    }
    // Obtiene una inicializacion posible para la solucion mejor
    int satisMejor = 0;
    for (int i = 0; i < numNinos; i++) {
        satisMejor += satis[i][i];
    }
    // Prepara los datos de la funcion
    tSol s;
    s.sol.assign(numNinos, 0);
    s.sumaSatis = 0;
    std::vector < bool > asignados(numJuguetes, false);
    resolver(numJuguetes,numNinos,satis, 0, s, asignados, satisMejor, acum);
    std::cout << satisMejor << '\n';
    return true;
}
int main() {
    # ifndef DOMJUDGE
    std::ifstream in ("1.in");
    auto cinbuf = std::cin.rdbuf( in .rdbuf());
    # endif

    while (resuelveCaso()) {} // Resolvemos todos los casos

    # ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system(" PAUSE ");
    # endif
    return 0;
}