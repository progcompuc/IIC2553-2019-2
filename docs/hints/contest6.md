---
title: contest 6 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 6](../contests#contest-6) > ```{{page.title}}```

### F - New Year Tree

<details> 
  <summary>Hint</summary>
  Hay una manera de mapear nodos a posiciones en un arreglo de manera que todo subarbol sea representado por un subarreglo de este arreglo. Esto es util por que si conseguimos hacer esto, cambiar los colores y contar los colores distintos es equivalente a realizar queries y modificaciones sobre rangos en un arreglo.
</details>
<details> 
  <summary>Hint 2</summary>
  Que estructura nos permite realizar modificaciones y queries sobre rangos en tiempo logaritmico?
</details>
<details> 
  <summary>Hint 3</summary>
  Como solo hay 60 colores, podemos utilizar un entero de 64 bits para representar conjuntos de colores.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Para mapear nodos a posiciones en un arreglo, lo que podemos hacer es un recorrido en pre-orden de los nodos asignando indices crecientes. Luego tenemos arreglos left[n] y right[n], de manera que left[i] es la posicion en el arreglo del nodo i, y left[i]:right[i] es el subarbol que tiene al nodo i como raiz.
</p><p>
  Para pintar el subarbol del nodo i ahora basta pintar el subarreglo left[i]:right[i], y para contar colores solo hay que contar la cantidad de colores distintos en el subarreglo left[i]:right[i]. Para poder realizar estas operaciones de manera eficiente podemos utilizar un Lazy Segment Tree, usando bitmasks para representar los distintos colores en los rangos. Para pintar una celdade color c, le asignamos el valor (1 << c), que representa el conjunto que solo tiene el color c. Para unir dos conjuntos utilizamos bitwise or. Para transformar un conjunto a una respuesta, hay que contar la cantidad de bits prendidos (en c++ se puede hacer con la funcion __builtin_popcountll). 
  </p><p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest6/F_New_year_tree.cpp">Código de ejemplo</a>
  </p>
</details>

### G - Whistle's New Car

<details> 
  <summary>Hint 1</summary>
  Guardemos un contador c[u] para cada nodo u. Sea d(u) el ancestro mas lejano al que podemos llegar desde u con el combustible que nos dan en u. Para cada nodo u realizemos lo siguiente: Aumentemos c[u] en 1, y disminuyamos c[d(u)] en 1. Luego para calcular cuan atractiva es una ciudad, basta sumar c[v] para cada v en el subarbol de u (sin incluir u). Esto funciona porque las ciudades del subarbol que no alcanzan a llegar a u aportan con un 1 y un -1 a la suma, por lo que no se cuentan. Las ciudades que si logran llegar a u aportan solo con un 1.
  
  Como calcular d(u) y como calcular la suma de c[v] en el subarbol de u de manera eficiente?
</details>
<details> 
  <summary>Hint 2</summary>
  Al igual que el problema anterior, es util "aplanar" el arbol, mapeando nodos a posiciones en un arreglo de manera que cada subarbol este representado por un subarreglo consecutivo de ese arreglo.
</details>
<details> 
  <summary>Hint 3</summary>
  Se puede utilizar Binary Lifting para calcular d(u) en tiempo logaritmico.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Para mapear nodos a posiciones en un arreglo, lo que podemos hacer es un recorrido en pre-orden de los nodos asignando indices crecientes. Luego tenemos arreglos left[n] y right[n], de manera que left[i] es la posicion en el arreglo del nodo i, y left[i]:right[i] es el subarbol que tiene al nodo i como raiz.
  </p><p>
  Para calcular d(u) se puede utilizar Binary Lifting, moviendose lo mas posible hacia arriba del arbol mientras la suma acumulada de los costos no sea mayor al combustible con el que se parte.
</p><p>
  Luego, tenemos un arreglo c[n] inicializado con 0's. Para cada nodo u sumamos 1 a c[left[u]] y restamos 1 a c[left[d(u)]].
</p><p>
  Para cada nodo u, calculamos su atractividad como la suma del subarreglo c[left[u]:right[u]]. Esto puede hacerse simplemente con un arreglo de sumas acumuladas (si acc[i]=sum(c[0:i]), entonces sum(c[l:r])=acc[r]-acc[l]).
  </p><p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest6/G_Whistles_new_car.cpp">Código de ejemplo</a>
  </p>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 6](../contests#contest-6) > ```{{page.title}}```
