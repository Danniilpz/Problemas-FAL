// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    bool players;
    int count;
    int round;
};

// función que resuelve el problema
tSol resolver(std::vector<std::string> const& v,int ini,int fin,int ronda) {
    if(ini+1==fin) {
        if(v[ini]=="NP"&&v[fin]=="NP") return{false,0,1};
        else if(v[ini]=="NP"||v[fin]=="NP") return {true,0,1};
        else return {true,1,1};
    }else{
        int mitad=(ini+fin)/2;
        tSol solIz=resolver(v,ini,mitad,ronda);
        tSol solDcha=resolver(v,mitad+1,fin,ronda);
        if(solIz.round<ronda){
            if(!solIz.players&&!solDcha.players) return {false,0,solIz.round+1};
            if(!solIz.players) return {true,solDcha.count,solIz.round+1};
            else if(!solDcha.players) return {true,solIz.count,solIz.round+1};
            else return {true,solIz.count+solDcha.count+1,solIz.round+1}; 
        }
        else{
            return {true,solIz.count+solDcha.count,solIz.round+1};
        }
        

    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,ronda;
    std::string dato;
    std::vector<std::string> v;
    std::cin>>len>>ronda;
    if (! std::cin)
        return false;
    for(int i=0;i<len;i++){
        std::cin>>dato;
        v.push_back(dato);
    }
    std::cout<<resolver(v,0,v.size()-1,ronda).count<<"\n";
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