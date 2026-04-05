#include <vector>
#include <chrono>
#include <iostream>

using namespace std;

/**
 * verifica si una asignacion de colores es una k-coloracion valida.
 *
 * @param adj Matriz de adyacencia (adj[i][j] = 1 si hay arista entre i y j)
 * @param colores Vector de colores asignados a cada vertice
 * @param n Numero de vertices
 * @return true si la coloracion es valida, false en caso contrario
 */
bool esColoracionValida(const vector<vector<int>>& adj, const vector<int>& colores, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            //si hay arista entre i y j y comparten color, no es valida
            if (adj[i][j] == 1 && colores[i] == colores[j]) {
                return false;
            }
        }
    }
    return true;
}

/**
 * itera sobre todas las k^n combinaciones posibles de asignacion de colores.
 * 
 * @param adj Matriz de adyacencia (n x n)
 * @param k Numero de colores disponibles (colores de 1 a k)
 * @param n Numero de vertices (0 a n-1)
 * @return Numero total de k-coloraciones validas
 */
int bruteForceCounting(const vector<vector<int>>& adj, int k, int n) {
    int totalValidas = 0;
    
    //generar todas las k^n combinaciones posibles
    //usamos indices que van de 0 a k^n - 1
    long long totalCombinaciones = 1;
    for (int i = 0; i < n; i++) {
        totalCombinaciones *= k;
    }
    
    for (long long i = 0; i < totalCombinaciones; i++) {
        vector<int> colores(n);
        
        //convertir el numero i a una asignacion de colores en base k
        long long temp = i;
        for (int j = 0; j < n; j++) {
            //los colores van de 1 a k (no de 0 a k-1)
            colores[j] = (temp % k) + 1;
            temp /= k;
        }
        
        //verificar si esta asignacion es una coloracion valida
        if (esColoracionValida(adj, colores, n)) {
            totalValidas++;
        }
    }
    
    return totalValidas;
}

/**
 *ejecuta el conteo de k-coloraciones con fuerza bruta y mide el tiempo.
 * 
 * @param adj Matriz de adyacencia
 * @param k Numero de colores
 * @param n Numero de vertices
 * @param tiempoMs Referencia donde se guardara el tiempo en milisegundos
 * @return Numero de k-coloraciones validas encontradas
 */
int bruteForceMeasured(const vector<vector<int>>& adj, int k, int n, double& tiempoMs) {
    auto inicio = chrono::high_resolution_clock::now();
    
    int resultado = bruteForceCounting(adj, k, n);
    
    auto fin = chrono::high_resolution_clock::now();
    auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio);
    
    tiempoMs = duracion.count() / 1000.0;  // Convertir a milisegundos
    
    return resultado;
}
