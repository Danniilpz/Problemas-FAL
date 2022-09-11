// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Explicación del algoritmo utilizado

//El algoritmo utiliza una "ventana" que se inicializa en el primer bucle, y la va desplazando hasta el final en el segundo.
//Se van guardando el numero de 0s y se coge el numero maximo y mas lejano.

// Coste del algoritmo utilizado

// El coste es lineal, como máximo de metrosValla-longitudTela+1




// función que resuelve el problema
int resolver(std::vector<int> const& datos,int const& long_t) {
    int sol=-1,num0=0,max=0;
    for(int i=0;i<long_t;i++){
        if(datos[i]==0) num0++;   
    }
    if(num0>=max&&num0!=0){
        max=num0;
        sol=0;
    }
    for(int i=long_t;i<datos.size();i++){
        if(datos[i-long_t]==0) num0--;  
        if(datos[i]==0) num0++;
        
        if(num0>=max&&num0!=0){
            max=num0;
            sol=i-long_t+1;
        } 
         
    }    
    return sol;    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int long_v,long_t,num;
    std::cin>>long_v;
    if (long_v==0){
        return false;
    }
    else{
        std::cin>>long_t;
    }
    std::vector<int> v;
    for (int i=0;i<long_v;i++){
        std::cin>>num;
        v.push_back(num);
    }
    int sol = resolver(v,long_t);
    if(sol!=-1) std:: cout<<sol;    
    else std:: cout<<"No hace falta";    
    std:: cout<<"\n";    
    
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
