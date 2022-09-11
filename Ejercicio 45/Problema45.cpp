// Daniel López Marqués
// A41

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


//  Escribe  una  solucion
void escribirSolucion(std::vector < char >
  const & v) {
  for (char c: v) std::cout << c;
  std::cout << '\n';
} //  Calcula  de  forma  recursiva  las  variaciones  de los  elementos
void variaciones(int m, int n, int k, std::vector < char > & sol) {
  for (char i = 'a'; i < 'a' + m; ++i) {
    sol[k] = i;
    if (k == n - 1) { // Es  solucion
      escribirSolucion(sol);
    } else { //  Sigue  completando  la  solucion
      variaciones(m, n, k + 1, sol);
    }
  }
} //  Resuelve  un caso de prueba , leyendo  de la  entrada  la
//  configuracion , y escribiendo  la  respuesta
bool resuelveCaso() { //  Lectura  de los  datos  de  entrada
  int m, n;
  std::cin >> m >> n;
  if (!std::cin) return false; //  Generar  las  soluciones
  std::vector < char > sol(n);
  variaciones(m, n, 0, sol);
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