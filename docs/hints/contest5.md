---
title: contest 5 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 5](../contests#contest-5) > ```{{page.title}}```


### B - Lowest Common Ancestor
<details> 
  <summary>Hint</summary>
  Problema "hello world" de LCA. Si te complicas implementádolo por primera vez, en los apuntes hay implementaciones de ejemplo, aunque recomiendo la primera vez entender bien la estructura en vez de hacer copy paste ciegamente.
</details>
<details>
  <summary>Solución + código</summary>
  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/LCA_LowestCommonAncestor.cpp">Código de ejemplo</a>
</details>

### I - Roads in Hackerland
<details> 
  <summary>Hint 1</summary>
  Notar que todas las aristas tienen pesos distintos (de hecho, potencias de 2 distintas). Entonces, el costo de un camino simple en el grafo se puede ver como un número binario, donde cada arista me indica qué bit debo prender.
</details>
<details> 
  <summary>Hint 2</summary>
  Se puede demostrar que el camino más barato entre 2 nodos A y B es el camino que los conecta en el Minimum Spanning Tree del grafo. Para verlo, por contradicción imagina que el óptimo fuera un camino alternativo distinto al del MST, dicho camino necesariamente debe usar al menos una arista e = (u,v) que no está en el MST. Luego hay 2 casos: 1) el costo de la arista "e" es mayor al camino que conecta u con v en el MST, en este caso podemos reemplazar "e" con el camino que conecta "u" con "v" en el MST y obtener un camino aún más barato para llegar de A a B (-><- contradicción), o bien 2) el costo de "e" es menor que el costo del camino de u a v en el MST, esto implica que hay una arista en dicho camino con una potencia de 2 mayor a la pontecia de 2 de "e", así que podemos reemplazar esa arista con "e" y obtener un MST aún más barato (-><- contradicción también). Es decir, en ambos casos hay contradicción así que nuestra suposición inicial es errónea, es decir, el óptimo entre A y B es necesariamente el camino del MST.
</details>
<details> 
  <summary>Hint 3</summary>
  Calcular la sumatoria de todos los caminos mínimos es equivalente a iterar por cada arista del MST y preguntarse en cuántos caminos mínimos dicha arista aparece, y así la contribución de la arista sería costo(arista) x count(arista). Y contar esto es trivial, la arista es un puente que separa al MST en 2 partes, entonces dicha arista aparece en todas las combinaciones de nodos de una parte con la otra.
</details>
<details> 
  <summary>Solución + código</summary>
  Encontramos el MST del grafo y luego corremos un DFS sobre el MST calculando por cada nodo el tamaño de subárbol (cuántos nodos hay en su subárbol incluyéndolo), entonces la contribución de la arista que va de ese nodo a su padre inmediato es igual a su costo multiplicado por (N-K)*K, donde K es el tamaño del subárbol del nodo. Dado que la suma es gigante, la podemos guardar la representación binaria en un arreglo de ints suficientemente grande, entonces sumar 2^C * (N-K)*K se puede hacer calculando (N-k)*K en un long long y luego sumando "a mano" sobre el arreglo shifteados C posiciones.
  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/hackerrank/RoadsInHackerLand.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 5](../contests#contest-5) > ```{{page.title}}```
