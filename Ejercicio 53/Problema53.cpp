// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz=std::vector<std::vector<int>>;

struct tSol{
    std::vector<int> sol;
    std::vector<int> marcas;
    std::vector<int> tareasPorAlumno;
    int sumaSatis;
    int satisMejor;
};
bool esValida(tSol& s,int i,int k,int maxTareas){
    bool repetido;
    if(k%2!=0) repetido=s.sol[k-1]==s.sol[k];
    else repetido=false;
    bool limiteTareas=s.marcas[i]<=maxTareas;
    return !repetido&&limiteTareas;
}
void escribirSolucion(std::vector<int> v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}
// función que resuelve el problema
void resolver(int m, int n, int k, tSol& s, int maxTareas, tmatriz const& satis) {
    for(int i=0;i<m;i++){
        s.sol[k]=i;
        s.marcas[i]++;
        s.sumaSatis+=satis[i][k/2];
        if(esValida(s,i,k,maxTareas)){
            if(k==n-1){
                if(s.sumaSatis>s.satisMejor) {
                    s.satisMejor=s.sumaSatis;
                    //escribirSolucion(s.sol);
                }
            }
            else{
                resolver(m,n,k+1,s,maxTareas,satis);
                    
            }
        }
        s.sumaSatis-=satis[i][k/2];
        s.marcas[i]--;
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int tareas,alumnos,maxTareas;
    tmatriz satis;
    // leer los datos de la entrada
    std::cin>>tareas>>alumnos>>maxTareas;
    if (tareas==0) return false;
    for(int i=0;i<alumnos;i++){
        std::vector<int> v(tareas);
        for(int j=0;j<tareas;j++)std::cin>>v[j];
        satis.push_back(v);
    }
    //calculo una inicializacion para la solucion mejor
    int satisMejor=0;

    tSol s;
    s.sol.resize(tareas*2);
    s.sumaSatis=0;
    s.satisMejor=satisMejor;
    s.marcas.resize(alumnos);    
    resolver(alumnos,2*tareas,0,s,maxTareas,satis);
    std::cout<<s.satisMejor;
    std::cout<<"\n";
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
