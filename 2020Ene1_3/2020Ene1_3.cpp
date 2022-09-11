// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    std::vector<int> sol;
    int count;
    int suma;
};
struct tDatos{
    int inicial;
    int sumaMax;
};
bool esValida(int i,int k,tSol& s,tDatos& d){
    bool empiezaPorD=k>0||i==d.inicial;
    bool entretenido=k==0||s.sol[k-1]!=s.sol[k];
    return empiezaPorD&&entretenido;
}
bool esSolucion(tSol& s,tDatos& d){
    bool sumaNoExcede=s.suma<=d.sumaMax;
    return sumaNoExcede;
}
// función que resuelve el problema
tSol resolver(int m,int n,int k,tSol& s,tDatos& d) {
    for(int i=0;i<m;i++){
        s.sol[k]=i;
        s.suma+=i;
        if(esValida(i,k,s,d)){
            if(k==n-1){
                if(esSolucion(s,d)) s.count++;
            }
            else{
                resolver(m,n,k+1,s,d);
            }
        }        
        s.suma-=i;
    }  
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int digitos,inicial,sumaMax;
    std::cin>>digitos>>inicial>>sumaMax;
    if (digitos==-1)
        return false;
    tSol s;
    s.count=0;
    s.suma=0;
    s.sol.resize(digitos);
    tDatos d;
    d.inicial=inicial;
    d.sumaMax=sumaMax;
    resolver(10,digitos,0,s,d);
    std::cout<<s.count;
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
