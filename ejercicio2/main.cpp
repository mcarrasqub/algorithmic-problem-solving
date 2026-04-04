#include <iostream>
#include <vector>
#include <iomanip>
#include "bruteforce.h"
#include "backtracking.h"

using namespace std;

void dibujarGrafo(const string& tipo) {
    if (tipo == "C4") {
        cout << R"(
        0 ---- 1
        |      |
        |      |
        3 ---- 2
        )" << endl;
    } else if (tipo == "K4") {
        cout << R"(
        0-----------1
        |\         /|
        | \       / |
        |  \     /  |
        |   \   /   |
        |    \ /    |
        |     X     |
        |    / \    |
        |   /   \   |
        3-----------2
        )" << endl;
    }
}

void imprimirPrimeraSolucion(const std::vector<int>& colores, int n) {
    for (int v = 0; v < n; v++) {
        cout << "color[" << v << "]=" << colores[v];
        if (v < n - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    // Grafo 1: Ciclo C4 (n=4, aristas: 0-1, 1-2, 2-3, 3-0), k=3
    vector<vector<int>> grafo1 = {
        {0, 1, 0, 1},
        {1, 0, 1, 0},
        {0, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int k1 = 3;
    int n1 = 4;
    
    // Grafo 2: Completo K4 (n=4, todos conectados), k=4
    vector<vector<int>> grafo2 = {
        {0, 1, 1, 1},
        {1, 0, 1, 1},
        {1, 1, 0, 1},
        {1, 1, 1, 0}
    };
    int k2 = 4;
    int n2 = 4;
    
    cout << "================== COLORACION DE GRAFOS ==================" << endl;
    cout << endl;
    
    // Prueba Grafo 1: C4
    cout << "GRAFO 1: Ciclo C4 (n=4, k=3)" << endl;
    cout << "Aristas: 0-1, 1-2, 2-3, 3-0" << endl;
    dibujarGrafo("C4");
    cout << endl;
    
    double tiempoBF1, tiempoBT1;
    int resultadoBF1 = bruteForceMeasured(grafo1, k1, n1, tiempoBF1);
    int resultadoBT1 = backtrackingMeasured(grafo1, k1, n1, tiempoBT1);
    
    cout << "Total de 3-coloraciones (Fuerza Bruta): " << resultadoBF1 << endl;
    cout << "Total de 3-coloraciones (Backtracking): " << resultadoBT1 << endl;
    cout << "Fuerza Bruta confirma: " << resultadoBF1 << endl;
    
    // Imprimir primera solucion de backtracking
    if (resultadoBT1 > 0) {
        cout << "Primera solucion (Backtracking):" << endl;
        vector<int> primeraSol1 = backtrackingPrimeraSolucion();
        imprimirPrimeraSolucion(primeraSol1, n1);
    } else {
        cout << "No existe una 3-coloracion valida" << endl;
    }
    cout << endl;
    
    // Prueba Grafo 2: K4
    cout << "GRAFO 2: Completo K4 (n=4, k=4)" << endl;
    cout << "Aristas: todos los pares de vertices" << endl;
    dibujarGrafo("K4");
    cout << endl;
    
    double tiempoBF2, tiempoBT2;
    int resultadoBF2 = bruteForceMeasured(grafo2, k2, n2, tiempoBF2);
    int resultadoBT2 = backtrackingMeasured(grafo2, k2, n2, tiempoBT2);
    
    cout << "Total de 4-coloraciones (Fuerza Bruta): " << resultadoBF2 << endl;
    cout << "Total de 4-coloraciones (Backtracking): " << resultadoBT2 << endl;
    cout << "Fuerza Bruta confirma: " << resultadoBF2 << endl;
    
    // Imprimir primera solucion de backtracking
    if (resultadoBT2 > 0) {
        cout << "Primera solucion (Backtracking):" << endl;
        vector<int> primeraSol2 = backtrackingPrimeraSolucion();
        imprimirPrimeraSolucion(primeraSol2, n2);
    } else {
        cout << "No existe una 4-coloracion valida" << endl;
    }
    cout << endl;
    
    // Tabla comparativa de tiempos
    cout << "================== TABLA COMPARATIVA DE TIEMPOS ==================" << endl;
    cout << endl;
    cout << setw(20) << left << "Algoritmo"
         << setw(25) << left << "Grafo 1 C4 (s)"
         << setw(25) << left << "Grafo 2 K4 (s)"
         << setw(20) << left << "Coloraciones"
         << endl;
    cout << string(90, '-') << endl;
    
    cout << setw(20) << left << "Fuerza Bruta"
         << setw(25) << left << fixed << setprecision(6) << tiempoBF1
         << setw(25) << left << fixed << setprecision(6) << tiempoBF2
         << setw(20) << left << resultadoBF1 << " / " << resultadoBF2
         << endl;
    
    cout << setw(20) << left << "Backtracking"
         << setw(25) << left << fixed << setprecision(6) << tiempoBT1
         << setw(25) << left << fixed << setprecision(6) << tiempoBT2
         << setw(20) << left << resultadoBT1 << " / " << resultadoBT2
         << endl;
    
    cout << endl;
    
    // Validacion
    if (resultadoBF1 == resultadoBT1 && resultadoBF2 == resultadoBT2) {
        cout << "VALIDACION: OK - Ambos algoritmos dan el mismo resultado" << endl;
    } else {
        cout << "VALIDACION: FALLO - Los algoritmos dan resultados diferentes" << endl;
    }
    
    cout << endl;
    
    return 0;
}
