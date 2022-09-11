// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    bool cumple;
    int minimo;
    int maximo;
};

// función que resuelve el problema
tSol resolver(std::vector<int> const& v, int ini, int fin) {
    if (ini == fin)return {true,v[ini],v[ini]};
    else {
        int mitad = (ini + fin) / 2;
        tSol solIz = resolver(v, ini, mitad);
        tSol solDcha = resolver(v, mitad + 1, fin);
        bool ord = solIz.cumple&&solDcha.cumple&&solIz.maximo<=solDcha.maximo&&solIz.minimo<=solDcha.minimo;
        int minimo,maximo;
        if(solIz.minimo<=solDcha.minimo) minimo=solIz.minimo;
        else minimo=solDcha.minimo;
        if(solIz.maximo<=solDcha.maximo) maximo=solDcha.maximo;
        else maximo=solIz.maximo;
        //std::cout<<"Minimo:"<<minimo<<" Maximo: "<<maximo<<"\n";
        return {ord,minimo,maximo};
    }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    bool full=false;
    std::vector<int> v;
    while(!full){
        std::cin >> num;
        if(num==0){
            if(v.size()==0) return false;
            else full=true;
        }
        else v.push_back(num);
    }
    //for(int &n:v) std::cout<<n;
    //std::cout<<"\n";
    tSol sol = resolver(v, 0, v.size()-1);
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
