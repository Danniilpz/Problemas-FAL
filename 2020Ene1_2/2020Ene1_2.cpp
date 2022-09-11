// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>

using ulli=unsigned long long int;

struct tSol{
    ulli suma;
    int digito;
};
// función que resuelve el problema
tSol resolver(ulli num) {
    if(num<10) return {num+1,(int)num%10};
    else{
        tSol anterior=resolver(num/10);
        int actual_digito=num%10;
        int correccion=(actual_digito>=anterior.digito)?0:1;
        return {(anterior.suma*9+1)-(9-actual_digito)+correccion,actual_digito};
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    ulli num;
    std::cin>>num;
    if (num==-1)
        return false;
    
    std::cout<<resolver(num).suma;
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
