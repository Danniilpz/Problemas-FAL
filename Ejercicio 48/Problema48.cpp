// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol {
    std::vector<int> sol;
    std::vector<int> abrigos;
    int masUtilizado;
    int cont;
};
/*void escribirSolucion(std::vector<int> v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}*/
bool esValida(tSol& s, int k, int i, std::vector<int> const& est, std::vector<int> const& sop) {
    bool no_repetido = (k > 0) ? (s.sol[k - 1] != i) : true;
    return no_repetido
        && sop[i] >= est[k]
        && s.abrigos[s.masUtilizado] <= 2 + k / 3;
}
bool solucionValida(tSol& s) {
    return s.sol[0] != s.sol[s.sol.size() - 1];
}
// función que resuelve el problema
void variaciones(int m, int n, int k, tSol& s, std::vector<int> const& est, std::vector<int> const& sop) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        s.abrigos[i]++;
        if (s.abrigos[i] >= s.abrigos[s.masUtilizado]) s.masUtilizado = i;
        if (esValida(s, k, i, est, sop)) {
            if (k == n - 1) {
                if (solucionValida(s)) {
                    //escribirSolucion(s.sol);
                    s.cont++;
                }
            }
            else {
                variaciones(m, n, k + 1, s, est, sop);
            }
        }
        s.abrigos[i]--;
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int dias, abrigos, num;
    std::vector<int> estimacion, soporte;
    std::cin >> dias >> abrigos;
    if (dias == 0)
        return false;
    for (int i = 0; i < dias; i++) {
        std::cin >> num;
        estimacion.push_back(num);
    }
    for (int i = 0; i < abrigos; i++) {
        std::cin >> num;
        soporte.push_back(num);
    }
    tSol s;
    s.sol.resize(dias);
    s.abrigos.resize(abrigos);
    s.cont = 0;
    s.masUtilizado = 0;
    variaciones(abrigos, dias, 0, s, estimacion, soporte);
    if (s.cont == 0) std::cout << "Lo puedes comprar";
    else std::cout << s.cont;
    std::cout << '\n';
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
