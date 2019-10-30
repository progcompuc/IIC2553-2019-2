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
  
### O - Koala and Notebook

<details> 
  <summary>Hint 1</summary>
  Notar que si hay 2 caminos para llegar a un nodo X, siempre conviene el camino cuyo string asociado (concatenación de los números en el camino) sea el más corto posible (un número con menos dígitos es siempre menor). Si los 2 strings empatan en largo, en ese caso me conviene el camino con el string lexicográficamente menor.
</details>
<details> 
  <summary>Hint 2</summary>
  Si tengo una arista bidireccional U-V etiquetada con el string "12045", podemos reemplazar dicha arista por 2 cadenas de aristas <strong>dirigidas</strong> obteniendo un nuevo grafo equivalente al original:
  
  <p>U -1-> M0 -2-> M1 -0-> M2 -4-> M3 -5-> V</p>
  <p>V -1-> M4 -2-> M5 -0-> M6 -4-> M7 -5-> U</p>
 Donde los M_i son nodos intermedios nuevos, y las notación usada [A] -[d]-> [B] denota una arista dirigida del nodo [A] al nodo [B] con peso igual al dígito [d].
</details>
<details> 
  <summary>Solución + código</summary>
  Modificamos el grafo usando el hint 2. Luego la idea es usar BFS por niveles, donde el i-ésimo nivel es el conjunto de todos los nodos que están a i pasos del nodo 1 (y no se puede llegar desde 1 en menos pasos). El nivel base es el nodo 1 solo que trivialmente tiene costo 0 llegar. Luego inductivamente podemos calcular el óptimo para todos los nodos del nivel i-ésimo asumiendo que tenemos y calculamos bien el óptimo para los nodos del (i-1)-ésimo. Para ello supongamos que por cada nivel tenemos (1) los nodos que están en ese nivel, (2) el costo óptimo para llegar a ellos y (3) un arreglo "rank" que resume cómo están compardos los strings de los caminos óptimos a cada uno de los nodos del nivel (si un string es mayor lexicográficamente que otro, su rank debe ser mayor al del otro, y si hay empate lexicográfico, los ranks deben empatar también). Inductivamente si asumimos que tenemos todo eso calculado bien para el nivel (i-1)-ésimo, no es díficil obtener lo mismo para el nivel i-ésimo: los nodos del nivel i-ésimo son nodos no visitados alcanzables en un paso por nodos del nivel (i-1)-ésimo, el string del camino óptimo a un nodo X del nivel i-ésimo es igual a un string óptimo a un nodo Y del nivel anterior + el dígito de la arista de Y a X (si hay más de una opción así, el óptimo es la menor lexicográficamente entre todas esas, lo cual se puede obtener comparando pares (rank[Y], digit[Y][X])). Finalmente los costos óptimos para el nivel i-ésimo se obtienen como costo[u] = (costo[p] * 10 + digit[p][u]) % MOD, donde p es el nodo "padre" del nivel anterior desde el cual llegamos al nodo u óptimamente.
  
  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/1209F_KoalaAndNotebook/sol.cpp">Código de ejemplo</a>
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

### V - Reklame

<details> 
  <summary>Hint</summary>
  Si quieres comenzar un request después de que ya terminaron todos los requests, siempre te conviene hacer que comience inmediatamente después del último día con publicidad.
</details>
<details> 
  <summary>Hint</summary>
  Una vez haces que un request comience un día d, entonces para el siguiente request te puedes olvidar de lo que hubo en los días d' < d.
</details>
 <details> 
  <summary>Hint</summary>
  Fíjate que nunca vas a hacer que un request comience antes de 7 días previo al último día con publicidad.
</details>
<details> 
  <summary>Hint</summary>
  Antes de considerar los hints de arriba, podemos pensar en un DP mas o menos naive que describe la distribución completa de ads en el banner, para los primeros d días. Pero esto no pasa porque son demasiados estados. Con los hints nos damos cuenta que solo hace falta recordar los últimos 7 días, y una de sus dimensiones del DP va a ser (k+1)^7.
</details>
<details> 
  <summary>Hint</summary>
  <p>
  Con los tres hints de arriba, podemos armar un DP booleano de dimensiones (k+1)^7 × n × (7n+1), es decir, cada estado va a ser (mask, i, r) donde mask es la descripción de los últimos 7 días del banner, i es el request que estoy revisando, y r es el día en que termino todos los requests hasta el i. Por lo tanto dp[mask][i][r] va a ser true si es que existe una distribución de los primeros i requests, cuyos últimos 7 días se ven como mask, que termina el día r. Después retornamos el mínimo r para dp[][n-1][]. Esto todavía es muy lento.
  </p>
  <p>
  Ahora, imagina que los primeros cuatro requests son:
  </p>  
<table><tr><th>A</th><th>_</th><th>_</th><th>A</th><th>A</th><th>A</th><th>A</th></tr></table>
<table><tr><th>B</th><th>_</th><th>_</th><th>B</th><th>_</th><th>_</th><th>B</th></tr></table>
<table><tr><th>C</th><th>C</th><th>C</th><th>_</th><th>_</th><th>_</th><th>_</th></tr></table>
<table><tr><th>D</th><th>_</th><th>D</th><th>_</th><th>_</th><th>_</th><th>D</th></tr></table>
  <p>
  Y tienes estas dos formas de colocarlos en los primeros días, con k = 2:
  </p>  
  <table>
  <tr>
    <th>A</th><th>_</th><th>_</th><th>A</th><th>A</th><th>A</th><th>A</th><th>C</th><th>C</th><th>C</th><th>_</th><th>_</th><th>_</th><th>_</th>
    </tr>
    <tr>
    <th>B</th><th>_</th><th>_</th><th>B</th><th>_</th><th>_</th><th>B</th><th>D</th><th>_</th><th>D</th><th>_</th><th>_</th><th>_</th><th>D</th>
  </tr>
  </table>
<table><tr><th>A</th><th>B</th><th>_</th><th>A</th><th>A</th><th>A</th><th>A</th><th>B</th><th>_</th><th>_</th><th>_</th><th>_</th><th>_</th><th>_</th></tr>
<tr><th>_</th><th>C</th><th>C</th><th>C</th><th>B</th><th>D</th><th>_</th><th>D</th><th>_</th><th>_</th><th>_</th><th>D</th><th>_</th><th>_</th></tr></table>
  <p>
  Fíjate que en cada distribución la cantidad de ads por día en el banner es:
  </p>
<table><th>2</th><th>0</th><th>0</th><th>2</th><th>1</th><th>1</th><th>2</th><th>2</th><th>1</th><th>2</th><th>0</th><th>0</th><th>0</th><th>1</th></table>
<table><th>1</th><th>2</th><th>1</th><th>2</th><th>2</th><th>2</th><th>1</th><th>2</th><th>0</th><th>0</th><th>0</th><th>1</th></table>
  <p>
  Los últimos 7 días en las dos distribuciones se ven igual. Para el quinto request, ¿vale la pena recordar estas dos distribuciones?
  </p>
</details>
  <details> 
<summary>Solución</summary>
    <p>
  Es un DP de tamaño (k+1)^7 × n, donde cada estado (mask, i) guarda la forma más eficiente (que termina en la primera fecha posible) de distribuir los primeros i requests, y tal que los últimos 7 días se ven como mask. 
    </p>
    <a href="https://github.com/mmunos/cp/blob/master/Z_trening/807%20-%20Reklame">Código</a>
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
   Lo que quieres es asignar valores de enteros a los niveles de este DAG con tal de que se respeten las desigualdades. Itera por todas y devuelve la de costo mínimo. El costo es la cantidad de <b>variables</b> por nivel × el valor absoluto del entero que estas asignando. Siempre hay una asignación que usa el 0 así que solo debes iterar por 2n de ellas. Complejidad O(n^2 × T) para T tests.
   </p>
   <a href="https://github.com/mmunos/cp/tree/master/uva/11671%20-%20Sign%20Of%20Matrix">Codigo</a>
</details>


### Z - Rotate Columns (hard version)

<details> 
  <summary>Hint</summary>
  Los límites sugieren que la complejidad debe ser O(m × 2^n), piensa de qué te sirve ver los subconjuntos de cada columna.
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
