// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std::vector <std::vector <int >>;

struct tSol {
    std::vector<int> sol;
    std::vector<int> unidades;
    int count;
};
bool esValida(tSol& s, int k, int i, std::vector<std::string> tipos, tmatriz const& satisfacciones, int satisMin) {
    bool tipoRepetido, asignacionRepetida, satisfecho, suficientesUnidades;

    suficientesUnidades = s.unidades[i] >= 0;

    if (k % 2 == 0) tipoRepetido = false;
    else tipoRepetido = (tipos[s.sol[k - 1]] == tipos[s.sol[k]]);

    if (k % 2 == 0) asignacionRepetida = false;
    else asignacionRepetida = s.sol[k - 1] > s.sol[k];

    if (k % 2 == 0) satisfecho = true;

    else {
        //std::cout<<satisfacciones[k%2][s.sol[k]]<<" +"<< satisfacciones[(k-1) % 2][s.sol[k - 1]]<<"\n";
        int c = (k / 2) + 1;
        int suma = satisfacciones[(k / 2)][s.sol[k]] + satisfacciones[(k / 2)][s.sol[k - 1]];
        satisfecho = (suma) >= satisMin;
    }
    return !tipoRepetido && !asignacionRepetida && satisfecho && suficientesUnidades;
}
void escribirSolucion(std::vector<int> v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}
// función que resuelve el problema
void variaciones(int m, int n, int k, tSol& s, std::vector<std::string>const& tipos, tmatriz const& satisfacciones, int satisMin) {
    for (int i = 0; i < m; i++) {
        s.sol[k] = i;
        s.unidades[i]--;
        if (esValida(s, k, i, tipos, satisfacciones, satisMin)) {
            if (k == n - 1) {
                s.count++;
                escribirSolucion(s.sol);

            }
            else {
                variaciones(m, n, k + 1, s, tipos, satisfacciones, satisMin);
            }

        }
        s.unidades[i]++;
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int regalos, ninos, unidad, satisMin, satis;
    std::string str;
    std::vector<std::string> tipos;
    std::vector<int> unidades;
    std::cin >> regalos >> ninos >> satisMin;
    tmatriz satisfacciones;
    if (!std::cin) return false;
    for (int i = 0; i < regalos; i++) {
        std::cin >> unidad;
        unidades.push_back(unidad);
    }
    for (int i = 0; i < regalos; i++) {
        std::cin >> str;
        tipos.push_back(str);
    }
    for (int i = 0; i < ninos; i++) {
        std::vector<int> temp;
        for (int j = 0; j < regalos; j++) {
            std::cin >> satis;
            temp.push_back(satis);
        }
        satisfacciones.push_back(temp);
    }
    tSol s;
    s.sol.resize(2 * ninos);
    s.unidades = unidades;
    s.count = 0;
    variaciones(regalos, 2 * ninos, 0, s, tipos, satisfacciones, satisMin);
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