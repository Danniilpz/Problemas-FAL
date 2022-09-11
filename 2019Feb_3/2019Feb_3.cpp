// Nombre del alumno .....
// Usuario del Juez ......


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

using tMatriz=std::vector<std::vector<int>>;

struct tSol{
    std::vector<int> sol;
    std::vector<int> solMejor;
    int satis;
    int satisMejor;    
    std::vector<int> juguetesPorNino;
};

struct tDatos{
    int minJuguetes;
    std::vector<int> edades;
    std::vector<int> edades_rec;
    tMatriz satisfacciones;
};

bool esValida(tDatos& d,tSol& s,int i, int k, int juguetes,int ninos){
    bool edadSuficiente=d.edades[i]>=d.edades_rec[k];
    bool demasiadosJuguetes=s.juguetesPorNino[i]>(d.minJuguetes+(juguetes%(ninos*2)));
    return edadSuficiente&&!demasiadosJuguetes;
}

// función que resuelve el problema
void resolver(int m,int n,int k,tDatos& d,tSol& s,std::vector<int> const& acum) {
    for(int i=0;i<m;i++){
        s.sol[k]=i;
        s.juguetesPorNino[i]++;
        s.satis+=d.satisfacciones[i][k];
        if(esValida(d,s,i,k,n,m)){
            if(k==n-1){
                if(s.satis>s.satisMejor){
                    s.satisMejor=s.satis;
                    s.solMejor=s.sol;
                }
            }
            else{
                if(s.satis+acum[k+1]>s.satisMejor)
                    resolver(m,n,k+1,d,s,acum);
            }
        }
        s.satis-=d.satisfacciones[i][k];
        s.juguetesPorNino[i]--;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int juguetes,ninos,minJuguetes;
    std::cin>>juguetes>>ninos>>minJuguetes;
    if (juguetes==0)
        return false;
    std::vector<int> edades(ninos),edades_rec(juguetes);
    for(int &n:edades_rec) std::cin>>n;
    for(int &n:edades) std::cin>>n;
    tMatriz satisfacciones;
    for(int i=0;i<ninos;i++){
        std::vector<int> aux(juguetes);
        for(int &n:aux) std::cin>>n;
        satisfacciones.push_back(aux);
    }
    tDatos d;
    d.minJuguetes=minJuguetes;
    d.edades=edades;
    d.edades_rec=edades_rec;
    d.satisfacciones=satisfacciones;
    tSol s;
    s.sol.resize(juguetes);
    s.solMejor.resize(juguetes);
    s.satis=0;
    s.satisMejor=0;

    //Inicializo la satisfaccion mejor y solucion mejor
    std::vector<int> marcas(ninos);
    int limiteJuguetes=d.minJuguetes+(juguetes%(ninos*2));
    for(int i=0;i<juguetes;i++){
        bool asignado=false;
        for(int j=0;j<ninos&&!asignado;j++){
            if(d.edades_rec[i]<=d.edades[j]&&marcas[j]<limiteJuguetes){
                s.satisMejor+=d.satisfacciones[j][i];
                marcas[j]++;
                asignado=true;
                s.solMejor[i]=j;
            }
        }
    }
    //Vector de maximos
     std::vector <int> acum(ninos);
    for (int i = 0; i < ninos; i++) {
        int auxMax = d.satisfacciones[i][0];
        for (int j=1; j<juguetes; j++)
            if (auxMax < d.satisfacciones[i][j]) auxMax = d.satisfacciones[i][j];
        acum[i] = auxMax;
    }
    // Vector acumulados
    for (int i = acum.size()-1; i>0; i--) {
        acum[i-1] += acum[i];
    }
    for(int &n:acum) std::cout<<n<<" ";
    std::cout<<"\n";

    s.juguetesPorNino.resize(ninos);
    resolver(ninos,juguetes,0,d,s,acum);
    std::cout<<s.satisMejor<<"\n";
    
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
