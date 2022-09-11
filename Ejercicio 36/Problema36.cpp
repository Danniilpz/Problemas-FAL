// Daniel López Marqués
// A41

//O(n)= c1 n=1
//      c2 n=2
//      2O(n/2)+c3 n>2

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tmatriz = std :: vector <std :: vector <int >>;

// función que resuelve el problema
std::pair<bool,int> resolver(std::vector<int> const& v,int ini,int fin) {
    if(ini==fin) return {true,v[ini]};
    else if(ini+1==fin) {
        if(v[ini]<v[fin])return {true,v[ini]+v[fin]};
        else return {false,v[ini]+v[fin]}; 
    }else{
        int mitad=(ini+fin)/2;        
        std::pair<bool,int> solIz=resolver(v,ini,mitad);
        std::pair<bool,int> solDcha=resolver(v,mitad+1,fin);
        return {solIz.first&&solDcha.first&&(solIz.second<solDcha.second),solIz.second+solDcha.second};
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int x,y,num;
    tmatriz m;
    std::cin>>x>>y;
    if (! std::cin)
        return false;
    int j=0;
    for(int i=0;i<x;i++){
        std::vector<int> temp;
        for(int j=0;j<y;j++){
            std::cin>>num;
            temp.push_back(num);
        }
        m.push_back(temp);
    }
    bool sol=true;
    for(int i=0;i<x;i++){
        sol=sol&&resolver(m[i],0,m[i].size()-1).first;
    }
    if(sol) std::cout<<"SI"<<"\n";
    else std::cout<<"NO"<<"\n";
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