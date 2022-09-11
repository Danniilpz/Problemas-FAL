// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
std::pair<int,int> interesante(int num,int act) {
    if(num<10) {
        if(act%(num%10)==0) std::cout<<act<<" "<<num%10<<" "<<"SI1f"<<"\n";
        else std::cout<<act<<" "<<num%10<<" "<<"NO1"<<"\n";
        if(0%(num%10)==0) std::cout<<0<<" "<<num%10<<" "<<"SI2f"<<"\n";
        else std::cout<<0<<" "<<num%10<<" "<<"NO2"<<"\n";
        return {act+num,num};
    }
    else{
        if(act%(num%10)==0) std::cout<<act<<" "<<num%10<<" "<<"SI1m"<<"\n";
        else std::cout<<act<<" "<<num%10<<" "<<"NO1"<<"\n";
        
        std::pair<int,int> sol=interesante(num/10,act+(num%10));
        if(sol.second%(num%10)==0) std::cout<<sol.second<<" "<<num%10<<" "<<"SI2m"<<"\n";
        else std::cout<<sol.second<<" "<<num%10<<" "<<"NO2"<<"\n";
        return {sol.first,sol.second+((num%10))};
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num;
    std::cout<<interesante(num,0).first<<" "<<interesante(num,0).second<<"\n";
    
    // escribir sol
    
    
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