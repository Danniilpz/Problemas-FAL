// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>


// función que resuelve el problema
bool entretenido(int num) {
    int division=num/10,digito=num%10;
    bool entretenido=true;
    while(division!=0){
        if(division%10==digito) entretenido=false;
        digito=division%10;
        division=division/10;
    }
    return entretenido;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin>>num;
    if (num==-1)
        return false;
    
    bool sol = entretenido(num);
    
    if(sol) std::cout<<"ENTRETENIDO"<<"\n";
    else std::cout<<"NO ENTRETENIDO"<<"\n";
    
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
