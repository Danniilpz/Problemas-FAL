// Daniel López Marqués 
// A41 
// A23 
#include <iostream>
#include <fstream>
#include <vector>
 // Explicación de la solucion del problema 
//El algoritmo utiliza la técnica Divide y Vencerás y divide el vector para buscar el valor en  función de el valor del medio, el del principio y el del final. 
// Coste de la solucion implementada. Se debe justificar indicando  
// la recurrencia y desplegandola  
//T(n)= c1 n=1 
// c2 n=2 
// T(n/2)+c3 n>2 
/* 
T(n/2)+c3 
T(n/2^2)+c3+c3 
T(n/2^3)+c3+c3+c3 
T(n/2^k)+kc3 
T(1)+log2(n)c3 que pertenece a O(log(n)) 
n/2^k=1 
n=2^k 
log2(n)=k 
*/
// Funcion recursiva que resuelve el problema 
bool resolver(std::vector < int >
  const & v, int ini, int fin, int x) {
  if (ini == fin) return (v[ini] == x) ? true : false;
  else if (ini + 1 == fin) return (v[ini] == x || v[fin] == x) ? true : false;
  else {
    int mitad = (ini + fin) / 2;
    if (v[mitad] > x && v[mitad] < v[ini]) return resolver(v, ini, mitad, x);
    else if (v[mitad] > x && v[ini] > x) return resolver(v, mitad + 1, fin, x);
    else if (v[mitad] > x && v[ini] < x) return resolver(v, ini, mitad, x);
    else if (v[mitad] < x && v[mitad] > v[fin]) return resolver(v, mitad + 1, fin, x);
    else if (v[mitad] < x && v[fin] < x) return resolver(v, ini, mitad, x);
    else if (v[mitad] < x && v[fin] > x) return resolver(v, mitad + 1, fin, x);
    else return true;
  }
}
// Funcion que trata cada caso de entrada 
bool resuelveCaso() {
  // Lectura de los datos 
  int numElem, x;
  std::cin >> numElem;
  if (numElem == -1) return false;
  std::cin >> x;
  std::vector < int > v(numElem);
  for (int & i: v) std::cin >> i;
  //LLamada a la función recursiva que resuelve el problema  
  bool sol=resolver(v, 0, v.size() - 1,x); 
  // Escribir los resultados 
  if (sol) std::cout << "SI\n";
  else std::cout << "NO\n";
  return true;
}
int main() {
  #ifndef DOMJUDGE
  std::ifstream in ("1.in");
  auto cinbuf = std::cin.rdbuf( in .rdbuf());
  #endif
  while (resuelveCaso())
  ;
  #ifndef DOMJUDGE // para dejar todo como estaba al principio  
  std::cin.rdbuf(cinbuf); 
  system("PAUSE");
  #endif
  return 0;
}