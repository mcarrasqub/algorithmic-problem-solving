# Primer Trabajo Práctico: Análisis y Diseño de Algoritmos
**Ejercicio 1: Permutaciones con Restricciones (Fuerza Bruta)**

---

## 1. Descripción Teórica del Problema y Enfoque de Solución

**El Problema:**
Se requiere procesar un conjunto de $n$ elementos distintos (enteros positivos) y encontrar todas las permutaciones posibles que cumplan con una restricción específica: ningún elemento en la posición $i$ puede ser mayor que el doble del elemento en la posición adyacente derecha $i+1$. Expresado formalmente, para toda permutación válida $P$, se debe cumplir:

$P[i] \le 2 \cdot P[i+1]$ para todo $i \in \{0, 1, \dots, n-2\}$

**Enfoque de Solución:**
El problema se aborda mediante un algoritmo de **Fuerza Bruta** con enumeración exhaustiva. Este enfoque consiste en generar sistemáticamente la totalidad del espacio de búsqueda (las $n!$ permutaciones posibles del conjunto) y, posteriormente a la generación de cada candidato, aplicar una función de evaluación (filtro) para verificar si cumple la restricción dada. Para garantizar que se generen absolutamente todas las permutaciones sin repeticiones, el conjunto inicial debe ordenarse de forma ascendente antes de comenzar la enumeración lexicográfica.

---

## 2. Desarrollo del Algoritmo en Pseudocódigo

```text
INICIO
    leer n
    leer arreglo A de tamaño n
    
    // Paso crucial para el orden lexicográfico
    ordenar A de forma ascendente 

    total_generadas = 0
    total_validas = 0

    HACER:
        total_generadas = total_generadas + 1
        valida = VERDADERO
        
        // Evaluar la restricción
        PARA i desde 0 hasta n-2:
            SI A[i] > 2 * A[i+1] ENTONCES:
                valida = FALSO
                break
            FIN SI
        FIN PARA
        
        // Si no se rompió la regla, registrar
        SI valida == VERDADERO ENTONCES:
            imprimir A
            total_validas = total_validas + 1
        FIN SI
        
    MIENTRAS exista una siguiente_permutacion(A)

    imprimir "Total generadas: ", total_generadas
    imprimir "Total válidas: ", total_validas
FIN
```

---

## 3. Ejemplos de Entrada y Salida Esperadas

Para validar el programa, realizamos una prueba de escritorio con $n = 3$ y el conjunto $\{1, 3, 4\}$.

**Nota sobre el caso de prueba:** A diferencia del ejemplo del documento base que indica 3 salidas válidas, el análisis matemático demuestra que solo existen 2 combinaciones que satisfacen la condición.

**Entrada:**
```text
n = 3
1 3 4
```

**salida real del programa:**
```
1 3 4 
1 4 3 
--------------------------------
total_generadas = 6
total_validas   = 2
Tiempo de ejecucion: 0.00xx segundos
```
---

## 5. Análisis de Complejidad y Preguntas Guía

### Clasificación del Enfoque (Fuerza Bruta vs. Backtracking)
**¿Por qué este enfoque se clasifica como Fuerza Bruta y no como Backtracking?**

Se clasifica como Fuerza Bruta porque el algoritmo es exhaustivo y "ciego" durante la fase de generación. Genera la permutación completa de los n elementos antes de evaluar si es correcta o no. Un enfoque de Backtracking, por el contrario, evaluaría la viabilidad de la solución de forma incremental (mientras construye la permutación). Si en el paso 2 la restricción ya se rompió, el Backtracking descartaría ese camino inmediatamente, mientras que la Fuerza Bruta actual termina de armar el arreglo completo inútilmente para luego descartarlo.

### Complejidad Algorítmica
* **Complejidad Temporal:** O(n * n!)
    El universo total de permutaciones para n elementos es de n!. Por cada una de estas permutaciones generadas, el algoritmo itera a través del arreglo para validar la restricción, realizando en el peor de los casos n-1 comparaciones. Por ende, el tiempo de ejecución crece proporcional al producto de la cantidad de permutaciones por el tamaño del arreglo.
* **Complejidad Espacial:** O(n)
    La memoria requerida no depende del número de permutaciones generadas (n!), ya que no las almacenamos simultáneamente. Solo requerimos un arreglo de tamaño n para almacenar la permutación actual y unas pocas variables primitivas para los contadores. La función next_permutation opera in-place (sobre el mismo arreglo).

### Impracticabilidad y Tiempos de Ejecución
**¿A partir de qué valor de n el tiempo de ejecución se vuelve impracticable en su equipo?**

A partir de n = 12, la cantidad de permutaciones (12! ≈ 479 millones) hace que la ejecución interactiva sea impracticable, tomando tiempos excesivamente largos para un análisis rápido.

| Valor de n | Total Permutaciones Generadas (n!) | Tiempo de ejecución |
| :--- | :--- | :--- |
| n = 10 | 3,628,800 | 35 s |
| n = 11 | 39,916,800 | 236 s (4 min aprox) |
| n = 12 | 479,001,600 | >30min |


### Proporción de Permutaciones Válidas
**¿Qué ocurre con la proporción de permutaciones válidas respecto al total a medida que n crece?**

La proporción (Válidas / Total) tiende rápidamente a cero. Esto se debe a que el denominador (el total de permutaciones) crece a un ritmo factorial explosivo, mientras que el numerador (las válidas) crece a un ritmo muchísimo más lento. Al aumentar n, se incrementa la cantidad de comparaciones adyacentes que deben cumplirse simultáneamente. La probabilidad de que un número grande caiga justo antes de un número pequeño (violando la regla P[i] <= 2 * P[i+1]) aumenta drásticamente, haciendo que la gran mayoría de las permutaciones generadas se descarten.

### Mejora del Enfoque (Poda Temprana)
**Si se quisiera mejorar el enfoque con Backtracking, ¿en qué paso del algoritmo se podría construir el árbol de búsqueda?**
El árbol de búsqueda se construiría paso a paso, insertando elemento por elemento de izquierda a derecha. Al intentar colocar un elemento en el índice i (para i > 0), el algoritmo aplicaría la regla evaluando P[i-1] <= 2 * P[i]. Si la evaluación es falsa, se aplica una "poda": no se generan los subárboles correspondientes a los (n-i)! arreglos restantes de esa rama, y el algoritmo hace un retroceso (backtrack) para intentar colocar el siguiente número disponible en la posición i.

### Generación Exacta
**¿Por qué se garantiza que next_permutation genera exactamente n! permutaciones si el arreglo está ordenado inicialmente?**
Porque el algoritmo detrás de next_permutation genera combinaciones basándose en un orden lexicográfico estricto. Al iniciar con el arreglo ordenado de menor a mayor (el mínimo valor lexicográfico posible), la función calcula matemáticamente el siguiente reordenamiento inmediatamente superior. Como avanza sin saltos y sin repeticiones hasta alcanzar el orden de mayor a menor (el arreglo en reversa, que es el límite máximo), se asegura de recorrer de principio a fin el conjunto completo y finito de las n! combinaciones posibles.