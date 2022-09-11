// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    bool cumple;
    int pares;
};
// función que resuelve el problema
tSol resolver(std::vector<int> const& v, int ini, int fin) {
    if (ini == fin)return {true,0};
    else if (ini + 1 == fin){
        int pares=0;
        if(v[ini]%2==0) pares++;
        if(v[fin]%2==0) pares++;
        return {true,pares};
    }
    else {
        int mitad = (ini + fin) / 2;
        tSol solIz = resolver(v, ini, mitad);
        tSol solDcha = resolver(v, mitad + 1, fin);
        int diff=solIz.pares - solDcha.pares;
        if(diff<0) diff=0-diff;
        bool cau = (diff <= 2) ? 1 : 0;
        return {cau && solIz.cumple && solDcha.cumple,solIz.pares+solDcha.pares};
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len, num;
    std::vector<int> v;
    std::cin >> len;
    if (len == 0)
        return false;

    for (int i = 0; i < len; i++) {
        std::cin >> num;
        v.push_back(num);
    }
    tSol sol = resolver(v, 0, len - 1);
    if (sol.cumple) std::cout << "SI";
    else std::cout << "NO";
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
