---
title: contest 1 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 1](../contests#contest-1) > ```{{page.title}}```

### A - Valeriy and Deque
<details> 
   <summary>Hint</summary>
      Ver si en el algún momento las cosas comienzan a repetirse cíclicamente y aprovechar eso
</details>
<details>
   <summary>Solución + código</summary>
   Simular hasta que el máximo quede al comienzo. De ahí en adelante los que están a la derecha del máximo van rotando. Para las queries que van antes del ciclo responde con lo simulado, y para las queries que caen dentro del ciclo calcula modularmente cual va a ser el elemento sacado. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/1180C_ValeriyAndDeque.cpp">Código de ejemplo</a>
</details>


### B - Roadwork
<details> 
   <summary>Hints</summary>
   1) En vez de pensar "esta persona, en qué obra se detiene?" puedes pensar "esta obra, a qué personas detiene?".
   2) Si una obra detiene a alguien, las obras a la derecha ya no lo pueden detener. Ve las obras en ese orden.
   3) Si tienes a las personas ordenadas por tiempo de salida, puedes saber en log n quién va a ser la primera persona en ser bloqueada por cierta obra.
</details>
<details> 
  <summary>Solución</summary>
   Ordena las obras e itera por ellas de izquierda a derecha. 
   Para cada obra, calcula qué tiempos de salida van a ser bloqueados, osea S-X <= D < T-X, y elimina a estas personas de la lista.
   La posicion de la obra es el punto de llegada para estas personas.
   Esto se puede hacer en (#personas x log n) con un multiset.
   El tiempo total es O(N + Q log Q).
</details>
<details> 
  <summary>Hints 2</summary>
   Piensa el problema geométricamente en un plano de Tiempo vs Posición
</details>
<details> 
  <summary>Solución 2 + código</summary>
   En el plano 2D las personas se ven como rectas diagonales y los roadworks como segmentos de recta horizontales. Cada persona se detiene con el primer segmento que se intersecta. Para hacerlo eficientemente, podemos hacer un sweep line diagonal manteniendo un set de segmentos activos ordenados de menor a mayor. La complejidad es O((N+Q) log (N+Q) + N log N + Q). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/AtCoder/abc128_e_Roadwork.cpp">Código de ejemplo</a>
</details>

### C - Two Teams
<details>
  <summary> Hint </summary>
  Puedes mantener a los estudiantes en un arbol ordenado por *skill* para poder 1) Determinar quien tiene la mayor *skill* en O(log(n)), y 2) Poder eliminar a los estudiantes que van saliendo en O(log(n)) cada uno
</details>
<details>
  <summary> Hint 2</summary>
  Puedes mantener a los estudiantes en una lista ligada para poder en O(1) determinar quien esta al lado de otro y sacarlo (o en un arbol ordenado por indice para hacerlo en O(log(n))).
</details>
<details>
  <summary> Solucion + Codigo </summary>
  Usar los dos hints anteriores, y repetir
  
  1. Determinar cual es el estudiante con la mayor *skill* y sacarlo
  2. Sacar *k* estudiantes a la derecha e izquierda utilizando la lista o arbol

  hasta que ya no queden mas estudiantes. A medida que se sacan estudiantes de la lista, asignarlos al equipo 1 o 2 como corresponde.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest1/C_TwoTeams.cpp">Código de ejemplo</a>
</details>

### D - Memory Management
<details>
  <summary>Hint 1</summary>
  Puedes mantener los numeros de bloques de memoria libres en un set o priority queue para poder ver cual es el numero de bloque de memoria libre mas bajo para poder asignarlo
</details>
<details>
  <summary>Hint 2</summary>
  Puedes mantener un set con los bloques de memoria asignados ordenados por tiempo de manera de poder 1) Determinar el bloque mas antiguo en O(log(n)) para ser removido, y 2) Poder cambiar el tiempo de un bloque cuando se accede a el. Ademas necesitas un map de numero de bloque a bloque de memoria, para poder acceder al bloque de memoria correcto cuando llega una query por un numero de bloque.
</details>
<details>
  <summary>Solucion + Codigo</summary>
  Usar los dos hints anteriores simplemente.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest1/D_MemoryManagement.cpp">Código de ejemplo</a>
</details>

### E - Largest Rectangle in a Histogram
<details> 
  <summary>Hint</summary>   
  El rectángulo máximo necesariamente tiene una altura igual a alguna columna. Sólo hay N columnas, así que puedes ponerte en los N casos, y sólo te falta saber el ancho. Dada una columna i-ésima, piensa en alguna forma de encontrar los extremos L[i] y R[i] del rectángulo maximal que se formaría si expandimos la columna i-ésima lo más que se puede hacia ambos lados.
</details>
<details> 
  <summary>Solución + código</summary>
  Primero calculamos L[i] de izquierda a derecha (para R[i] podemos hacer lo mismo al revés). Para ello mantenemos un stack, en cada instante el stack guarda los distintos mínimos acumulados de las alturas de las columnas medidos desde la columna i-1 hacia la izquierda, junto con el extremo derecho donde comienza a regir cada mínimo (para entender mejor esto, dibujar un histograma, pararse en alguna columna de al medio y dibujar la altura del mínimo acumulado hacia la izquierda, se ve como una función escalonada). Con ese stack es fácil encontrar L[i] (hacemos pop hasta que llegamos a un mínimo < H[i]) y actualizarlo (pusheamos el par (H[i],i)). Como cada columna es pusheada y popeada sólo 1 vez, la complejidad es O(N). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/HISTOGRA_LargestRectangleInAHistogram.cpp">Código de ejemplo</a>
</details>

### F - Weird Function

<details> 
  <summary>Hint</summary>
  Piensa en una forma eficiente de trackear la mediana.
</details>
<details> 
  <summary>Solución + código</summary>
  Una forma de trackear la mediana es guardando la mitad inferior de los valores en un maxheap y la mitad superior de los valores en un minheap, manteniendo la invariante de que la mediana siempre se encuentre en el tope del maxheap. Cuando agreguemos un nuevo valor, lo comparamos con la mediana actual y lo metemos en el minheap o maxheap según corresponda, teniendo cuidado de mantener los 2 contenedores balanceados en tamaño para mantener la invariante. Insertar y meter en heaps es O(log N) así que la complejidad total es O(N log N). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/WEIRDFN_WeirdFunction.cpp">Código de ejemplo</a>
</details>

### G - Criss-cross Cables

<details> 
  <summary>Hint</summary>
  Hay N*(N-1)/2 pares de ubicaciones posibles, que si los ordenamos por largo de menor a mayor codiciosamente nos convendrían los M primeros ¿verdad? Piensa en una forma de encontrar los M primeros sin tener que generar los N*(N-1)/2 pares explícitamente.
</details>
<details> 
  <summary>Solución + código</summary>
  Ordenamos los cables por largo de menor a mayor. Además, usamos un minheap (priority_queue) y primero lo llenamos con intervalos correspondientes a pares consecutivos (i, i+1). Luego de forma sincronizada iteramos sobre los cables y vamos sacando intervalos del minheap, si el algún punto el cable no se la puede o nos quedamos cortos de intervalos, no se puede. Si no, cada vez que sacamos un intervalo, metemos al minheap un nuevo intervalo alargado un índice más a la derecha (o sea, si sacamos el intervalo (i,j), metemos el intervalo (i,j+1)). La complejidad es O(M log M + M log N). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/kattis/crisscrosscables.cpp">Código de ejemplo</a>
</details>

### H - equeue
<details>
  <summary>Hint</summary>
  Nunca es necesario botar items de la mano y luego seguir tomando items. Siempre se pueden botar todos los items al final.
</details>
<details>
  <summary>Hint 2</summary>
  Si todos los items se van a botar al final, entonces no importa el orden en el que se tomen items de la derecha e izquierda del cilindro
</details>
<details>
  <summary>Solucion + Codigo</summary>
  Sea L el numero de items que tomamos de la izquierda, R el numero de items que tomamos de la derecha, y V(L,R) el valor que obtenemos de tomar estos items y luego botar los K-(L+R) items mas negativos (o botar todos los items negativos si hay menos que K-(L+R)). Podemos calcular V(L,R) en O(n), y hay n^2 combinaciones posibles de L,R. Por lo tanto, podemos calcular todos los posibles valores de V(L,R) en O(N^3) y quedarnos con el maximo.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest1/H_equeue.cpp">Código de ejemplo</a>
</details>

### I - Cat Party (Hard Edition)

<details> 
  <summary>Hint</summary>
  Imaginemos que tenemos un leaderboard / ranking donde los competidores son los colores y sus scores son sus frecuencias, y sólo aparecen colores con scores positivos. Si le quitamos 1 punto a algún color, para que en el leaderboard nos aparezcan todos empatados necesitamos que haya un color que tenga exactamente 1 punto y que todos los demás estén empatados (así le quitamos 1 al de 1 punto y se borra) o bien que haya un color que tenga 1 más que el resto (le restamos 1 a ese y todos quedan empatados). Además, cada día hay que actualizar el leaderboard ya que el score de algún color aumenta en 1. Piensa en una forma eficiente de hacer todo eso.
</details>
<details> 
  <summary>Solución + código</summary>
  Básicamente hacer lo que dice el hint usando un set e iteradores. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/1163B2_CatParty(HardEdition).cpp">Código de ejemplo</a>
</details>

### J - Back to the Future

<details> 
  <summary>Hint</summary>
  Darse cuenta de que para un nodo cualquiera del grafo, para satisfacer los requisitos de A y B a ese nodo siempre le conviene que el conjunto sea lo más grande posible: para satisfacer A lo ideal es que estén la mayor cantidad de vecinos, para satisfacer B lo ideal es que estén la mayor cantidad de no-vecinos. Hay un conjunto de nodos que genera la situación ideal para todos los nodos simultáneamente: el conjunto de todos los nodos. Si en ese conjunto ideal hay nodos que no cumplen, entonces no hay ningún subconjunto en el que puedan llegar a cumplir y por ende los podemos descartar. Piensa en alguna forma eficiente de ir descartando nodos partiendo desde el conjunto universo hasta llegar a un subcojunto maximal en que todos cumplen.
</details>
<details> 
  <summary>Solución + código</summary>
  Metemos todos los nodos a un set ordenados por cantidad de vecinos (y desempatados por ID para permitir duplicados), e iterativamente vamos borrando nodos por el extremo izquierdo del set cuando no cumplen A y por la derecha del set cuando no cumplen B. Cada vez que descartamos un nodo, tenemos que avisarle a cada uno de sus vecinos que ese nodo ya no está y además tenemos que actualizar la ubicación del vecino dentro del set (eso se puede hacer borrándolo y metiéndolo de nuevo con su score actualizado). La complejidad de esto es O((N+M)log(N)). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/LiveArchive/7887_BackToTheFuture.cpp">Código de ejemplo</a>
</details>

### K - Who is The Boss
<details> 
  <summary>Hint 1</summary>
   Lo ideal sería encontrar el jefe inmediato de cada empleado, teniendo eso es fácil armar un grafo (en realidad un árbol) y saber cuántos subordinados en total tiene cada empleado.
</details>
<details> 
  <summary>Hint 2</summary>
   Para encontrar el jefe inmediato de cada empleado, piensa en alguna forma de ordenar los empleados lexicográficamente de tal modo que puedas iterar sobre ellos y en cada paso ir actualizando alguna estructura de datos que te permita encontrar el jefe inmediato del empleado actual en la iteración.
</details>
<details> 
  <summary>Hint 3</summary>
   Suponiendo que ya lograste armar el grafo (árbol), ten cuidado de no realizar cómputos innecesarios para encontrar la cantidad de subordinados .. quizás podrías usar ... (spoiler alert) ... programación dinámica sobre el árbol?
</details>
<details>
  <summary>Solución + código</summary>
   Ordena los empleados por altura de mayor a menor y en caso de empate desempata por sueldo (de mayor a menor). Así, para cada empleado se cumple que todos los empleados con altura mayor estricta están a su izquierda, y de los empleados que le empatan en altura los que le ganan en sueldo están a la izquierda también (y así, si el empleado i-ésimo tiene algún jefe inmediato, dicho jefe necesariamente aparece antes que él en la lista). Para encontrar al jefe inmediato, lo que hacemos es mantener a todos los empleados vistos hasta el momento ordenados por sueldo en un árbol binario balanceado (un set de C++). Si insertamos al empleado actual en el set, el empleado que queda justo a su derecha es el menor con sueldo mayor estricto y altura mayor o igual, así que ese es el jefe inmediato. Haciendo eso para cada empleado encontramos todos los jefes inmediatos y con eso es fácil armar un árbol y hacer programación dinámica sobre el árbol para contar los subordinados de todos los empleados, y finalmente responder las queries. La complejidad de esto O(N log N) por ordenar N empleados, O(N log N) por iterar sobre los empleados y actualizar el set en cada paso y O(N) por hacer DP sobre el árbol y responder las queries, lo que da una complejidad total de O (N log N + N). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/VBOSS_WhoIsTheBoss.cpp">Código de ejemplo</a>
</details>

### L - Daunting device
<a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/URI/DauntingDevice.cpp">Código de ejemplo</a>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 1](../contests#contest-1) > ```{{page.title}}```
