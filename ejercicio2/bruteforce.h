#ifndef BRUTEFORCE_H
#define BRUTEFORCE_H

#include <vector>

/**
 * Cuenta todas las k-coloraciones validas usando fuerza bruta.
 * Itera sobre todas las k^n combinaciones posibles de asignacion de colores.
 * 
 * @param adj Matriz de adyacencia (n x n)
 * @param k Numero de colores disponibles (colores de 1 a k)
 * @param n Numero de vertices (0 a n-1)
 * @return Numero total de k-coloraciones validas
 */
int bruteForceCounting(const std::vector<std::vector<int>>& adj, int k, int n);

/**
 * Ejecuta el conteo de k-coloraciones con fuerza bruta y mide el tiempo.
 * 
 * @param adj Matriz de adyacencia
 * @param k Numero de colores
 * @param n Numero de vertices
 * @param tiempoMs Referencia donde se guardara el tiempo en milisegundos
 * @return Numero de k-coloraciones validas encontradas
 */
int bruteForceMeasured(const std::vector<std::vector<int>>& adj, int k, int n, double& tiempoMs);

#endif
