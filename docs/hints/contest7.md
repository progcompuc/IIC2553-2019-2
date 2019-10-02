---
title: contest 7 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 7](../contests#contest-7) > ```{{page.title}}```


### A - Surely You Congest
<details> 
  <summary>Hint 1</summary>
  Solo es necesario considerar las aristas del grafo que forman parte de algun camino optimo entre el nodo 1 y algun otro nodo.
</details>
<details> 
  <summary>Hint 2</summary>
  Si dos autos generan una congestion, entonces necesariamente partieron desde nodos que estan a la misma distancia desde el nodo 1.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>Primero podemos correr un dijsktra inicial para encontrar las distancias mas cortas hacia cada nodo desde el nodo 1. Tambien podemos inmediatamente identificar que aristas pertenecen a caminos optimos. Utilizamos estas aristas (poniendoles capacidad unitaria)  y las intersecciones de la ciudad para armar un grafo sobre el que calcularemos flujo, donde el destino es la interseccion 1 y la fuente es un nodo virtual. Sea <strong>G</strong> este grafo. </p>

  <p> Luego agrupamos los autos segun su distancia inicial del destino. La gracia es que autos en grupos distintos no pueden causar congestion. Por cada grupo hacemos lo siguiente:</p>

  <ul>
    <li>Tomamos el grafo <strong>G</strong> obtenido en la primera parte.</li>
    <li>Por cada auto en el grupo conectamos la fuente con el nodo donde parte el auto (con una arista de capacidad 1)</li>
    <li>Calculamos el flujo maximo de la fuente al destino</li>
  </ul>

  <p>Luego, la respuesta final es la suma de los flujos de cada grupo.</p>

  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest7/A_surely_you_congest.cpp">Código de ejemplo</a>
</details>

### B - Boa Viagem, Roim
<details> 
  <summary>Hint 1</summary>   
  Existen algoritmos que calculan el flujo máximo con costo mínimo (osea, de todos los flujos con costo maximo, eligen el de menor costo). Un algoritmo consiste en utilizar Edmonds-Karp, pero en lugar de elegir caminos mas cortos en numero de aristas elige siempre los caminos más baratos para enviar flujo. Más detalles <a href="https://cp-algorithms.com/graph/min_cost_flow.html">acá</a>.
</details>
<details> 
  <summary>Hint 2</summary>
  Piensa en como codificar los costos de las aristas en el grafo de manera que el algoritmo siempre elija la menor cantidad de chartered flights, y de los flujos que usan la menor cantidad de chartered flights que elija la de menor costo total.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Sea T = (suma de los costos de todas las aristas) + 1. Luego, a cada arista que representa un chartered flight sumamos T a su costo.
  </p>
  <p>
  La gracia es que si tomamos un flujo por este grafo (donde todas las aristas tienen capacidad unitaria), el costo siempre se va a ver de la forma C = (# chartered flights) * TC + (costo real), donde el costo real es siempre menor a TC. Por lo tanto, si tenemos un algoritmo que minimiza C, entonces primero va a minimizar el numero de chartered flights y luego va a minimizar el costo real.
  </p><p>
  Con esto, la solucion es computar el flujo desde el inicio al destino sobre el grafo modificado. Sea F y C el valor y el costo de este flujo, respectivamente. Si F es menor a 2, entonces no es posible que Roim y el compañero se vayan por rutas distintas. Si F es menor a 2, entonces utilizamos floor(C/TC) chartered flights, y el costo real es C % TC.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest7/B_boa_viagem_roim.cpp">Código de ejemplo</a>
</details>


### C - In Case of Invasion, Please ...
<details> 
  <summary>Hint 1</summary>
  El tiempo mínimo que le toma a alguien llegar a un refugio R desde un nodo X es la distancia más corta desde X a R en el grafo.
</details>
<details> 
  <summary>Hint 2</summary>
  Si fijamos un instante de tiempo t >= 0 y nos preguntamos "¿es posible que todos puedan llegar a algún refugio en un tiempo menor o igual a t?". Si la respuesta es sí, entonces para t' > t la respuesta es sí también. Si la respuesta es no, para un t' < t la respuesta es no también. Por lo tanto se puede hacer búsqueda binaria sobre t.
</details>
<details> 
  <summary>Hint 3</summary>
  Para un t fijo, el problema de ver si todos pueden llegar a algún refugio en un tiempo <= t se reduce a flujos.
</details>
<details> 
  <summary>Solución + código</summary>
  Calculamos la distancia más corta de cada refugio a cada nodo con Dijkstra. Luego hacemos búsqueda binaria sobre t y en el predicado usamos flujos. Una forma impulsiva de hacerlo sería crear un nodo virtual source que lo conectamos a cada nodo con arista igual a la población del nodo; luego una arista con capacidad infinita de cada nodo a cada refugio tal que la distancia más corta de dicho nodo a dicho refugio sea <= t (si es mayor a t no se alcanza a llegar dentro de t), y finalmente una arista de cada refugio a un nodo virtual destino con capacidad igual a la capacidad del refugio. El problema de esto es que la cantidad de nodos sería enorme, y por complejidad computacional Dinic explotaría. Para resolverlo, notar que si 2 nodos están conectados a los mismos refugios, podemos fusionarlos en un mismo nodo con población = la suma de las poblaciones de los nodos fusionados. Como hay a lo más 10 refugios, a lo más hay 2^10 = 1024 posibles subconjuntos, con lo que la cantidad de nodos baja enormemente. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/kattis/incaseofinvasion.cpp">Código de ejemplo</a>
</details>
  
### D - Keep it Covered
<details> 
  <summary>Hint</summary>
  Las celdas las podemos separar en 2 grupos: las blancas y las negras (si es que pintamos la matriz como tablero de ajedrez). Visto así, la celdas blancas con círculo deben escoger una celda negra vecina a la que conectarse, y las celdas blancas sin círculo deben escoger 2 celdas blancas vecinas a las que conectarse. Las celdas negras con círculo sólo pueden ser escogidas por una celda blanca, mientras que las celdas negras sin sírculo sólo pueden ser escogidas por dos celdas blancas.
</details>
<details> 
  <summary>Solución + código</summary>
  Armamos un grafo para maxflow. Creamos un source y lo conectamos a las celdas blancas. Si la celda blanca tiene círculo, la arista tiene capacidad 1, si no tiene círculo le damos capacidad 2. Luego por cada celda blanca agregamos aristas con capacidad infinita hacia las celdas negras vecinas. Finalmente de las celdas negras agregamos aristas hacia un nodo virtual target (si tiene círculo, con capacidad 1, si no, con capacidad 2). Encontramos el flujo máximo y si se cumple que es igual a la suma de las capacidades de entrada e igual a la suma de las capacidades de salida, entonces se puede, de lo contrario, no se puede. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/LiveArchive/8198_KeepItCovered.cpp">Código de ejemplo</a>
</details>

### E - Domino Art
<details> 
  <summary>Hint</summary>
  Si pintamos las celdas como un tablero de ajedrez, el problema se reduce a "conectar" celdas blancas con sus celdas negras adyacentes utilizando dominos. Por cada celda blanca, hay que tomar la decision de a cual celda negra conectarla.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>El problema se reduce a maximum matching entre las celdas blancas y negras si coloreamos la grilla como un tablero de ajedrez. </p>
  
  <p> Armamos un grafo para flujo maximo con r*c+2 nodos. Luego, para cada celda blanca se conecta una arista desde el nodo fuente hasta el nodo correspondiente a la celda con capacidad 1. Tambien agregamos aristas con capacidad 1 desde el nodo de la celda blanca hacia los nodos que representan las celdas vecinas. Por cada celda negra, conectamos su nodo con el destino con una arista de capacidad unitaria. Si el flujo maximo por este grafo es igual a la mitad de las celdas marcadas, entonces es posible cubrir la grilla con dominos.</p>

  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest7/E_domino_art.cpp">Código de ejemplo</a>
</details>

### H - Attacking Rooks
<details> 
  <summary>Hint</summary>
  Cuando ponemos una torre en una celda (r,c), notemos que la celda (r,c) pertence a un segmento de columna (col_seg[r,c]) y a un segmento de fila (row_seg[r,c]) delimitados ya sea por los bordes del tablero o peones puestos. Ninguna otra torre puede ser puesta en col_seg[r,c] ni en row_seg[r,c] ya que serían atacadas por la torre puesta en (r,c). Por lo tanto, poner una torre en una celda (r,c) se puede interpretar como emparejar row_seg[r,c] con col_seg[r,c].
</details>
<details> 
  <summary>Solución + código</summary>
  El poblema se puede modelar como maximum bipartite matching. Tenemos un grafo bipartito donde un grupo son todos los segmentos de fila y otro grupo son todos los segmentos de columna, y hay una arista de un segmento de fila a un segmento de columna si es que estos comparten una celda. Poner la mayor cantidad de torres posible es equivalente a maximizar la cantidad de parejas que podemos armar en este grafo bipartito. El resto es hacer el típico maxflow para maximum bipartite matching. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/LiveArchive/6525_AttackingRooks.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 7](../contests#contest-7) > ```{{page.title}}```
