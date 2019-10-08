---
title: contest 8 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```

### B - Good Travels
<details> 
  <summary>Hint 1</summary>
  Si el equipo llega a la ciudad u, el recorrido optimo siempre va a pasar por todas las ciudades v tales que v es alcanzable desde u y u es alcanzable desde v. Si un recorrido optimo no hiciera esto, siempre podriamos visitar esa ciudad v que nos falto, volver a u, y luego continuar el recorrido, mejorando el optimo.
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

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 8](../contests#contest-8) > ```{{page.title}}```
