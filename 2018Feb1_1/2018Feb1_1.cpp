// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    int ini;
    int len;
};
// función que resuelve el problema
tSol resolver(std::vector<int>const& v) {
    int secMax=1,secActual=1,iniMax=0,iniActual=0;
    for(int i=1;i<v.size();i++){
        if(v[i]>v[i-1]&&v[i]-v[i-1]==1){
            secActual++;
            if(secActual>secMax){
                secMax=secActual;
                iniMax=iniActual;
            }
        }
        else{
            secActual=1;
            iniActual=i;
        }
    }
    return {iniMax,secMax};
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len;
    std::cin>>len;
    if (len==0)
        return false;
    std::vector<int> v(len);
    for(int &n:v) std::cin>>n;
    
    tSol sol = resolver(v);
    
    std::cout<<sol.ini<<" "<<sol.len<<"\n";
    
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
