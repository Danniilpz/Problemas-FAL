// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


struct tSol {
    std::vector<int> sol;
    int count;
};
bool esValida(tSol& s, int k, int i, std::vector<std::string> tipos) {
    bool tipoRepetido,asignacionRepetida;
    if (k%2==0) tipoRepetido = false;
    else tipoRepetido = (tipos[s.sol[k - 1]] == tipos[s.sol[k]]);
    if(k%2==0) asignacionRepetida= false;
    else asignacionRepetida= s.sol[k-1] > s.sol[k];
    return !tipoRepetido&&!asignacionRepetida;
}
void escribirSolucion(std::vector<int> v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}
// función que resuelve el problema
void variaciones(int m, int n, int k, tSol& s, std::vector<std::string> tipos) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        if (esValida(s, k, i, tipos)) {
            if (k == n - 1) {
                s.count++;
                escribirSolucion(s.sol);
                
            }
            else {
                variaciones(m, n, k + 1, s, tipos);
            }

        }
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int regalos, ninos;
    std::string str;
    std::vector<std::string> v;
    std::cin >> regalos >> ninos;
    if (!std::cin) return false;
    for (int i = 0; i < regalos; i++) {
        std::cin >> str;
        v.push_back(str);
    }
    tSol s;
    s.sol.resize(2*ninos);
    s.count = 0;
    variaciones(regalos, 2 * ninos, 0, s, v);
    if (s.count == 0) std::cout << "SIN SOLUCION\n";
    std::cout << "\n";
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