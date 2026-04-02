# Ejercicio 2: Coloracion de Grafos con k Colores

## Descripcion del Problema

El problema de coloraci√ ́on de grafos consiste en asignar k colores a los v√©rtices de un grafo tal que ningun par de vertices adyacentes comparta el mismo color. Este ejercicio implementa dos soluciones:

1. **Fuerza Bruta**: Itera todas las k^n combinaciones posibles y verifica cada una.
2. **Backtracking**: Utiliza poda para explorar solo ramas validas.

### Grafos de Prueba

- **Grafo 1**: Ciclo C4 (n=4 vertices, aristas: 0-1, 1-2, 2-3, 3-0), k=3 colores
- **Grafo 2**: Grafo Completo K4 (n=4, todos los vertices conectados), k=4 colores

## Estructura del Proyecto

```
ejercicio2/
├── main.cpp            - Integracion final de ambos algoritmos
├── bruteforce.cpp      - Implementacion de Fuerza Bruta (Persona B)
├── bruteforce.h        - Header para Fuerza Bruta
├── backtracking.cpp    - Implementacion de Backtracking (Persona A)
├── backtracking.h      - Header para Backtracking
└── README.md           - Este archivo
```

## Instalacion de g++ (Requisito Previo)

### En Windows

**Opcion 1: MinGW-w64**
1. Descargue desde: https://www.mingw-w64.org/
2. Ejecute el instalador y seleccione:
   - Version: latest
   - Architecture: x86_64 (64-bit)
   - Threads: posix
   - Exception handling: dwarf2
3. Agregue la carpeta `bin` al PATH (ej: `C:\mingw-w64\bin`)

**Opcion 2: Chocolatey (si esta instalado)**
```powershell
choco install mingw
```

**Opcion 3: MSYS2**
1. Descargue desde: https://www.msys2.org/
2. Ejecute: `pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-gdb`

### En Linux
```bash
# Ubuntu/Debian
sudo apt-get install build-essential

# Fedora/RHEL
sudo dnf install gcc-c++

# Arch
sudo pacman -S base-devel
```

### En macOS
```bash
brew install gcc
```

## Instrucciones de Compilacion

### Metodo 1: Script automatico

**En Windows:**
```bash
compile.bat
```

**En Linux/Mac:**
```bash
chmod +x compile.sh
./compile.sh
```

### Metodo 2: Compilacion manual

```bash
g++ -O2 -std=gnu++17 -o solucion main.cpp bruteforce.cpp backtracking.cpp
```

## Uso del Programa

```bash
./main.exe
```

**Salida esperada para Grafo 1 (C4, k=3):**

```
================== COLORACION DE GRAFOS ==================

GRAFO 1: Ciclo C4 (n=4, k=3)
Aristas: 0-1, 1-2, 2-3, 3-0

Total de 3-coloraciones (Fuerza Bruta): 18
Total de 3-coloraciones (Backtracking): 18
Fuerza Bruta confirma: 18

GRAFO 2: Completo K4 (n=4, k=4)
Aristas: todos los pares de vertices

Total de 4-coloraciones (Fuerza Bruta): 24
Total de 4-coloraciones (Backtracking): 24
Fuerza Bruta confirma: 24

================== TABLA COMPARATIVA DE TIEMPOS ==================

Algoritmo            Grafo 1 C4 (ms)       Grafo 2 K4 (ms)       Coloraciones
-----------------------------------------------------------------------------------
Fuerza Bruta         0.XX                  0.XX                  18 / 24
Backtracking         0.XX                  0.XX                  18 / 24

VALIDACION: OK - Ambos algoritmos dan el mismo resultado
```

## Funciones Implementadas  (Fuerza Bruta)

### esColoracionValida()
Verifica si una asignacion de colores es valida (ningun par de vertices adyacentes comparte color).

**Parametros**:
- `adj`: Matriz de adyacencia (n x n)
- `colores`: Vector de colores asignados (de 1 a k)
- `n`: Numero de vertices

**Retorna**: true si es valida, false en caso contrario

### bruteForceCounting()
Itera todas las k^n combinaciones posibles de colores y cuenta las validas.

**Parametros**:
- `adj`: Matriz de adyacencia
- `k`: Numero de colores disponibles
- `n`: Numero de vertices

**Retorna**: Numero total de coloraciones validas

**Complejidad Temporal**: O(k^n * n^2) - O(k^n) para iterar combinaciones, O(n^2) para verificar cada una

### bruteForceMeasured()
Ejecuta bruteForceCounting() y mide el tiempo de ejecucion usando chrono.

**Parametros**:
- `adj`: Matriz de adyacencia
- `k`: Numero de colores
- `n`: Numero de vertices
- `tiempoMs`: Referencia para guardar tiempo en milisegundos

**Retorna**: Numero de coloraciones validas

## Características de la Implementacion

✓ Uso de matriz de adyacencia para representar el grafo
✓ Vertices numerados de 0 a n-1
✓ Colores numerados de 1 a k (no de 0 a k-1)
✓ Medicion de tiempo con chrono de STL
✓ Sin acentos en las salidas del programa
✓ Compilacion con -O2 para optimizaciones
✓ Estandar C++17

## Casos de Prueba

### Caso 1: Ciclo C4, k=3

- **Grafo**: 4 vertices en ciclo (0→1→2→3→0)
- **Colores**: 3
- **Coloraciones validas esperadas**: 18
- **Calculo**: k(k-1)^n para ciclos = 3 * 2^4 = 3 * 16 = 48... Revisar: 
  - En realidad para C4 con k=3: se puede calcular como (k-1)^n + (-1)^n(k-1)
  - = 2^4 + 2 = 16 + 2 = 18 ✓

### Caso 2: Grafo Completo K4, k=4

- **Grafo**: 4 vertices completamente conectados
- **Colores**: 4
- **Coloraciones validas esperadas**: 24
- **Calculo**: k! / (k-n)! = 4! / 0! = 24 (numero de permutaciones)
  - 4 * 3 * 2 * 1 = 24 ✓

## Validacion de Resultados

El programa valida automaticamente que Fuerza Bruta y Backtracking den el mismo resultado.
Si los resultados son diferentes, se mostrara "VALIDACION: FALLO".

## Notas sobre el Algoritmo de Fuerza Bruta

La implementacion convierte numeros de 0 a k^n-1 en asignaciones de colores usando
aritmetica en base k. Esto asegura que se exploren todas las combinaciones.

Ejemplo para k=3, n=2:
- 0 → (0+1, 0+1) = (1, 1)
- 1 → (1+1, 0+1) = (2, 1)
- 2 → (2+1, 0+1) = (3, 1)
- 3 → (0+1, 1+1) = (1, 2)
- ... y asi sucesivamente hasta 8 (3^2 - 1)

## Mejoras Futuras

- [ ] Agregar opciones de entrada interactiva (n, k, adyacencia)
- [ ] Generar grafos aleatorios
- [ ] Aumentar tamanio de n para observar diferencias de rendimiento
- [ ] Visualizar coloracion en formato GraphViz
- [ ] Paralelizacion con OpenMP para Fuerza Bruta

## Referencias

- Undirected Graph Coloring Problem: NP-complete para determinar si existe k-coloracion
- Chromatic polynomial: Calculo del numero de k-coloraciones validas
- Backtracking pattern: Algoritmo de busqueda exhaustiva con poda

---
