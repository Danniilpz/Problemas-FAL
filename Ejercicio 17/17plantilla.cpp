//*****************
// IMPORTANTE
//
// Daniel López Marqués
// A41
// A43
//
//***************************************************
#include <iostream>

#include <fstream>

#include <vector>

#include <algorithm>

#include <string>
 //*******************************
// Aqui explicacion de la función que resuelve el problema.
//
// El algoritmo recorre el arry de edificios desde el mas cercano a la costa hasta el mas alejado,
// comprobando con una variable si su piso supera la altura maxima hasta ese momento y
//comprobando si el edificio supera la altura anterior.
//
// Aqui la justificación del coste de la función que resuelve el problema
//
// El coste es lineal, del orden del tamaño del vector n, exactamente 3+4n
//
//*******************************
struct tDatos {
  std::string id;
  int altura;
  int piso;
};
// Aqui la función implementada por el alumno para resolver el problema
std::vector < std::string > resolver(std::vector < tDatos >
  const & v) {
  std::vector < std::string > sol;
  int alturamax = -1;
  for (int i = v.size() - 1; i >= 0; i--) {
    if (v[i].piso != -1 && v[i].piso > alturamax) {
      sol.push_back(v[i].id);
    }
    if (v[i].altura > alturamax) {
      alturamax = v[i].altura;
    }
  }
  return sol;
}

bool resuelveCaso() {
  int numEdificios;
  std::cin >> numEdificios;
  if (numEdificios == 0) return false;
  std::vector < tDatos > edificios(numEdificios);
  for (int i = 0; i < numEdificios; ++i) {
    std::cin >> edificios[i].id >> edificios[i].altura >> edificios[i].piso;
  }
  // LLamada a la funcion que resuelve el problema
  std::vector < std::string > sol = resolver(edificios);
  if (sol.size() > 0) {
    std::cout << sol.size() << "\n";
    for (std::string & p: sol) {
      std::cout << p << " ";
    }
  } else
    std::cout << "Ninguno"; {}
  std::cout << "\n";
  // Escribir el resultado

  return true;
}
int main() {
  // Para la entrada por fichero.
  #ifndef DOMJUDGE
  std::ifstream in ("1.in");
  auto cinbuf = std::cin.rdbuf( in .rdbuf());
  #endif
  while (resuelveCaso())
  ;
  // Para restablecer entrada.
  #ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system("PAUSE");
  #endif
  return 0;
}