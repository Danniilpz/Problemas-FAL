// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v,int ini,int fin,int longMasAlto) {
  /*  if(ini==fin) return v[ini];
    else{
        int mitad=(ini+fin)/2;
        if(v[mitad]<v[ini]) return resolver(v,ini,mitad,longMasAlto);
        else resolver(v,mitad+1,fin,longMasAlto);
    }
    
*/



    if(ini==fin) return v[ini];
    else{
        int mitad=(ini+fin)/2;
        int solIz=resolver(v,ini,mitad,longMasAlto);
        int solDcha=resolver(v,mitad+1,fin,longMasAlto);
        return solIz>=solDcha?solIz:solDcha;
    }
    
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,longMasAlto;
    std::cin>>len>>longMasAlto;
    if (len==-1)
        return false;
    std::vector<int> v(len);
    for(int &n:v) std::cin>>n;

    std::cout<<resolver(v,0,v.size()-1,longMasAlto);
    std::cout<<"\n";
    // escribir sol
    
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
