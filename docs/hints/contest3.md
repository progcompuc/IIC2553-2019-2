---
title: contest 3 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 3](../contests#contest-3) > ```{{page.title}}```

### C - Matrix Summation
<details> 
  <summary>Hint</summary>
  Problema hello world de Fenwick Tree 2D
</details>
<details> 
  <summary>Solución + código</summary>
  Simplemente usar Fenwick Tree 2D. <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/MATSUM_MatrixSummation.cpp">Código de ejemplo</a>
</details>

### D - Salary Management
<details> 
  <summary>Hint 1</summary>
  Piensa en alguna forma de aplanar la jerarquía de la empresa
</details>
<details> 
  <summary>Hint 2</summary>
  Con la jerarquía aplanada, los mínimos y sumas que piden se pueden ver como mínimos de rangos y sumas de rangos, ¿alguna estructura de datos que pueda servir para eso?
</details>
<details> 
  <summary>Solución + código</summary>
  Aplanamos la jerarquía usando DFS (depth first search), a cada nodo le asignamos como índice el instante en que es visitado por el DFS, partiendo de la raíz (0). Cuando terminamos de explorar todo el subárbol de un nodo u, vemos el índice del último nodo visitado y así obtenemos el rango L[u] - R[u] del nodo u. Además, los salarios los ordenamos según el orden del DFS (para mantener todo consistente), y finalmente hacemos las operaciones que nos piden usando 2 lazy segment trees, uno para RMQ (range minimun query) y otro para RSQ (range sum query). <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/SPOJ/SALMAN_SalaryManagement.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 3](../contests#contest-3) > ```{{page.title}}```
