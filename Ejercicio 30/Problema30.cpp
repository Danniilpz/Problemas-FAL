// 
// Daniel López Marqués 
// A41 
// 
#include <iostream>

#include <fstream>

int recursionNoFinal(int numero) { 
// Aqui el código del alumno 
  if (numero < 10) return numero*10+numero;
  else return recursionNoFinal(numero / 10)*100+(numero%10*10+numero%10);
}
// Función recursiva final 
int recursionFinal(int numero, int actual,int pot) { 
  // Aqui el código del alumno 
  if (numero < 10) return actual+(numero*10+numero)*pot;
  else return recursionFinal(numero/10,actual+(numero%10*10+numero%10)*pot,pot*100);
}
void resuelveCaso() {
  int numero;
  std::cin >> numero;
  int s1 = recursionNoFinal(numero); 
  int s2=recursionFinal(numero,0,1); 
  std::cout << s1 << ' ' << s2 << '\n'; 
}
int main() {
  #ifndef DOMJUDGE
  std::ifstream in ("1.in");
  auto cinbuf = std::cin.rdbuf( in .rdbuf());
  #endif
  int numCasos;
  std::cin >> numCasos;
  for (int i = 0; i < numCasos; ++i) {
    resuelveCaso();
  }
  #ifndef DOMJUDGE // para dejar todo como estaba al principio  
  std::cin.rdbuf(cinbuf); 
  system("PAUSE");
  #endif
  return 0;
}