// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    bool existe;
    int pos1;
    int pos2;
};

// función que resuelve el problema
tSol resolver(std::vector<int> v1,std::vector<int> v2,int ini, int fin) {
    if(ini==fin){
        if(v1[ini]>v2[ini]) return {false,ini-1,ini}; 
        else if(v1[ini]<v2[ini]) return {false,ini,ini+1}; 
        else return {true,ini,0}; 
    }
    else{
        int mitad=(ini+fin)/2;
        if(v1[mitad]>v2[mitad]) return resolver(v1,v2,0,mitad); 
        else return {true,mitad,0};
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,num;
    std::cin>>len;
    if (len==0)
        return false;
    std::vector<int> v1,v2;
    for(int i=0;i<len;i++){
        std::cin>>num;
        v1.push_back(num);
    }
    for(int i=0;i<len;i++){
        std::cin>>num;
        v2.push_back(num);
    }
    tSol sol = resolver(v1,v2,0,len-1);
    if(sol.existe) std::cout<<"SI "<<sol.pos1;
    else std::cout<<"NO "<<sol.pos1<<" "<<sol.pos2;
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
