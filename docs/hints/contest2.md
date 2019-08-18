---
title: contest 2 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 2](../contests#contest-2) > ```{{page.title}}```

### A - Vladik and Entertaining Flags
<details> 
  <summary>Hint 1</summary>
  Piensa en una forma de responder la query(L,R) descomponiendo el rango [L,R] en sub-rangos y combinando respuestas precomputadas para dichos sub-rangos.
</details>
<details>
  <summary>Hint 2</summary>
  Supón que tienes la respuesta precomputada para el rango [L,M] y para el rango [M+1, R]. ¿Cómo obtener la respuesta para el rango [L, R]? Notar que las componentes de ambos rangos se fusionan si es que en el punto de contacto entre las columnas M y M+1 hay valores adyacentes iguales. Cualquier componente que no toque la interfaz no se puede fusionar.
</details>
<details> 
  <summary>Solución + código</summary>
  Básicamente usamos ya sea un Sparse Table o un Segment Tree, los rangos los modelamos con un Struct/Class que guarde los índices L y R del rango, un par de arreglos int left[10] e int right[10] que guarden los ids de las componentes a las que pertenecen los valores de las columnas L y R respectivamente, y un contador de la cantidad de componentes del rango. Para fusionar los rangos A = [L, M] y B = [M+1, R], podemos iterar sincronizadamente sobre las columnas M y M+1 y detectar cuando los valores matrix[M][i] == matrix[M+1][i], en cuyo caso las componentes A.right[i] y B.left[i] deben fusionarse (podemos iterar sobre las 4 columnas A.left, A.right, B.left y B.right y actualizar los ids). Usando Sparse Table la complejidad es O(N^2*M*log(M)) por construir el sparse table y O(Q*N^2*log(M)) por responder las queries. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/811E_VladikAndEntertainingFlags_v2.cpp
">Código de ejemplo</a>
</details>

### B - Update the array

<details>
  <summary>Hint 1</summary>
  ¿Hay alguna manera de rapidamente almacenar la informacion de los updates de manera que al preguntar por la suma acumulada en el rango [0, i], obtengamos el valor final del elemento i-esimo? Si tuvieramos eso podriamos primero almacenar rapidamente la informacion de todos los updates, y luego calcular todas las sumas acumuladas en tiempo lineal.
</details>

<details>
  <summary>Hint 2</summary>
  ¿Que sucede si para un update de la forma (l,r,val), sumamos val a arr[l] y restamos val a arr[r+1]?
</details>

<details>
  <summary>Solucion + codigo</summary>
  Seguir los dos hints anteriores: Para cada update de la forma (l,r,val) hay que sumarle val a arr[l] y restarselo a arr[r+1]. Luego hay que iterar sobre el arreglo calculando las sumas acumuladas. Para cada query i responder la suma acumulada hasta el indice i. Con esto la solucion es O(n+u+q). 
  
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest2/B_UpdateTheArray.cpp">Codigo de ejemplo</a>
</details>

<details>
  <summary>Solucion Alternativa + codigo</summary>
  Otra solucion conceptualmente mas simple (pero menos eficiente) es utilizar un Lazy Segment Tree. Esta estructura de datos permite en tiempo logaritmico realizar updates y consultas en rangos, que son precisamente las operaciones que necesitamos. La solucion es O(n+u*log(n)+q). 
  
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest2/B_UpdateTheArray_lazyST.cpp">Codigo de ejemplo</a>
</details>

### D - Weird Points
<details>

  <summary>Hint</summary>

  Si procesamos los puntos en orden segun su coordenada <strong>x</strong> y los vamos ingresando a una estructura de datos, al procesar un punto <strong>p=(x_i, y_i)</strong> podemos determinar cuantos puntos son dominados por <strong>p</strong> si somos capaces de contar cuantos puntos de los que ya hemos procesado tienen <strong>y &lt;= y_i</strong>. ¿Que estructura nos permite contar esto?

</details>
<details>

  <summary>Solución + código</summary>

  Primero hay que ordenar los puntos segun su coordenada x segun dice el Hint 1. Luego hay varias elecciones de estructuras de datos que nos permite contar cuantos puntos existen menor a un cierto <strong>y_i</strong> de manera eficiente. Lo mas simple es usar una <a href="https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/">policy based data structure</a>. Con esto la solucion consiste en:
  
  <ol>
    <li>Ordenar los puntos segun su coordenada <strong>x</strong></li>
    <li>Instanciar el <strong>ordered_set</strong> como explica el link anterior, pero para <strong>pair&lt;int,int&gt;</strong>. El primer elemento del par va a ser la coordenada <strong>y</strong> de cada punto, y el segundo elemento es el indice <strong>i</strong> del punto en el arreglo ordenado segun coordenada <strong>x</strong>. Esto es por si hay puntos distintos con la misma coordenada <strong>y</strong>.</li>
    <li>Iterar sobre los puntos segun su coordenada <strong>x</strong>. Para el <strong>i</strong>-esimo punto realizar lo siguiente:
        <ol>
        <li> Ver cuantos elementos en el set son menores a <strong>(y_i,i)</strong>. Sea este numero <strong>d0</strong>.</li>
        <li> Calcular la dominancia del punto <strong>i</strong> como <strong>abs(2*d0 - n + 1)</strong>.</li>
        <li> Si la dominancia del punto <strong>i</strong> es mayor o igual a <strong>k</strong>, es un Wierd Point.</li>
        <li> Ingresar el par <strong>(y_i,i)</strong> al ordered_set.</li>
        </ol>
    </li>
  </ol>

  La solucion es O(n*log(n)).

  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest2/D_WeirdPoints.cpp">Codigo de ejemplo</a>

</details>

### E - Turn Off The TV
<details>
  <summary>Hint 1</summary>
  Es más fácil determinar que TVs <strong>no</strong> son redundantes.
</details>

<details>
  <summary>Hint 2</summary>
  Es posible seguir una estrategia similar al problema B del contest 1: crear "eventos" de encendido/apagado de TVs, ordenarlos por tiempo, y de alguna manera determinar en que tiempos hay solo 1 TV funcionando (lo que hace que esa TV no sea redundante).
</details>

<details>
  <summary>Solución + código</summary>
  Por cada tv, crear un evento de encendido en el tiempo <strong>l</strong> y un evento de apagado en el tiempo <strong>r+1</strong>. Ordenar los eventos por tiempo.
  Luego iterar sobre los eventos, manteniendo un <strong>set</strong> con las TVs encendidas actualmente. Cada vez que cambia el tiempo de un evento a otro (es decir, despues de procesar todos los eventos en el tiempo actual <strong>t</strong>), revisar si hay solo una TV encendida actualmente. Si hay solo 1, entonces esa TV no es redundante.

  De esta manera se pueden identificar todas las TVs no redundantes. Elegir una TV que no este en este conjunto si existe, sino imprimir -1.

  La solucion es O(n*log(n)).

  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest2/D_WeirdPoints.cpp">Codigo de ejemplo</a>
</details>

### F - Gravel
<details>
  <summary>Hint 1</summary>
  Este problema es similar al B - update the array, tenemos updates sobre rangos y consultas puntuales. La diferencia es que acá los updates y consultas pueden estar intercalados.
</details>
<details>
  <summary>Hint 2</summary>
  Al igual que en el problema B - update the array, podemos usar el concepto de <a href="https://www.geeksforgeeks.org/difference-array-range-update-query-o1/">difference array</a>, sin embargo, como acá tenemos updates y consultas intercalados, recalcular un difference array a cada rato daría TLE. ¿Se te ocurre alguna forma de implementar el mismo concepto de difference array pero con una estructura que permita hacer updates y consultas de forma eficiente?
</details>
<details>
  <summary>Solución + código</summary>
  Básicamente usamos un fenwick tree (a.k.a. bit) para simular un difference array dinámico. Cuando nos piden hacer un update por rango, hacemos bit.add(l,k) y bit.add(r+1,-k), y cuando nos hacen una consulta puntual consultamos con bit.psq(p). La complejidad es O(M log N). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codechef/SPREAD_Gravel.cpp">Código de ejemplo</a>
</details>

### G - Youngling Tournament

<details> 
  <summary>Hint 1</summary>
  Notar que la cantidad de ganadores es a lo más log_2(10^12), esto lo podemos notar si codiciosamente tratamos de generar el caso con mayor cantidad de ganadores, que sería con las fuerzas 1, 1, 2, 4, 8, 16, 32, ...
  Quizás podrías aprovechar eso para encontrar a esos poquitos ganadores.
</details>
<details> 
  <summary>Hint 2</summary>
  En este problema tienes un ranking dinámico, en el cual para un instante dado los jugadores tienen ciertas fuerzas y están rankeados de una cierta manera, y en otro instante algunos jugadores tienen fuerzas distintas y por lo tanto el ranking puede cambiar. Si sólo se tratara de mantener un ranking dinámico, eso se puede hacer fácilmente con un set de C++, o incluso con un ordered_set (policy based data structures de C++). El problema es que además te interesa saber la suma acumulada de las fuerzas de una cierta posición a la izquierda. Sabemos que calcular sumas acumuladas es trivial con fenwick tree o segment tree, ¿pero cómo podemos tener un ranking dinámico a la vez? Hay un trucazo muy ingenioso: si tenemos N jugadores y M updates, podemos suponer que tenemos N+M jugadores, y que en cada instante N jugadores están "activados" y M jugadores están "desactivados", entonces procesar un update se reduce a desactivar la versión obsoleta de un jugador y activar su versión nueva.
</details>
<details> 
  <summary>Solución + código</summary>
  Básicamente ponemos en un mismo arreglo los N jugadores iniciales y los M jugadores "actualizados" (un arreglo de largo N+M). Lo ordenamos de menor a mayor. Las N posiciones originales aparecen con sus fuerzas tal cual, mientras que las M posiciones de las queries inicialmente las "desactivamos" asignándoles fuerza = 0. Luego construimos un fenwick tree (o segment tree) sobre el arreglo. De esta manera, cuando consultamos la fuerza acumulada desde el principio hasta una posición i, las posiciones con fuerza = 0 no alteran la suma acumulada. Dado un estado actual del arreglo y del fenwick tree (segment tree) asociado, podemos contar la cantidad de ganadores usando búsqueda binaria. El primer jugador siempre es ganador, de ahí en adelante podemos considerar al jugador i-ésimo como un ancla y buscar el primer jugador j-ésimo a la derecha (j > i) que su fuerza acumulada hasta su posición sea >= al doble de la fuerza acumulada hasta la posición del ancla. Ese jugador se considera como "candidato" a ser ganador. Para confirmar si es ganador, chequeamos si su fuerza es >= a la fuerza acumulada en la posición j-1. Luego consideramos al jugador j-ésimo como nueva ancla y volvemos a hacer búsqueda binaria hacia la derecha, y así sucesivamente hasta que se nos acaba el arreglo. Cada vez que necesitamos consultar la suma acumulada hasta una cierta posición, podemos usar nuestro fenwick/segment tree. Cuando procesamos un update de fuerza, lo que hacemos es setear fuerza = 0 en la posición anterior del jugador, y setear la nueva fuerza en la posición nueva del jugador (esto requiere que en nuestra implementación recordemos las posiciones de los jugadores). La complejidad de esto es O(M*log(max_fuerza)*log(M+N)^2 + M*log(M+N)). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/gym_100960G_YounglingTournament.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 2](../contests#contest-2) > ```{{page.title}}```
