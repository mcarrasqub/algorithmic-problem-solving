#ifndef BACKTRACKING_H
#define BACKTRACKING_H

#include <vector>

/**
 * Cuenta todas las k-coloraciones validas usando backtracking.
 * Utiliza poda para evitar explorar ramas innecesarias.
 * 
 * @param adj Matriz de adyacencia (n x n)
 * @param k Numero de colores disponibles (colores de 1 a k)
 * @param n Numero de vertices (0 a n-1)
 * @return Numero total de k-coloraciones validas
 */
int backtrackingCounting(const std::vector<std::vector<int>>& adj, int k, int n);

/**
 * Ejecuta el conteo de k-coloraciones con backtracking y mide el tiempo.
 * 
 * @param adj Matriz de adyacencia
 * @param k Numero de colores
 * @param n Numero de vertices
 * @param tiempoMs Referencia donde se guardara el tiempo en milisegundos
 * @return Numero de k-coloraciones validas encontradas
 */
int backtrackingMeasured(const std::vector<std::vector<int>>& adj, int k, int n, double& tiempoMs);

/**
 * Obtiene la primera k-coloracion valida encontrada por backtracking.
 * 
 * @return Vector con los colores de la primera solucion, o vector vacio si no existe
 */
std::vector<int> backtrackingPrimeraSolucion();

#endif
