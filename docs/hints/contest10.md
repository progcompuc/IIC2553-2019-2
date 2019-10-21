---
title: contest 10 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 10](../contests#contest-10) > ```{{page.title}}```

### B - Flight Plan Evaluation

<details>
  <summary>Hint 1</summary>
  Dados los límites podemos encontrar todas las intersecciones del vuelo con continentes considerando cada arco esférico del vuelo contra cada arco esférico de cada continente. Así se reduce a saber encontrar la intersección entre 2 arcos esféricos. Para eso notar que esto es equivalente a encontrar las 2 intersecciones entre las 2 circunsferencias que contienen a cada arco respectivamente y luego verificar si alguna de estas 2 intersecciones está contenida en ambos arcos (teniendo cuidado con el caso borde en que ambos arcos pertenecen a la misma circunsferencia, en cuyo caso por enunciado no puede haber intersección).
</details>
<details>
 <summary>Hint 2</summary>
  Para encontrar la intersección de 2 circunsferencias, primero notar que si tengo un arco de circunsferencia que va del punto A al punto B y lo llamamos arco(A,B), entonces arco(A,B) forma parte de la circunsferencia con radio igual al de la esfera, con centro en (0,0,0) y orientada de forma perpendicular al vector normal N = AxB (donde "x" denota producto cruz). Llamemos a esta circunsferencia circ(A,B). Notar que un punto X pertenece a circ(A,B) si y sólo si pertenece a la esfera y el vector que va desde (0,0,0) a X es perpendicular a N(A,B)=AxB. Por lo tanto, si queremos encontrar la intersección entre las circunsferencias circ(A,B) y circ(C,D), debemos encontrar un X en la esfera que sea perpendicular a N(A,B) = AxB y a N(C,D) = CxD. Sólo hay 2 posibles X que satisfacen ambas condiciones: X1 = R * (N(A,B) x N(C,D)) / |N(A,B) x N(C,D)| y X2 = -X1 (donde R es el radio de la esfera). Luego faltaría verificar cuál de estos puntos (X1 o X2 o ninguno) está estrictamente contenido por arco(A,B) y arco(C,D) simultáneamente.
</details>
<details>
 <summary>Hint 3</summary>
  Para verificar si un punto X forma parte de arco(A,B), podemos encontrar el ángulo que hay entre A y B (alpha(A,B)), el ángulo que hay entre A y X (alpha(A,X)), primero chequear alpha(A,X) <= alpha(A,B) y segundo rotar A alpha(A,X) radianes hacia B obteniendo un vector A' y finalmente verificar si A' == X. Para rotar A hacia B alpha(A,X) radianes podemos parametrizar la circunsferencia circ(A,B) con un X(t) donde t es el ángulo de rotación, de tal manera que X(0) == A y X(t) es la ubicación en la circunsferencia circ(A,B) si rotamos el vector A t radianes antihorario entorno a la normal N(A,B) = AxB. ¿Cómo calcular X(t)? Podemos definir X(t) = R * (cos(t) * A_hat + sin(t) * C_hat) donde A_hat es A unitarizado y C_hat es un vector unitario que corresponde a rotar A_hat 90 grados antihorario (C_hat = N(A,B) x A / |N(A,B) x A|).
</details>
<details> 
  <summary>Solución + código</summary>
  Los hints ya revelan muchos detalles, pero básicamente hacemos lo siguiente: por cada arco (A_i, B_i) del vuelo encontramos todos los ángulos de rotación de A_i hacia B_i en los cuales ocurre una intersección (comparamos el arco (A_i, B_i) con cada arco (C_i, D_i) de cada continente, encontramos las intersecciones como se mencionó en los hints y recolectamos los ángulo que habría que rotar A_i para generar esos puntos de intersección). Ordenamos los ángulos de menor a mayor con un sort() e iteramos sobre ellos, además tenemos una variable booleana para ir trackeando si estamos dentro o fuera de un continente, si estamos dentro y pasamos por una intersección ahora estamos fuera, y si estabamos fuera pasamos a estar dentro (recordar que el punto de partida siempre es en continente). La distancia recorrida desde un ángulo alpha_j a un ángulo alpha_(j+1) es (alpha_(j+1) - alpha_j) * R. Cada vez que calculamos la distancia recorrida entre 2 pares consecutivos de ángulos, si ese tramo lo hicimos sobre el océano lo agregamos a nuestra suma total. Para ver detalles de implementación revisar el siguiente <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/kattis/flightplan.cpp">código de ejemplo</a>.
</details>


<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 10](../contests#contest-10) > ```{{page.title}}```
