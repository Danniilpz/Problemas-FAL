// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolverNoFinal(int num1,int num2) {
    if(num1<10||num2<10){
        int digit=(((num1%10)+(num2%10))%10);
        return (num1-(num1%10))+(num2-(num2%10))+digit;
    }
    else{
        return resolverNoFinal(num1/10,num2/10)*10+(((num1%10)+(num2%10))%10);
    }
}

int resolverFinal(int num1,int num2,int nuevo, int pot) {
    if(num1<10||num2<10){
        int digit=(((num1%10)+(num2%10))%10);
        return ((num1-(num1%10))+(num2-(num2%10))+digit)*pot+nuevo;
    }
    else{
        return resolverFinal(num1/10,num2/10,(((num1%10)+(num2%10))%10)*pot+nuevo,pot*10);
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int num1,num2;
    std::cin>>num1>>num2; 
    std::cout<<resolverNoFinal(num1,num2)<<" ";
    std::cout<<resolverFinal(num1,num2,0,1);  
    std::cout<<"\n";
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