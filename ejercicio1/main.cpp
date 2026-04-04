#include <iostream>
#include <vector>
#include <algorithm> 
#include <chrono>   

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

    // Ordenar el arreglo ascendentemente.
    // Esto garantiza que empecemos desde la permutacion mas pequena
    sort(A.begin(), A.end());

    long long total_generadas = 0;
    long long total_validas = 0;

    // Empezamos a medir el tiempo aqui
    auto start = chrono::high_resolution_clock::now();

    // Generacion iterativa usando Fuerza Bruta
    do {
        total_generadas++;
        bool valida = true;

        // Aplicar el filtro de restriccion P[i] <= 2 * P[i+1]
        for (int i = 0; i < n - 1; i++) {
            if (A[i] > 2 * A[i+1]) {
                valida = false;
                break;
            }
        }

        // Si paso la prueba, la imprimimos y sumamos
        if (valida) {
            for (int i = 0; i < n; i++) {
                if (i > 0) cout << " ";
                cout << A[i];
            }
            cout << "\n";
            total_validas++;
        }

    // std::next_permutation genera la siguiente permutacion lexicografica
    // Retorna false cuando vuelve al inicio
    } while (next_permutation(A.begin(), A.end()));

    // Terminamos de medir el tiempo
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end - start;

    // Reporte final
    cout << "--------------------------------\n";
    cout << "total_generadas = " << total_generadas << "\n";
    cout << "total_validas   = " << total_validas << "\n";
    cout << "Tiempo de ejecucion: " << duration.count() << " segundos\n";

    return 0;
}