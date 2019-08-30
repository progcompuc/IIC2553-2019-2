---
title: contest 4 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 4](../contests#contest-4) > ```{{page.title}}```

### A - TROY Query
<details> 
  <summary>Hint 1</summary>
  Dada una celda (x,y), si yo quiero <strong>mantener</strong> el signo de la celda necesito:
  <ol>
    <li>multiplicar la fila <strong>x</strong> y la columna <strong>y</strong> por -1 ambas una cantidad <strong>PAR</strong> de veces, o bien</li>
    <li>multiplicar la fila <strong>x</strong> y la columna <strong>y</strong> por -1 ambas una cantidad <strong>IMPAR</strong> de veces</li>
  </ol>
  De igual manera, si yo quiero <strong>invertir</strong> el signo de la celda necesito:
  <ol>
    <li>multiplicar por -1 la fila <strong>x</strong> una cantidad <strong>PAR</strong> y la columna <strong>y</strong> una cantidad <strong>IMPAR</strong>, o bien</li>
    <li>multiplicar por -1 la fila <strong>x</strong> una cantidad <strong>IMPAR</strong> y la columna <strong>y</strong> una cantidad <strong>PAR</strong></li>
  </ol>
</details>
<details> 
  <summary>Hint 2</summary>
  Por cada fila y por cada columna hay 2 posibilidades, mulplicarla por -1 ya sea una cantidad <strong>PAR</strong> o bien una cantidad <strong>IMPAR</strong> de veces. Cada vez que nos dan información sobre una celda (x,y), esto tiene como efecto que ciertas posibilidades quedan <strong>amarradas</strong> ("si A ocurre entonces B ocurre"). Lo que jamás debería pasar es que las dos posibilidades para una misma fila o columna queden amarradas (una columna no puede ser par e impar simultáneamente, por ejemplo).
</details>
<details> 
  <summary>Solución + código</summary>
  Simplemente usamos un UnionFind para fusionar las posibilidades de las filas y columnas a medida que nos van dando información sobre las celdas. Conceptualmente, si dos posibilidades pertenecen al mismo conjunto significa que ambas posibilidades están amarradas (si una posibilidad ocurre entonces todas las demás posibilidades en el mismo conjunto deben ocurrir también). Si en algún punto se da que una misma fila o columna debe ser par e impar simultáneamente, esto genera una contradicción lógica y por tanto de ahí en adelante ya no se puede. Para lidear con los valores gigantes simplemente los mapeamos a un rango compacto usando por ejemplo un unordered_map. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/gym_100570D_TROYQuery.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 4](../contests#contest-4) > ```{{page.title}}```
