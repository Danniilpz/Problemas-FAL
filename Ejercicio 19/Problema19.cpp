// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    int cont;
    std::vector<int> posiciones;
};

// función que resuelve el problema
tSol resolver(std::vector<int> const& v,int longitud) {
    int long_actual=1;int ini_actual=0;
    tSol sol;
    sol.cont=0;
    for(int i=1;i<v.size();i++){
        int diff=(v[i]-v[i-1]);
        if(diff==0||diff==-1||diff==1) long_actual++;
        else if(long_actual>=longitud){
            sol.cont++;
            sol.posiciones.push_back(ini_actual);
            long_actual=1;
            ini_actual=i;
        }
        else{
            long_actual=1;
            ini_actual=i;
        }
        if(i+1==v.size()&&long_actual>=longitud){
            sol.cont++;
            sol.posiciones.push_back(ini_actual);
        }
    }
    return sol;
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,s,num;
    std::vector<int> v;
    std::cin>>len>>s;
    if (len==0)
        return false;
    
    for(int i=0;i<len;i++){
        std::cin>>num;
        v.push_back(num);
    }
    tSol sol = resolver(v,s);
    
    std::cout<<sol.cont<<" ";
    for(int &n:sol.posiciones) std::cout<<n<<" ";
    std::cout<<"\n";
    
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
