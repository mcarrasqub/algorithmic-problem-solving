#include <iostream>
#include <vector>
#include <chrono>

using namespace std;

// ─────────────────────────────────────────
// VARIABLES GLOBALES
// ─────────────────────────────────────────
int n, k;                          // n = numero de vertices, k = numero de colores
vector<vector<int>> ady;           // matriz de adyacencia: ady[u][v] = 1 si hay arista
vector<int> color;                 // color[v] = color asignado al vertice v (0 = sin color)
long long total_soluciones = 0;    // contador de k-coloraciones validas
bool primera_guardada = false;     // bandera: ya guardamos la primera solucion?
vector<int> primera_solucion;      // aqui guardamos la primera solucion encontrada

// ─────────────────────────────────────────
// FUNCION: es_seguro(v, c)
// Pregunta: ¿puedo pintar el vertice v con el color c?
// Respuesta: SI, si ningun vecino de v ya tiene el color c
//            NO, si algun vecino de v ya tiene el color c
// ─────────────────────────────────────────
bool es_seguro(int v, int c) {
    for (int u = 0; u < n; u++) {          // revisa cada vertice u
        if (ady[v][u] == 1 && color[u] == c) {  // si u es vecino de v Y u ya tiene el color c
            return false;                  // NO es seguro, hay conflicto
        }
    }
    return true;                           // SI es seguro, ningun vecino tiene ese color
}

// ─────────────────────────────────────────
// FUNCION: bt(v)  <-- backtracking recursivo
// Intenta asignar un color al vertice v, luego sigue con v+1, v+2, etc.
// Si no puede asignar ningun color a v, retrocede (backtrack)
// ─────────────────────────────────────────
void bt(int v) {
    if (v == n) {
        // Llegamos al final: todos los vertices tienen color valido
        // Esto cuenta como una solucion valida
        total_soluciones++;

        // Si es la primera solucion, la guardamos para imprimirla luego
        if (!primera_guardada) {
            primera_solucion = color;     // copiamos el arreglo de colores
            primera_guardada = true;
        }
        return;                           // regresamos para seguir buscando mas soluciones
    }

    // Intentamos cada color del 1 al k para el vertice v
    for (int c = 1; c <= k; c++) {
        if (es_seguro(v, c)) {            // si el color c es valido para v...
            color[v] = c;                 // ...asignamos ese color a v
            bt(v + 1);                    // ...y continuamos con el siguiente vertice
            color[v] = 0;                 // BACKTRACK: quitamos el color para probar el siguiente
        }
        // Si es_seguro retorna false, simplemente probamos el siguiente color
        // Eso es la PODA: no seguimos por ese camino, ahorramos tiempo
    }
}

// ─────────────────────────────────────────
// FUNCION MAIN
// ─────────────────────────────────────────
int main() {
    // ── Leer entrada ──
    cout << "Ingrese n (vertices) y k (colores): ";
    cin >> n >> k;

    // Inicializar la matriz de adyacencia con ceros (sin aristas)
    ady.assign(n, vector<int>(n, 0));
    color.assign(n, 0);  // todos los vertices comienzan sin color (0)

    cout << "Ingrese la matriz de adyacencia (" << n << "x" << n << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> ady[i][j];

    // ── Medir tiempo del Backtracking ──
    auto inicio = chrono::high_resolution_clock::now();

    bt(0);  // empezamos desde el vertice 0

    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<double> tiempo_bt = fin - inicio;

    // ── Imprimir resultados ──
    cout << "\n=== BACKTRACKING ===\n";

    if (total_soluciones == 0) {
        cout << "No existe una " << k << "-coloracion valida\n";
    } else {
        cout << "Total de " << k << "-coloraciones: " << total_soluciones << "\n";
        cout << "Primera solucion:\n";
        for (int v = 0; v < n; v++) {
            cout << "color[" << v << "] = " << primera_solucion[v] << "\n";
        }
    }

    cout << "Tiempo Backtracking: " << tiempo_bt.count() << " segundos\n";

    return 0;
}