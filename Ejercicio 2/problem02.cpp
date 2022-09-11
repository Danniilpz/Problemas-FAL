// Daniel López Marqués
// A41


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


using namespace std;
// función que resuelve el problema
bool resolver(vector<int> const& datos, int mid) {
    int max=datos[0];
    for(int i=0;i<datos.size();i++){
        if(i<=mid && datos[i]>max){
            max=datos[i];
        }
        else if(i>mid && datos[i]<=max){
            return false;
        }
    }
    return true;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int length,mid,num;
    vector<int> v;
    cin >> length;
    cin >> mid;
    //cout << length << " " << mid << "\n";
    for(int i = 0; i < length; i++){
        cin >> num;
        v.push_back(num);
    }

    bool sol = resolver(v,mid);
    if(sol) cout << "SI" << "\n";
    else cout << "NO" << "\n";
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     ifstream in("datos.txt");
     auto cinbuf = cin.rdbuf(in.rdbuf()); //save old buf and redirect cin to casos.txt
     #endif 
    
    
    int numCasos;
    cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();

    
    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     cin.rdbuf(cinbuf);
     system("PAUSE");
     #endif
    
    return 0;
}