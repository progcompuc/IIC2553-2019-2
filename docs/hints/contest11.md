---
title: contest 11 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 11](../contests#contest-11) > ```{{page.title}}```

### I - Go up the ultras

<details> 
  <summary>Hint 1</summary>
  Dado un punto i-ésimo del input, podemos separar el problema en 2: encontrar el D_derecha y el D_izquierda. Así, el D será min(D_izquierda, D_derecha).
</details>
<details> 
  <summary>Hint 2</summary>
  Notar que para calcular D_izquierda de un punto i-ésimo, sólo importa la altura mínima que hay entre i y la primera cúspide mayor estricta hacia la izquierda. Cualquier otra cúspide mayor estricta que esté más a la izquierda implica que para llegar a ella debo pasar por el mismo mínimo que está entre i y la primera cúspide mayor estricta, y lo que pase más allá da lo mismo. El mismo razonamiento aplica a D_derecha.
</details>
<details> 
  <summary>Hint 3</summary>
  Para calcular D_izquierda para cada punto, piensa en una forma de iterar sobre los puntos de izquierda a derecha e ir manteniendo en el proceso una estructura de datos que resuma de manera compacta el relieve a la izquierda del punto actual en la iteración, de tal manera que sea fácil calcular D_izquierda para el punto actual. Y luego repite lo mismo pero al revés para D_derecha.
</details>
<details> 
  <summary>Solución + código</summary>
  El problema se puede resolver usando stacks, de una forma análoga a como se resuelve el problema de encontrar el rectángulo más grande en un histograma con stacks (<a href="https://www.spoj.com/problems/HISTOGRA/">link al problema</a>, recomendado como ejercicio al lector). Veamos cómo calcular D_izquierda para cada punto (para D_derecha es simétrico): Imaginemos que en la iteración actual estamos parados en el punto i-ésimo, y definamos la función F(j) = max{ H[k] for k = j .. i } (con j <= i). Si graficamos F(j) se ve como una función escalonada creciente (de derecha a izquierda). Intuitivamente a medida que avanzamos hacia la izquierda desde i y vemos una nueva cumbre más alta que todas las anteriores, comienza un nuevo "peldaño" de la función F (se recomienda graficar con lápiz y papel esto). Imaginemos que identificamos los puntos en que comienzan (hacia la izquierda) estos "peldaños" y además junto con este punto inicial guardamos la altura mínima de los puntos bajo la sombra del peldaño asociado. La idea es que toda esta info la podemos representar a través de un stack de pares (h_peldaño, min_h_en_peldaño). A medida que iteramos sobre los puntos podemos ir actualizando este stack (hacemos pop mientras H[i] sea >= al h_peldaño del tope del stack y al final pusheamos el H[i] actual, y en el proceso podemos ir calculando el min_h_en_peldaño nuevo que pushearemos también). Así, podemos computar un arreglo L donde L[i] = la altura mínima desde i hacia la cúspide mayor estricta ubicada a la izquierda. Y análogamente podemos calcular un R[i] hacia la derecha. Finalmente D[i] = H[i] - max(L[i], R[i]), y si D[i] >= 150000, i es ultra. El algoritmo es O(N) porque un punto es pusheado y popeado del stack a lo más O(1) veces. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/UVA/12674_GoUpTheUltras.cpp">Código de ejemplo</a>
</details>
 
### U - Cleaning Robot

<details> 
  <summary>Hint</summary>
  TSP, BFS
</details>
<details> 
  <summary>Solución + código</summary>
  Armamos un grafo donde los nodos son el robot + las manchas y las aristas tienen peso igual a la distancia entre 2 nodos en el tablero. Las distancias se pueden calcular con BFS. Después queremos encontrar el tour más corto que parte en el robot y visita a todas las manchas. Esto se puede hacer con TSP (TSP = travelling salesman problem, un DP muy estándar con bitmask con complejidad O(N x 2^N)). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/CLEANRBT_CleaningRobot.cpp">Código de ejemplo</a>
</details>
 
### Y - Sign of Matrix
<details> 
  <summary>Hint</summary>
  Puedes modelar los valores en la matriz como un sistema de inecuaciones col_i + row_j > 0, col_i + row_j = 0, col_i + row_j < 0. Así, cada fila impone una condición sobre todas las columnas (en negativo) y viceversa.
</details>
<details> 
  <summary>Hint</summary>
  ¿Qué pasa si hay un ciclo de desigualdades? por ejemplo col_1 > -row_2 = col_3 > -row_4 = col_1. Y si no hay ciclo?
</details>
 <details> 
  <summary>Hint</summary>
  Si modelas las desigualdades como un grafo dirigido y el sistema es consistente, obtienes un DAG. ¿Cómo puedes usar los niveles de este DAG?
</details>
 <details> 
  <summary>Solución + código</summary>
   <p>
   Para ver si hay ciclo necesitas igualar variables, esto se puede hacer con Union Find. Cuando ya verificaste que no hay ciclo puedes separar las variables en un vértice cada uno, o bien trabajar sobre el mismo grafo y recordar cuántas variables están metidas en cada vértice.
   </p>
   <p>
   Lo que quieres es asignar valores de enteros a los niveles de este DAG con tal de que se respeten las desigualdades. Itera por todas y devuelve la de costo mínimo. El costo es la cantidad de <b>variables</b> por nivel × el valor absoluto del entero que estas asignando. Siempre hay una asignación que usa el 0 así que solo debes iterar por 2*n de ellas. Complejidad O(n^2 * T) para T tests.
   </p>
   <a href="https://github.com/mmunos/cp/tree/master/uva/11671%20-%20Sign%20Of%20Matrix">Codigo</a>
</details>


### Z - Rotate Columns (hard version)

<details> 
  <summary>Hint</summary>
  Los límites sugieren que la complejidad debe ser O(m·2^n), piensa de qué te sirve ver los subconjuntos de cada columna.
</details>
<details> 
  <summary>Hint</summary>
  Piensa en un DP de espacio O(m·2^n) que solucione el problema pero sin considerar las rotaciones, y ve como añades las rotaciones después.
</details>
<details> 
  <summary>Hint</summary>
  Para cada par (columna, mask) puedes saber qué rotación es la que más le conviene, antes de hacer el dp. 
</details>
<details> 
  <summary>Hint</summary>
  <p>
    Con los hints de arriba vas a poder resolver la versión "fácil" del problema: <a href="https://codeforces.com/problemset/problem/1209/E1">Rotate Columns (Easy Version)</a>
  </p>
  <p>
  Ahora, la solución final va a usar a lo más n columnas. ¿Ves una forma de preprocesar las columnas y saber cuáles no van ser parte de la solución final?
  </p>
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  El DP es sobre los subconjuntos de filas, para cada columna. En la columna c, el DP[c][mask] va a ser el maximo de DP[c-1][mask1] + maxcol(c, mask2), para los pares mask1 y mask2, donde mask1 | mask2 = mask, mask1 & mask2 = 0, y para calcular maxcol(c, mask2) necesitas revisar todas las rotaciones de mask2 y evaluarlas. Esto tiene complejidad O(2^2n · m · n^2) para cada test, lo que aun no es suficiente.
  </p>
  <p>
  Optimizamos usando el hint 3. Se puede hacer un preproceso sobre los masks y las columnas para tener los maxcol(c, mask). Esto mejora la complejidad a O(2^n · n^2 · m + 2^2n · m) para cada test.
  </p>
  <p>
  Finalmente, con el hint 4, sabemos que no hay que ver todas las columnas. Lo que se puede hacer, es ordenar las columnas por su valor máximo, y considerar solo las n primeras. Esto mejora la complejidad a O(2^n · n^3 + 2^2n · n) por test, lo que pasa raspando.
  </p>
  <a href="https://codeforces.com/contest/1209/submission/63502896">Código de ejemplo</a>
</details>
<details> 
  <summary>Extra</summary>
  <p>
  Si usas un lenguaje lento (Java) vas a necesitar un par de optimizaciones extra:
  </p>
  <p>
  * Las posibles rotaciones para un bitmask forman una clase de equivalencia. Por ejemplo, para n = 4 las clases son {0000}, {0001, 0010, 0100, 1000}, {0011, 0110, 1100, 1001}, {0101, 1010}, {0111, 1110}, {1111}. El DP no necesitas hacerlo sobre todos los bitmask, sino sobre las clases de equivalencia. Para n = 12, los bitmask posibles son 4096 y las clases son 352, lo que mejora el tiempo en un factor de ~11,6.
  </p>
  <p>
  * Para cada clase, ten preprocesada una lista de masks compatibles. Por ejemplo, si estás en la clase 0101, no vas a poder rellenar los 0s con el mask 0011 ni el 0111, tu lista va a tener {0000, 0001, 0101}, o bien, {0000, 0010, 1000, 1010} para no tener que revisar las rotaciones de nuevo. Haciendo un análisis, se puede ver que esto mejora el factor de (2^2n) a 3^n.
  </p>
</details>


<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 11](../contests#contest-11) > ```{{page.title}}```
