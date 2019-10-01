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
  Calculamos a distancia más corta de cada refugio a cada nodo con Dijkstra. Luego hacemos búsqueda binaria sobre t y en el predicado usamos flujos. Una forma impulsiva de hacerlo sería crear un nodo virtual source que lo conectamos a cada nodo con arista igual a la población del nodo; luego un arista con capacidad infinita de cada nodo a cada refugio tal que la distancia más corta de dicho nodo a dicho refugio sea <= t (si es mayor a t no se alcanza a llegar dentro de t), y finalmente una arista de cada refugio a un nodo virtual destino con capacidad igual a la capacidad del refugio. El problema de esto es que la cantidad de nodos sería enorme, y por complejidad computacional Dinic explotaría. Para resolverlo, notar que si 2 nodos están conectados a los mismos refugios, podemos fusionarlos en un mismo nodo con población = la suma de las poblaciones de los nodos fusionados. Como hay a lo más 10 refugios, a lo más hay 2^10 = 1024 posibles subconjuntos, con lo que la cantidad de nodos baja enormemente. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/kattis/incaseofinvasion.cpp">Código de ejemplo</a>
</details>


<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 7](../contests#contest-7) > ```{{page.title}}```
