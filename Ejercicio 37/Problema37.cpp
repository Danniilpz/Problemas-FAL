// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>



// función que resuelve el problema
int resolver(std::vector<int> & v,int ini,int fin) {
    if(ini+1==fin) return 0;    
    else{
        int mitad=(ini+fin)/2,inv=0;        
        int solIz=resolver(v,ini,mitad);
        int solDcha=resolver(v,mitad,fin);
        int i=ini,j=mitad;
        while(i<mitad&&j<fin){
            if(v[i]>v[j]) {
                inv+=mitad-i;
                j++;
            } else i++;
        }
        std::inplace_merge (v. begin ()+ ini ,v. begin ()+ mitad ,v. begin ()+ fin);
        return inv+solIz+solDcha;
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,num;
    std::vector<int> v;
    std::cin>>len;
    if (! std::cin)
        return false;
    for(int i=0;i<len;i++){
        std::cin>>num;
        v.push_back(num);
    }
    std::cout<<resolver(v,0,v.size())<<"\n";
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