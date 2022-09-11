// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

struct tSol{
    std::vector<int> sol; //array para construir la solucion
    std::vector<int> luces; //marcas
    int suma; //suma total de luces
    int consumo; //consumo total
    int count; //contador de soluciones

};
bool esValida(tSol& s,int k,int i){
    bool distintoDosAnteriores=(k>1&&(s.sol[k-1]==i&&(s.sol[k-2]==i)))?false:true;
    bool menorQueSuma=((s.luces[i])-(s.suma-s.luces[i])>1)?false:true;
    return distintoDosAnteriores&&menorQueSuma;
}
bool solucionValida(tSol& s,int consumoMax){
    return s.consumo<=consumoMax;
}
void escribirSolucion(std::vector<int> v) {
    for (int n : v) std::cout << n << " ";
    std::cout << "\n";
}
// función que resuelve el problema
void variaciones(int m,int n,int k,tSol& s,std::vector<int> const& consumos,int consumoMax){
    for(int i=0;i<m;i++){
        s.sol[k]=i;
        s.luces[i]++;
        s.suma++;
        s.consumo+=consumos[i];
        if(esValida(s,k,i)){
            if(k==n-1){
                if(solucionValida(s,consumoMax)){
                    s.count++;
                    //escribirSolucion(s.sol);
                    
                }
            }
            else{
                variaciones(m,n,k+1,s,consumos,consumoMax);
            }
            
        }
        s.consumo-=consumos[i];
        s.suma--;
        s.luces[i]--;
    }    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    int len, luces, consumoMax, num;
    std::vector<int> consumos;
    std::cin>>len>>luces>>consumoMax;    
    if (len==0)
        return false;
    for(int i=0;i<luces;i++){
        std::cin>>num;
        consumos.push_back(num);
    }
    tSol s;
    s.sol.resize(len);
    s.luces.resize(luces);
    s.suma=0;
    s.consumo=0;
    s.count=0;
    variaciones(luces,len,0,s,consumos,consumoMax);
    std::cout << s.count;
    std::cout << '\n';
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
