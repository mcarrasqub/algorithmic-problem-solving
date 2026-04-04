#include <vector>
#include <chrono>

using namespace std;

// ─────────────────────────────────────────
// VARIABLES GLOBALES (PRIVADAS AL MODULO)
// ─────────────────────────────────────────
static int n_global, k_global;
static vector<vector<int>> ady_global;
static vector<int> color_global;
static vector<int> primera_solucion_global;
static bool primera_guardada_global = false;
static long long total_soluciones_global = 0;

// ─────────────────────────────────────────
// FUNCION: es_seguro(v, c)
// Pregunta: ¿puedo pintar el vertice v con el color c?
// Respuesta: SI, si ningun vecino de v ya tiene el color c
//            NO, si algun vecino de v ya tiene el color c
// ─────────────────────────────────────────
static bool es_seguro(int v, int c) {
    for (int u = 0; u < n_global; u++) {
        if (ady_global[v][u] == 1 && color_global[u] == c) {
            return false;
        }
    }
    return true;
}

// ─────────────────────────────────────────
// FUNCION: bt(v) <-- backtracking recursivo
// Intenta asignar un color al vertice v, luego sigue con v+1, v+2, etc.
// Si no puede asignar ningun color a v, retrocede (backtrack)
// ─────────────────────────────────────────
static void bt(int v) {
    if (v == n_global) {
        // Llegamos al final: todos los vertices tienen color valido
        total_soluciones_global++;
        
        // Guardar la primera solucion encontrada
        if (!primera_guardada_global) {
            primera_solucion_global = color_global;
            primera_guardada_global = true;
        }
        return;
    }

    // Intentamos cada color del 1 al k para el vertice v
    for (int c = 1; c <= k_global; c++) {
        if (es_seguro(v, c)) {
            color_global[v] = c;
            bt(v + 1);
            color_global[v] = 0;  // BACKTRACK
        }
    }
}

/**
 * Cuenta todas las k-coloraciones validas usando backtracking.
 * Utiliza poda para evitar explorar ramas innecesarias.
 * 
 * @param adj Matriz de adyacencia (n x n)
 * @param k Numero de colores disponibles (colores de 1 a k)
 * @param n Numero de vertices (0 a n-1)
 * @return Numero total de k-coloraciones validas
 */
int backtrackingCounting(const vector<vector<int>>& adj, int k, int n) {
    n_global = n;
    k_global = k;
    ady_global = adj;
    color_global.assign(n, 0);
    primera_solucion_global.clear();
    primera_guardada_global = false;
    total_soluciones_global = 0;

    bt(0);

    return total_soluciones_global;
}

/**
 * Ejecuta el conteo de k-coloraciones con backtracking y mide el tiempo.
 * 
 * @param adj Matriz de adyacencia
 * @param k Numero de colores
 * @param n Numero de vertices
 * @param tiempoMs Referencia donde se guardara el tiempo en milisegundos
 * @return Numero de k-coloraciones validas encontradas
 */
int backtrackingMeasured(const vector<vector<int>>& adj, int k, int n, double& tiempoMs) {
    auto inicio = chrono::high_resolution_clock::now();

    int resultado = backtrackingCounting(adj, k, n);

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> duracion = fin - inicio;
    tiempoMs = duracion.count();

    return resultado;
}

/**
 * Obtiene la primera k-coloracion valida encontrada por backtracking.
 * 
 * @return Vector con los colores de la primera solucion, o vector vacio si no existe
 */
std::vector<int> backtrackingPrimeraSolucion() {
    return primera_solucion_global;
}
