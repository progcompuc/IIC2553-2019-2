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


### D - Weird Points
<details>

  <summary>Hint 1</summary>

  Si procesamos los puntos en orden segun su coordenada x y los vamos ingresando a una estructura de datos, al procesar un punto p=(x_i, y_i) podemos determinar cuantos puntos son dominados por p si somos capaces de contar cuantos puntos de los que ya hemos procesado tienen y <= y_i. ¿Que estructura nos permite contar esto?

</details>
<details>

  <summary>Solución + código</summary>

  Primero hay que ordenar los puntos segun su coordenada x segun dice el Hint 1. Luego hay varias elecciones de estructuras de datos que nos permite contar cuantos puntos existen menor a un cierto y_i de manera eficiente. Lo mas simple es usar una policy based data structure (<a href="https://www.geeksforgeeks.org/ordered-set-gnu-c-pbds/">link</a>). Con esto la solucion consiste en:
  
  <ol>
    <li>Instanciar el ordered_set como explica el link anterior, pero para pair&lt;int,int&gt;. El primer elemento del par va a ser la coordenada y de cada punto, y el segundo elemento es el indice i del punto en el arreglo ordenado segun coordenada x. Esto es por si hay puntos distintos con la misma coordenada y.</li>
    <li>Iterar sobre los puntos segun su coordenada x. Para el i-esimo punto realizar lo siguiente:
        <ol>
        <li> Ver cuantos elementos en el set son menores a (y_i,i). Sea este numero d0.</li>
        <li> Calcular la dominancia del punto i como abs(2*d0 - n + 1).</li>
        <li> Si la dominancia del punto i es mayor o igual a k, es un Wierd Point.</li>
        <li> Ingresar el par (y_i,i) al ordered_set.</li>
        </ol>
    </li>
  </ol>

  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest2/D_WeirdPoints.cpp">Codigo de ejemplo</a>

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
