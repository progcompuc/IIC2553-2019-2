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
  Simplemente usamos un UnionFind para fusionar las posibilidades de las filas y columnas a medida que nos van dando información sobre las celdas. Conceptualmente, si dos posibilidades pertenecen al mismo conjunto significa que ambas posibilidades están amarradas (si una posibilidad ocurre entonces todas las demás posibilidades en el mismo conjunto deben ocurrir también). Si en algún punto se da que una misma fila o columna debe ser par e impar simultáneamente, esto genera una contradicción lógica y por tanto de ahí en adelante ya no se puede. Para lidiar con los valores gigantes simplemente los mapeamos a un rango compacto usando por ejemplo un unordered_map. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/gym_100570D_TROYQuery.cpp">Código de ejemplo</a>
</details>

### C - Ball

<details> 
  <summary>Hint</summary>
  Puede ser útil pensar en cada persona como un punto en el plano (beauty, intellect) que ademas tiene un valor asociado (su richness).
</details>
<details> 
  <summary>Hint 2</summary>
  Otra forma de ver si una persona P se suicida es: Sea r_max la riqueza maxima de las personas con beauty e intellect mayores a P. ¿Es r_max mayor a la riqueza de P?

  ¿Como hacer esa consulta por rango de forma eficiente?
</details>
<details> 
<details> 
  <summary>Hint 3</summary>
  Puede ser util hacer sweep line, similar al problema "Fundraising" del contest pasado.
</details>
  <summary>Solución + código</summary>
  <p>
  Ordenar los puntos segun su beauty de derecha a izquierda (e intellect de abajo para arriba si tienen igual beauty). Ademas comprimir el espacio en la dimension intellect.
  </p>
  <p>
  Luego, hacer sweep line sobre los puntos ordenados. Mantener un SegmentTree o FenwickTree que va a guardar el richness de los puntos que ya hemos procesado, y un contador global para contar cuantas personas se suicidan. 
  </p>
  <p>
  Cada vez que procesamos un punto, preguntamos por el maximo en richness de los puntos que tienen un intellect mayor. Si es mayor al intellect del punto que estamos procesando, aumentar el contador global en 1. Luego actualizar el Fenwick Tree o Segment Tree con el punto actual.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest4/C_Ball.cpp">Código de ejemplo</a>
</details>

### D - K-query

<details> 
  <summary>Hint</summary>
  Puede ser util leer todas las queries, ordenarlas de alguna forma, resolverlas en ese orden, y luego responderlas todas al final.
</details>
<details> 
  <summary>Hint 2</summary>
  Tambien es util comenzar con un arreglo "vacio" e ir rellenandolo de alguna forma a medida que respondemos queries.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Sea A un arreglo de 1s y 0s de largo n, inicialmente lleno de 0s. Sea B un arreglo de tuplas de la forma (a_i,i), ordenados decrecientemente segun el primer elemento (a_i). Sea C un arreglo de queries de la forma (i,j,k), ordenadas decrecientemente segun el tercer elemento (k).
  </p>
  <p>
  Para responder una query de la forma (i,j,k), lo que podemos hacer es iterar sobre B mientras a_i sea mayor a k. Por cada elemento (a_i,i) de B, sumarle 1 a A[i]. Luego podemos consultar la suma por rango de A[i:j] para obtener la respuesta.
  </p>
  <p>
  Una vez que respondemos una query (i,j,k), para responder la siguiente query (i',j',k') no necesitamos iterar desde el comienzo de B, sino que podemos continuar desde donde quedamos en la query anterior (porque sabemos que k' es menor a k).
  </p>
  <p>
  Para poder realizar las sumas por rango de manera eficiente hay que usar un SegmentTree o FenwickTree.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest4/D_K_Query.cpp">Código de ejemplo</a>
</details>

### E - D-query
<details> 
  <summary>Hint</summary>
  Piensa en una forma de ordenar las queries, de tal manera que al ir iterando sobre ellas puedas ir actualizando una estructura de datos que te permita contar cuántos números están activos (teniendo cuidado de nunca activar números duplicados simultáneamente).
</details>
<details> 
  <summary>Solución + código</summary>
  Lo que hacemos es ordenar las queries (L,R) de forma creciente en R. Además, creamos un fenwick tree de tamaño N en el cual vamos trackeando con 0s y 1s los números del arreglo actualmente activos (inicialmente partimos con puros 0s, i.e. ningún número activo). Luego vamos iterando sobre las queries (crecientes en R) y para cada query hacemos avanzar un puntero r hasta alcanzar el R actual, y en cada paso activamos el número r-ésimo (sumamos 1 en la posición r-ésima del fenwick tree, indicando que el número r-ésimo está activo), <strong>PERO</strong> si el número r-ésimo ya estaba activo en una posición anterior, lo desactivamos (sumamos -1 en su posición anterior). De esta manera si un número está duplicado, siempre mantenemos activa la posición más a la derecha en la que aparece. Con eso logramos que se cumpla la invariante de que de todos los distintos números dentro del intervalo [1,R] estén activados en sus respectivas posiciones más a la derecha (dentro de [1,R]), y todo el resto está desactivado. Luego, para saber cuántos números distintos hay consultamos al fenwick tree la suma acumulada de 1s en el intervalo [L,R]. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/DQUERY_D-query.cpp">Código de ejemplo</a>
</details>
<details> 
  <summary>Solución Alternativa + código</summary>
  El problema se puede hacer trivialmente también aplicando el <a href="../resources/sqrtdecomp">algoritmo de MO</a>. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/DQUERY_D-query_v2.cpp">Código de ejemplo</a>
</details>


<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 4](../contests#contest-4) > ```{{page.title}}```
