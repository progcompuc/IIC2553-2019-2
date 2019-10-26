---
title: contest 11 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 11](../contests#contest-11) > ```{{page.title}}```

### Z - Rotate Columns (hard version)

<details> 
  <summary>Hint</summary>
  Los límites sugieren que la complejidad debe ser O(m·2^n), piensa de qué te sirve ver los subconjuntos de cada columna.
</details>
<details> 
  <summary>Hint</summary>
  Piensa en un DP de espacio O(m·2^n) que solucione el problema pero sin considerar las rotaciones, y ve como añades las rotaciones después.
</details>
<details> 
  <summary>Hint</summary>
  Para cada par (columna, mask) puedes saber qué rotación es la que más le conviene, antes de hacer el dp. 
</details>
<details> 
  <summary>Hint</summary>
  <p>
    Con los hints de arriba vas a poder resolver la versión "fácil" del problema: <a href="https://codeforces.com/problemset/problem/1209/E1">Rotate Columns (Easy Version)</a>
  </p>
  <p>
  Ahora, la solución final va a usar a lo más n columnas. ¿Ves una forma de preprocesar las columnas y saber cuáles no van ser parte de la solución final?
  </p>
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  El DP es sobre los subconjuntos de filas, para cada columna. En la columna c, el DP[c][mask] va a ser el maximo de DP[c-1][mask1] + maxcol(c, mask2), para los pares mask1 y mask2, donde mask1 | mask2 = mask, mask1 & mask2 = 0, y para calcular maxcol(c, mask2) necesitas revisar todas las rotaciones de mask2 y evaluarlas . Esto tiene complejidad O(2^2n · m · n^2) para cada caso, lo que aun no es suficiente.
  </p>
  <p>
  Optimizamos usando el hint 3. Se puede hacer un preproceso sobre los masks y las columnas. Esto mejora la complejidad a O(n^2 · m + 2^2n · m) para cada caso.
  </p>
  <p>
  Finalmente, con el hint 4, sabemos que no hay que ver todas las columnas. Lo que se puede hacer, es ordenar las columnas por su valor máximo, y considerar solo las n primeras. Esto mejora la complejidad a O(n^3 + 2^2n · n) por caso, lo que pasa raspando.
  </p>
  <a href="https://codeforces.com/contest/1209/submission/63502896">Código de ejemplo</a>
</details>
<details> 
  <summary>Extra</summary>
  <p>
  Si usas un lenguaje lento (Java) vas a necesitar un par de optimizaciones extra:</br></br>
  </p>
  <p>
  * Las posibles rotaciones para un bitmask forman una clase de equivalencia. Por ejemplo, para n = 4 las clases son {0000}, {0001, 0010, 0100, 1000}, {0011, 0110, 1100, 1001}, {0101, 1010}, {0111, 1110}, {1111}. El DP no necesitas hacerlo sobre todos los bitmask, sino sobre las clases de equivalencia. Para n = 12, los bitmask posibles son 4096 y las clases son 352, lo que mejora el tiempo en un factor de ~11,6.
  </p>
  <p>
  * Para cada clase, ten preprocesada una lista de masks compatibles. Por ejemplo, si estás en la clase 0101, no vas a poder rellenar los 0s con el mask 0011 ni el 0111, tu lista va a tener {0000, 0001, 0101}, o bien, {0000, 0010, 1000, 1010} para no tener que revisar las rotaciones de nuevo. Haciendo un análisis, se puede ver que esto mejora el factor de (2^2n) a 3^n.
  </p>
</details>


<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 11](../contests#contest-11) > ```{{page.title}}```
