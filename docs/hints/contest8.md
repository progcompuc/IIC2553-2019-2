---
title: contest 8 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```

### A - Jobbery
<details> 
  <summary>Hint 1</summary>
  Básicamente nos piden encontrar todos los nodos pertenecientes a la SCC raíz del DAG de SCCs (si es que hay). Si no hay una única SCC raíz para todo el DAG, entonces no hay ningún senador peligroso.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Notar que encontrar la SCC raíz del DAG es equivalente a encontrar la (única) SCC hoja del DAG inverso (invirtiendo la dirección de las aristas). Corremos entonces tarjan sobre el grafo inverso y la primera vez que detectemos una SCC esa es una SCC hoja. Para chequear si dicha ese SCC es raíz del grafo original, corremos un DFS partiendo de un nodo cualquiera de dicha SCC y vemos si llegamos a todos los nodos, en cuyo caso todos los nodos de la SCC que encontramos son los senadores peligrosos. Para evitar seguir explorando más SCCs innecesariamente, una vez que ya encontramos la primera SCC interrumpimos la exploración (se puede hacer retornando true en el dfs).
  </p>
  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/acm.timus.ru/1198_Jobbery.cpp">Código de ejemplo</a>
</details>

### B - Good Travels
<details> 
  <summary>Hint 1</summary>
  Si el equipo llega a una ciudad u, el recorrido optimo siempre va a pasar por todas las ciudades v tales que v es alcanzable desde u y u es alcanzable desde v. Si un recorrido optimo no hiciera esto, siempre podriamos visitar esa ciudad v que nos falto, volver a u, y luego continuar el recorrido, mejorando el optimo.
</details>
<details> 
  <summary>Hint 2</summary>
  Otra manera de plantear el hint anterior es: Si un recorrido pasa por una componente fuertemente conexa, entonces visita todos los nodos de esa componente.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Dado el grafo de ciudades, obtener el DAG de componentes fuertemente conexas. Para cada componente calcular la suma de f_i para sus nodos. Luego el problema se reduce a encontrar el camino con la suma de f_i mas alta en el DAG de componentes fuertemente conexas, lo que puede hacerse en tiempo lineal.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest8/B_Good_Travels.cpp">Código de ejemplo</a>
</details>

### C - Checkposts
<details> 
  <summary>Hint</summary>
  Cada checkpost puede proteger la SCC a la que pertenece y nada más. Por lo que basta con poner un checkpost por SCC, y como queremos minimizar el costo escogemos el nodo más barato en cada SCC, pero pueden haber empates ...
</details>
<details> 
  <summary>Solución + código</summary>
  Corremos tarjan y encontramos todos los SCCs, por cada SCC encontramos el nodo de costo mínimo y cuántos nodos dentro de la SCC empatan a ese costo mínimo. El costo total es la sumatoria sobre el costo mínimo de cada SCC. Las formas de lograrlo es el productoria sobre la frecuencia del costo mínimo en cada SCC. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/427C_Checkposts.cpp">Código de ejemplo</a>
</details>

### D - Hedge Mazes
<details> 
  <summary>Hint</summary>
  <p>
  Supongamos que tenemos un camino simple entre los nodos S y T. Tomemos una arista (u,v) cualquiera de este camino. Tenemos dos opciones:
  </p>
  <ol>
    <li>
        Hay un camino entre u y v que no utiliza la arista (u,v)
    </li>
    <li>
        La arista (u,v) es el unico camino entre los nodos u y v
    </li>
  </ol>
  <p>
  Si estamos en el primer caso, entonces hay otro camino simple entre los nodos S y T que no utiliza la arista (u,v).
  </p>
</details>
<details> 
  <summary>Hint 2</summary>
  Si tomamos un camino simple entre S y T, este camino simple es unico si y solo si todas las aristas en este camino son aristas de corte.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Como dicen los hints, la solucion para cada query (S,T) consiste en encontrar un camino simple entre S y T y luego revisar que todas las aristas utilizadas sean aristas de corte. Para realizar esto eficientemente se puede utilizar binary lifting.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest8/D_Hedge_Mazes.cpp">Código de ejemplo</a>
</details>

### E - Capital City
<details> 
  <summary>Hint</summary>
  Lo mismo que el A - Jobbery pero al revés.
</details>
<details> 
  <summary>Solución + código</summary>
  Lo mismo que el A - Jobbery pero al revés. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/CAPCITY_CapitalCity.cpp">Código de ejemplo</a>
</details>

### H - Leaders
<details> 
  <summary>Hints + Solución + código</summary>
  Leer los comentarios dentro del código. Para hacer la lectura más ordenada, partir leyendo desde el main. El código está <strong>MUY</strong> comentado. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/97E_Leaders.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```
