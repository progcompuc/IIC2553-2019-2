---
title: contest 7 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 7](../contests#contest-7) > ```{{page.title}}```

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
  Las celdas las podemos separar en 2 grupos: las blancas y las negras (si es que pintamos la matriz como tablero de ajedrez). Visto así, la celdas blancas con círculo deben escoger una celda negra vecina a que conectarse, y las celdas blancas sin círculo deben escoger 2 celdas blancas vecinas a las que conectarse. Las celdas negras con círculo sólo pueden ser escogidas por una celda blanca, mientras que las celdas negras sin sírculo sólo pueden ser escogidas por dos celdas blancas.
</details>
<details> 
  <summary>Solución + código</summary>
  Armamos un grafo para maxflow. Creamos un source y lo conectamos a las celdas blancas. Si la celda blanca tiene círculo, la arista tiene capacidad 1, si no tiene círculo le damos capacidad 2. Luego por cada celda blanca agregamos aristas con capacidad infinita hacia las celdas negras vecinas. Finalmente de las celdas negras agregamos aristas hacia un nodo virtual target (si tiene círculo, con capacidad 1, si no, con capacidad 2). Encontramos el flujo máximo y si se cumple que es igual a la suma de las capacidades de entrada e igual a la suma de las capacidades de salida, entonces se puede, de lo contrario, no se puede. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/LiveArchive/8198_KeepItCovered.cpp">Código de ejemplo</a>
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
