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
  Básicamente usamos ya sea un Sparse Table o un Segment Tree, los rangos los modelamos con un Struct/Clase que guarde los índices L, R del rango, un par de arreglos int left[10] e int right[10] que guaran los ids de las componentes a las que pertenecen los valores de las columnas L y R respectivamente, y un contador de la cantidad de componentes del rango. Para fusionar los rangos A = [L, M] y B = [M+1, R], podemos iterar sincronizadamente sobre las columnas M y M+1 y detectar cuando los valores matrix[M][i] == matrix[M+1][i], en cuyo caso las componentes A.right[i] y B.left[i] deben fusionarse (podemos iterar sobre las 4 columnas A.left, A.right, B.left y B.right y actualizar los ids). Usando Sparse Table la complejidad es O(N*M*log(M)) por construir el sparse table y O(Q*N*log(M)) por responder las queries. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/811E_VladikAndEntertainingFlags_v2.cpp
">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 2](../contests#contest-2) > ```{{page.title}}```
