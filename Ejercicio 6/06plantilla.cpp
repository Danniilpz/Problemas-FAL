// Daniel López Marqués
// A41

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <iomanip>

using lli = long long int;
// Calcula un vector con los valores acumulados
void resolver(std::vector<int> const& a, std::vector<lli>& v)
{
   long long int acumulados=0;
   for(int i=0;i<a.size();i++){
       v.push_back(a[i]+acumulados);
       acumulados+=a[i];
   }
}
// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // Lee las dos fechas entre las que tenemos datos
    int a1, a2;
    std::cin >> a1 >> a2;
    if (a1 == 0 && a2 == 0) return false;

    // Lee el resto de los datos y calcula el vector de acumulados

    int length=a2-a1+1,num;
    std::vector<int> a;
    std::vector<lli> v;
    for(int i=0;i<length;i++){
        std::cin>>num;
        a.push_back(num);
    }
    resolver(a,v);
    // Lectura de las preguntas
    int m;
    long long int sol; 
    std::cin >> m;
    for (int i = 0; i < m; ++i) {
        int f1, f2;
        std::cin >> f1 >> f2;
        sol=v[f2-a1];
        if(f1>a1) sol-=v[f1-a1-1];
        std::cout<<sol<<"\n";
        // Aqui codigo del estudiante
    }
    std::cout << "---\n";

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
    
    
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif

    return 0;
}



