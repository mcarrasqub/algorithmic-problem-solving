# Trabajo Practico: Fuerza Bruta y Backtracking en C++

Este proyecto implementa dos ejercicios de algoritmos: Permutaciones con Restricciones (Fuerza Bruta) y Coloracion de Grafos (Backtracking).

## Estructura del Proyecto

```
.
├── INFORME.pdf                    # Informe completo con teoria, pseudocodigo y analisis
├── README.md                     # Este archivo
├── ejercicio1/
│   └── main.cpp                  # Programa del Ejercicio 1
└── ejercicio2/
    ├── main.cpp                  # Programa del Ejercicio 2
    ├── backtracking.cpp         # Implementacion de Backtracking
    ├── backtracking.h           # Header de Backtracking
    ├── bruteforce.cpp           # Implementacion de Fuerza Bruta
    └── bruteforce.h             # Header de Fuerza Bruta
```

## Requisitos

- Compilador C++: g++ (recomendado g++ 7.0 o superior)
- Sistema operativo: Windows, Linux o macOS
- Standard: C++17 o superior

### Instalacion de g++

#### En Windows
1. Descargar MinGW-w64: https://www.mingw-w64.org/
2. Seguir instrucciones de instalacion y agregar a PATH
3. Verificar: `g++ --version`

#### En Linux
```bash
sudo apt-get install build-essential
```

#### En macOS
```bash
brew install gcc
```

## Compilación

Ejecutar los comandos desde la carpeta raiz del proyecto.

Si estas dentro de `ejercicio1/` o `ejercicio2/`, usa las rutas locales indicadas en la seccion "Alternativa si ya estas dentro de la carpeta".

### Ejercicio 1: Permutaciones con Restricciones

**Windows (PowerShell o CMD)**
```powershell
g++ -O2 -std=c++17 -o ejercicio1/solucion.exe ejercicio1/main.cpp
```

**Linux/macOS**
```bash
g++ -O2 -std=c++17 -o ejercicio1/solucion ejercicio1/main.cpp
```

**Alternativa si ya estas dentro de `ejercicio1/`**

```powershell
g++ -O2 -std=c++17 -o solucion.exe main.cpp
```

### Ejercicio 2: Coloracion de Grafos

**Windows (PowerShell o CMD)**
```powershell
g++ -O2 -std=c++17 -o ejercicio2/solucion2.exe ejercicio2/main.cpp ejercicio2/backtracking.cpp ejercicio2/bruteforce.cpp
```

**Linux/macOS**
```bash
g++ -O2 -std=c++17 -o ejercicio2/solucion2 ejercicio2/main.cpp ejercicio2/backtracking.cpp ejercicio2/bruteforce.cpp
```

**Alternativa si ya estas dentro de `ejercicio2/`**

```powershell
g++ -O2 -std=c++17 -o solucion2.exe main.cpp backtracking.cpp bruteforce.cpp
```

**Si estas dentro de `ejercicio1/` y quieres compilar Ejercicio 2 sin cambiar de carpeta**

```powershell
g++ -O2 -std=c++17 -o ../ejercicio2/solucion2.exe ../ejercicio2/main.cpp ../ejercicio2/backtracking.cpp ../ejercicio2/bruteforce.cpp
```

## Ejecución

### Ejercicio 1

**Windows (PowerShell)**
```powershell
.\ejercicio1\solucion.exe
```

**Windows (CMD)**
```cmd
ejercicio1\solucion.exe
```

**Linux/macOS**
```bash
./ejercicio1/solucion
```

**Si ya estas dentro de `ejercicio1/`**
```powershell
.\solucion.exe
```

**IMPORTANTE: Si tu entorno generó `gsolucion.exe` es mejor usarlo en vez de solucion.exe**
```powershell
.\gsolucion.exe
```

**Entrada interactiva:**
```
Ingrese la cantidad de elementos (n): 3
Ingrese los 3 elementos separados por espacio:
1 3 4
```

**Salida esperada:**
```
1 3 4
1 4 3
--------------------------------
total_generadas = 6
total_validas   = 2
Tiempo de ejecucion: 0.00x segundos
```

### Ejercicio 2

**Windows (PowerShell)**
```powershell
.\ejercicio2\solucion2.exe
```

**Windows (CMD)**
```cmd
ejercicio2\solucion2.exe
```

**Linux/macOS**
```bash
./ejercicio2/solucion2
```

**Si ya estas dentro de `ejercicio2/`**
```powershell
.\solucion2.exe
```

**IMPORTANTE: Si tu entorno generó `gsolucion2.exe` es mejor usarlo en vez de solucion.exe**
```powershell
.\gsolucion2.exe
```

**Salida esperada:**
```
================== COLORACION DE GRAFOS ==================

GRAFO 1: Ciclo C4 (n=4, k=3)
Aristas: 0-1, 1-2, 2-3, 3-0

    0 ---- 1
    |      |
    |      |
    3 ---- 2

Total de 3-coloraciones (Fuerza Bruta): 18
Total de 3-coloraciones (Backtracking): 18
Fuerza Bruta confirma: 18

GRAFO 2: Completo K4 (n=4, k=4)
Aristas: todos los pares de vertices

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

Total de 4-coloraciones (Fuerza Bruta): 24
Total de 4-coloraciones (Backtracking): 24
Fuerza Bruta confirma: 24

================== TABLA COMPARATIVA DE TIEMPOS ==================

Algoritmo            Grafo 1 C4 (s)        Grafo 2 K4 (s)        Coloraciones
────────────────────────────────────────────────────────────────────────────
Fuerza Bruta         0.xxxxxx              0.xxxxxx              18 / 24
Backtracking         0.xxxxxx              0.xxxxxx              18 / 24

VALIDACION: OK - Ambos algoritmos dan el mismo resultado
```

## Notas Importantes

1. **Sin acentos en salidas:** El programa genera salida sin caracteres acentuados, acorde a especificaciones.

2. **Rendimiento:** El Ejercicio 1 puede tardar considerablemente con n >= 12. Se recomienda probar con n <= 10.

3. **Validacion:** El Ejercicio 2 compara automaticamente resultados entre Backtracking y Fuerza Bruta.

4. **Parametros personalizados:** Para probar otros grafos en Ejercicio 2, modificar las matrices de adyacencia en main.cpp.

## Información Adicional

- Analisis teorico completo: Ver INFORME.pdf
- Pseudocodigo detallado: Seccion 1.2 y 2.2 del INFORME
- Analisis de complejidad: Apendice del INFORME
