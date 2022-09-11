// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits.h>

using tmatriz=std::vector<std::vector<int>>;

struct tSol{
    std::vector<int> sol;
    std::vector<int> marcas;
    int sumaTiempos;
    int tiempoMejor;
};
bool esValida(tSol& s,int i){
    bool marcado=(s.marcas[i]>1)?true:false;
    return !marcado;
}
// función que resuelve el problema
void resolver(int m, int n, int k, tSol& s, tmatriz const& tiempos, std::vector<int>const& acum) {
    for(int i=0;i<m;i++){
        s.sol[k]=k;
        s.marcas[i]++;
        s.sumaTiempos+=tiempos[k][i];
        if(esValida(s,i)){
            if(k==n-1){
                if(s.sumaTiempos<s.tiempoMejor) {
                    s.tiempoMejor=s.sumaTiempos;
                }
            }
            else{
                if(s.sumaTiempos+acum[k+1]<s.tiempoMejor)
                    resolver(m,n,k+1,s,tiempos,acum);
            }
        }
        s.sumaTiempos-=tiempos[k][i];
        s.marcas[i]--;
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int empleados,trabajos;
    tmatriz tiempos;
    // leer los datos de la entrada
    std::cin>>empleados;
    trabajos=empleados;
    if (empleados==0) return false;
    for(int i=0;i<empleados;i++){
        std::vector<int> v(trabajos);
        for(int j=0;j<trabajos;j++)std::cin>>v[j];
        tiempos.push_back(v);
    }
    //calculo una inicializacion para la solucion mejor
    int tiempoMejor=INT_MAX;/*
    for(int i=0;i<tiempos.size();i++){
        tiempoMejor+=tiempos[i][i];
    }*/
    //calculo el vector de minimos
    std::vector<int> acum(empleados);
    for(int i=0;i<empleados;i++){
        acum[i]=tiempos[i][0];
        for(int j=1;j<trabajos;j++) if(tiempos[i][j]<acum[i]) acum[i]=tiempos[i][j];
    }
    //calculo el vector de acumulados
    for(int i=acum.size()-1;i>0;i--){
        acum[i-1]+=acum[i];
    }
    tSol s;
    s.sol.resize(empleados);
    s.sumaTiempos=0;
    s.tiempoMejor=tiempoMejor;
    s.marcas.resize(trabajos);
    resolver(trabajos,empleados,0,s,tiempos,acum);
    std::cout<<s.tiempoMejor;
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
