---
title: contest 8 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```

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
  Si tomamos un camino simple entre S y T y todas las aristas en este camino son aristas de corte, entonces este camino es el unico camino simple entre S y T.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Como dicen los hints, la solucion para cada query (S,T) consiste en encontrar un camino simple entre S y T y luego revisar que todas las aristas utilizadas sean aristas de corte. Para realizar esto eficientemente se puede utilizar binary lifting.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest8/D_Hedge_Mazes.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```
