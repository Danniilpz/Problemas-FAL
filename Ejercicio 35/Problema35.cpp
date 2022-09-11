// Daniel López Marqués
// A41

//O(n)= c1 n=1
//      O(n/2)+c3 n>1


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v,int ini,int fin,int valor) {
    if(ini==fin) return v[ini]==(ini+valor)?v[ini]:-1;
    else{
        int mitad=(ini+fin)/2;
        if(mitad+valor<v[mitad]) return resolver(v,ini,mitad,valor);
        else if(mitad+valor>v[mitad]) return resolver(v,mitad+1,fin,valor);
        else return v[mitad];
    } 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int len,valor,num;
    std::vector<int> v;
    std::cin>>len;
    std::cin>>valor;
    for(int i=0;i<len;i++){
        std::cin>>num;
        v.push_back(num);
    }
    int sol=resolver(v,0,v.size()-1,valor);
    if((sol!=-1)) std::cout<<sol<<"\n";
    else std::cout<<"NO"<<"\n";
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("1.in");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif 
    
    
    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}