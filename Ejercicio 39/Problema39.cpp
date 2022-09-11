// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> v,int ini,int fin,int viajes) {
    if(ini==fin) return ini;
    else{
        int mitad=(ini+fin)/2; 
        int suma=0,viajes_actuales=0;
        for(int i=0;i<v.size();i++){
            suma+=v[i];
            if(suma==mitad) {
                viajes_actuales++;
                suma=0;
            }
            else if(suma>mitad){
                viajes_actuales++;
                suma=v[i];
                if(suma==mitad) {
                    viajes_actuales++;
                    suma=0;
                }
            }
        }
        if(suma>0) viajes_actuales++;

        if (viajes_actuales<=viajes){            
            return resolver(v,ini,mitad,viajes); 
        }
        else{
            int mitad=(ini+fin)/2; 
            return resolver(v,mitad+1,fin,viajes); 
        }
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int len,viajes,max=0,suma=0,num;
    std::cin>>len>>viajes;
    if (len==0)
        return false;
    std::vector<int> v;
    for(int i=0;i<len;i++){
        std::cin>>num;
        if(num>max) max=num;
        suma+=num;
        v.push_back(num);
    }
    std::cout<<resolver(v,max,suma,viajes)<<"\n";
    
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
