// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    std::vector<int> sol;
    std::vector<std::pair<int, int>> blocks;
    int cont;
};

bool esValida(tSol s, int k, int i) {
    return ((i == 3 && s.sol[k - 1] != 3) || i != 3)
        && s.blocks[i - 1].first >= s.blocks[i - 1].second
        && ((i == 3 && s.blocks[0].second >= s.blocks[2].second) || i != 3);
}
bool solucionValida(tSol s) {
    return s.blocks[1].second > (s.blocks[0].second + s.blocks[2].second);
    
}

void escribirSolucion(std::vector<int> const& v) {
    for (int n : v) {
        if (n == 1) std::cout << "azul" << " ";
        else if (n == 2) std::cout << "rojo" << " ";
        else if (n == 3) std::cout << "verde" << " ";
    }
    std::cout << '\n';
} //  Calcula  de  forma  recursiva  las  variaciones  de los  elementos
void variaciones(int m, int n, int k, tSol& s) {
    for (int i = 1; i < 1 + m; ++i) {
        s.sol[k] = i;
        s.blocks[i - 1].second += 1;
        if (esValida(s, k, i)) {
            if (k == n - 1) { // Es  solucion
                if(solucionValida(s)) {
                    escribirSolucion(s.sol);
                    s.cont++;
                }
            }
            else { //  Sigue  completando  la  solucion
                variaciones(m, n, k + 1, s);
            }
        }
        s.blocks[i - 1].second -= 1;

    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num, m = 3;
    std::cin >> num;
    if (num == 0) return false;
    tSol s;
    s.sol.resize(num);
    s.blocks.resize(m);
    std::cin >> s.blocks[0].first >> s.blocks[1].first >> s.blocks[2].first;
    s.blocks[1].second = 1;
    s.sol[0] = 2; //base roja
    s.cont=0;
    int cont;
    if (num > 1) {
        variaciones(m, num, 1, s);
        if(s.cont==0) std::cout<<"SIN SOLUCION\n";
    }
    else escribirSolucion(s.sol);
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
