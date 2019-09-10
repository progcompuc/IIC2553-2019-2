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

### C - Tree 2

<details> 
  <summary>Hint</summary>
  Un diametro de un grafo se define como un par de nodos (a,b) tal que la distancia entre ellos es maxima. Un grafo puede tener multiples diametros. Los diametros cumplen varias propiedades interesantes:

<ol>
    <li>Dado un nodo cualquiera u, sea v el nodo mas lejano de u. Esta garantizado que v es el extremo de un diametro.</li>
    <li>Dado un diametro (a,b) y un nodo u cualquiera, esta garantizado que a o b es uno de los nodos mas lejanos a u (es decir, no existe un nodo x tal que dist(x,u) sea mayor a max(dist(a,u),dist(b,u)).</li>
</ol>

La demostracion de estas propiedades queda como ejercicio. La propiedad 1 puede usarse para encontrar un diametro del arbol, y la propiedad 2 puede usarse para responder las queries de manera eficiente.

</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Para encontrar un diametro del arbol, puede hacerse bfs desde un nodo cualquiera. Sea <strong>a</strong> el ultimo nodo visitado (que sabemos es el extremo de un diametro). Luego podemos hacer bfs de nuevo partiendo desde <strong>a</strong> y guardando en <strong>b</strong> el ultimo nodo visitado. Tenemos que (<strong>a</strong>,<strong>b</strong>) es un diametro del arbol.
    </p><p>
  Ahora supongamos que nos dan una query <strong>v</strong>,<strong>d</strong>. Sabemos que solo necesitamos revisar <strong>a</strong> y <strong>b</strong> para encontrar un nodo mas lejano de <strong>v</strong>. Sea <strong>w</strong> este nodo. Si dist(<strong>v</strong>, <strong>w</strong>) es menor a <strong>d</strong>, podemos responder inmediatamente 0. Si la profundidad de <strong>v</strong> es menor o igual a <strong>d</strong>, entonces basta responder el <strong>d</strong>-esimo ancestro de v. En otro caso, podemos responder el ancestro (dist(<strong>v</strong>,<strong>w</strong>)-<strong>d</strong>)-esimo de <strong>w</strong>.
</p><p>
  Para calcular distancias y ancestros en tiempo logaritmico podemos utilizar el metodo de Binary Lifting.
</p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest5/C_Tree_2.cpp">Código de ejemplo</a>
</details>

### E - Minimum spanning tree for each edge

<details> 
  <summary>Hint1</summary>
  Es posible computar el MST una vez, y luego usar ese MST como punto de partida para responder las queries eficientemente.
</details>
<details>
    <summary>Hint2</summary>
    Dado un MST del grafo y una arista (u,v) cualquiera del grafo que no este en el MST, si agregamos la arista (u,v) al MST se forma un ciclo. Que arista (distinta de (u,v)) nos conviene sacar para eliminar este ciclo y minimizar el costo?
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Dado una arista (u,v), el MST que la contiene es equivalente a un MST cualquiera al que se le remueve la arista mas cara en el camino u-v y luego se agrega la arista (u,v).
</p><p>
  Para calcular la arista mas cara entre u y v en el MST se puede utilizar Binary Lifting.
</p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest5/E_MST_for_each_edge.cpp">Código de ejemplo</a>
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
  Encontramos el MST del grafo y luego corremos un DFS sobre el MST calculando por cada nodo el tamaño de su subárbol (cuántos nodos hay en su subárbol incluyéndolo), entonces la contribución de la arista que va de ese nodo a su padre inmediato es igual a su costo multiplicado por (N-K)*K, donde K es el tamaño del subárbol del nodo. Dado que la suma es gigante, podemos guardar su representación binaria en un arreglo de ints suficientemente grande, entonces sumar 2^C * (N-K)*K se puede hacer calculando (N-k)*K en un long long y luego sumando sus bits "a mano" sobre el arreglo shifteados C posiciones.
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
