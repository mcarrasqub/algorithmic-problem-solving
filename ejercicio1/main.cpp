#include <iostream>
#include <vector>
#include <algorithm> // Para std::next_permutation y std::sort
#include <chrono>    // Para medir el tiempo de ejecución

using namespace std;

int main() {
    int n;
    cout << "Ingrese la cantidad de elementos (n): ";
    cin >> n;

    vector<int> A(n);
    cout << "Ingrese los " << n << " elementos separados por espacio:\n";
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    // 1. OBLIGATORIO: Ordenar el arreglo ascendentemente.
    // Esto garantiza que empecemos desde la permutación más pequeña (ej: 1 3 4)
    sort(A.begin(), A.end());

    long long total_generadas = 0;
    long long total_validas = 0;

    // Empezamos a medir el tiempo aquí
    auto start = chrono::high_resolution_clock::now();

    // 2. Generación iterativa usando Fuerza Bruta
    do {
        total_generadas++;
        bool valida = true;

        // 3. Aplicar el filtro de restricción (Actividad 2)
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > 2 * A[i+1]) {
                valida = false;
                break; // Si falla una vez, ya no es válida, dejamos de revisar este arreglo
            }
        }

        // Si pasó la prueba, la imprimimos y sumamos
        if (valida) {
            for (int num : A) cout << num << " ";
            cout << "\n";
            total_validas++;
        }

    // std::next_permutation genera la siguiente permutación lexicográfica
    // Retorna false cuando vuelve al inicio (arreglo ordenado descendentemente)
    } while (next_permutation(A.begin(), A.end()));

    // Terminamos de medir el tiempo
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // 4. Reporte final (Actividad 3)
    cout << "--------------------------------\n";
    cout << "total_generadas = " << total_generadas << "\n";
    cout << "total_validas   = " << total_validas << "\n";
    cout << "Tiempo de ejecucion: " << duration.count() << " segundos\n";

    return 0;
}