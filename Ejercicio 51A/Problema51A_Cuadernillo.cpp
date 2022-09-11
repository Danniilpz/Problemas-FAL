#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

// Datos de entrada
struct tDatos {
  int numJuguetes, numNinos;
  std::vector < std::vector < int > > satis;
};
// Solucion que se va construyendo
struct tSol {
  std::vector < int > sol;
  int sumaSatis;
};
// Parametros :
// datos de entrada
// k - etapa
// s - Solucion que se va construyendo
// asignados - Vector de dimension el numero de juguetes marca los juguetes ya asignados
// acum - vector con la satisfaccion acumulada desde cada ninno hasta el ultimo
// satisMejor - la satisfacion maxima
void resolver(tDatos
  const & datos, int k, tSol & s, std::vector < bool > & asignados, int & satisMejor, std::vector < int >
  const & acum) {
  for (int i = 0; i < datos.numJuguetes; ++i) {
    s.sol[k] = i;
    if (!asignados[i]) { // es Valida
      s.sumaSatis += datos.satis[k][i];
      asignados[i] = true; // marca
      if (k == s.sol.size() - 1) { // es solucion
        if (s.sumaSatis > satisMejor) satisMejor = s.sumaSatis; // solucion mejor
      } else { // No es solucion
        if (s.sumaSatis + acum[k + 1] > satisMejor) // Estimacion
          resolver(datos, k + 1, s, asignados, satisMejor, acum);
      }
      asignados[i] = false; // desmarca
      s.sumaSatis -= datos.satis[k][i];
    }
  }
}
bool resuelveCaso() {
  // Lectura de los datos de entrada
  tDatos datos;
  std::cin >> datos.numJuguetes;
  if (!std::cin) return false;
  std::cin >> datos.numNinos;
  // Lee la satisfaccion que les proporcionan los juguetes a los ninnos
  for (int i = 0; i < datos.numNinos; ++i) {
    std::vector < int > aux(datos.numJuguetes);
    for (int j = 0; j < datos.numJuguetes; ++j) std::cin >> aux[j];
    datos.satis.push_back(aux);
  }
  // Calcula el vector de maximos
  std::vector < int > acum(datos.numNinos);
  for (int i = 0; i < datos.numNinos; ++i) {
    int auxMax = datos.satis[i][0];
    for (int j = 1; j < datos.numJuguetes; ++j)
      if (auxMax < datos.satis[i][j]) auxMax = datos.satis[i][j];
    acum[i] = auxMax;
  }
  // Vector acumulados
  for (int i = (int) acum.size() - 1; i > 0; --i) {
    acum[i - 1] += acum[i];
  }
  // Obtiene una inicializacion posible para la solucion mejor
  int satisMejor = 0;
  for (int i = 0; i < datos.numNinos; ++i) {
    satisMejor += datos.satis[i][i];
  }
  // Prepara los datos de la funcion
  tSol s;
  s.sol.assign(datos.numNinos, 0);
  s.sumaSatis = 0;
  std::vector < bool > asignados(datos.numJuguetes, false);
  resolver(datos, 0, s, asignados, satisMejor, acum);
  std::cout << satisMejor << '\n';
  return true;
}
int main() {
  # ifndef DOMJUDGE
  std::ifstream in ("1.in");
  auto cinbuf = std::cin.rdbuf( in .rdbuf());
  # endif
  while (resuelveCaso()) {} // Resolvemos todos los casos
  # ifndef DOMJUDGE // para dejar todo como estaba al principio
  std::cin.rdbuf(cinbuf);
  system(" PAUSE ");
  # endif
  return 0;
}