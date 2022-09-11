// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
int complementarioNoFinal(int num) {
    if(num<10) return (9-(num%10));
    else return complementarioNoFinal(num/10)*10+(9-num%10);
}
int complementarioFinal(int num,int nuevo, int pot) {
    if(num<10) return (9-(num%10))*pot+nuevo;
    else return complementarioFinal(num/10,(9-num%10)*pot+nuevo,pot*10);
}
std::pair<int,int> complementarioInversoNoFinal(int num) {
    if(num<10) return {(9-(num%10)),10};
    else {        
        std::pair<int,int> sol=complementarioInversoNoFinal(num/10);
        return {sol.first+(9-num%10)*sol.second,sol.second*10};
    }
}
int complementarioInversoFinal(int num,int nuevo) {
    if(num<10) return nuevo*10+(9-(num%10));
    else return complementarioInversoFinal(num/10,nuevo*10+(9-num%10));
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int a;
    std::cin>>a;
    std::cout<<complementarioFinal(a,0,1)<<" ";
    std::cout<<complementarioInversoNoFinal(a).first<<'\n';
    
    
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