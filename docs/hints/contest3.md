---
title: contest 3 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 3](../contests#contest-3) > ```{{page.title}}```

### A - GM plants
<details> 
  <summary>Hint</summary>
  No es necesario guardar explicitamente el cubo. Es posible computar las respuestas guardando los updates en cada eje por separado.
</details>
<details> 
  <summary>Hint 2</summary>
  Si tengo una query (x1,y1,z1,x2,y2,z2), y se que en el rango (x1,x2) hay rx posiciones rojas y gx posiciones verdes para el eje x, y similarmente ry, gy, rz, gz para los otros ejes, entonces hay rx * ry * rz + rx * gy * gz + gx * ry * gz + gx * gy * rz posiciones rojas en el cubo. 
  
  ¿Como hacer eficientemente estas modificaciones y queries por rangos?
</details>
<details> 
  <summary>Solución + código</summary>
  Mantener por cada eje un lazy segment tree donde cada nodo guarda la cantidad de posiciones rojas en su rango, y la funcion de update esta modificada para hacer flip de los colores en el rango. Luego las queries de tipo 0,1,2 se reducen a hacer un update en el lazy segment tree correspondiente, mientras que las queries de tipo 3 requieren consultar los arboles y calcular las posiciones rojas segun dice el hint 2.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest3/A_GM_plants.cpp">Código de ejemplo</a>
</details>

### B - K12-Bored of Suffixes and Prefixes
<details> 
  <summary>Hint</summary>   
  Puedes pensar cada letra como una matriz con valores binarios. Ejemplo:

  <pre><code>
    ABC
    ACB
  </code></pre>

  Se traduce en las matrices

  <pre><code>
    1 0 0
    1 0 0

    0 1 0
    0 0 1

    0 0 1
    0 1 0
  </code></pre>
  
  y otras 23 matrices llenas de 0s.
</details>
<details> 
  <summary>Hint2</summary>
  Siguiendo el Hint anterior, el problema se reduce a realizar updates puntuales y sumas acumuladas en estas matrices.
</details>
<details> 
  <summary>Solución + código</summary>
  Mantener 26 fenwick trees 2D (un arbol por cada letra) para poder realizar eficientemente las sumas acumuladas. Los updates se reducen a restar 1 en un fenwick tree y sumar 1 en otro fenwick tree por cada letra del nuevo string. Las queries requieren iterar sobre los fenwick trees calculando sumas acumuladas en el rectangulo pedido.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest3/B_K12_Bored_of_Suffixes_and_Prefixes.cpp">Código de ejemplo</a>
</details>

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

### F - Fundraising
<details> 
  <summary>Hint 1</summary>
  Primero, notar que si 2 o más personas tienen exactamente la misma belleza y riqueza, nos podemos simplificar la vida fusionándolas en una misma persona que dona lo mismo que donaban las personas originales juntas.
</details>
<details> 
  <summary>Hint 2</summary>
  (Lo siguiente asume que ya fusionamos según el hint 1) Si miramos a las personas como puntos en un plano 2D de belleza vs riqueza, notar que cualquier conjunto de invitados válido se ve como una secuencia "escalonada", es decir, un primer invitado con belleza y riqueza mínimos del grupo, un segundo invitado con belleza y riqueza estrictamente mayores al primero, un tercer invitado con belleza y riqueza estrictamente mayores al segundo, y así sucesivamente hasta el último invitado del grupo. Si ponemos un eje de referencia en el invitado i-ésimo del grupo, todos los invitados que lo anteceden viven en el cuadrante III y los invitados que lo suceden viven en el cuadrante I (enumerando los cuadrantes anti-horario).
</details>
<details> 
  <summary>Hint 3</summary>
  Un grupo de invitados de N personas se puede pensar como un grupo de invitados de N-1 personas al que le concatenamos una última persona al final. Más aún, dada una persona X, si yo me pregunto cuál es el conjunto de invitados óptimo en que X es el último invitado, esto se puede pensar recursivamente como encontrar todas las personas Y que viven en el cuadrante III de X (estrictamente inferior en belleza y riqueza) y hacer que X se concatene al final del grupo óptimo del mejor de todos esos Y. Dicho de otra manera, el grupo óptimo para X se pueder armar concatenando X al mejor grupo óptimo de algún Y que viva en el cuadrante III de X. Esto huele a programación dinámica, ¿no?
</details>
<details> 
  <summary>Solución + código</summary>
  Primero, las personas que empatan en belleza y riqueza las fusionamos según el hint 1. Luego, ordenamos las personas de forma creciente en riqueza, y en caso de empate desempatamos de forma <strong>decreciente</strong> en belleza. Luego iteramos por cada persona y calculamos la donación máxima que se puede lograr suponiendo que dicha persona fuese el último invitado del grupo. Para ello lo que hacemos es mantener un fenwick tree "vertical" (quizás esto se puede visualizar mejor como un <i>sweep line</i> vertical) indexado por belleza (estamos asumiendo belleza en el eje vertical) en el cual vamos recordando y actualizando la máxima donación lograda hasta el momento por una persona con cierto nivel de belleza. Así, dada una persona X, si quiero saber su donación óptima, esta está dada por X.donación + ft.query(1, X.belleza - 1), es decir, la donación de X + el máximo entre todos los óptimos de personas Y en el cuadrante III de X. Luego, puedo usar el óptimo recién calculado para la persona X para actualizar el fenwick tree. Y así sucesivamente. Un detalle: los valores numéricos que vienen en el input llegan hasta 10^9, por lo que necesitamos comprimir los números en un rango compacto para que no nos explote la memoria.  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/URI/Fundraising.cpp">Código de ejemplo</a>
</details>

### G - Xenia and Bit Operations
<details> 
  <summary>Hint</summary>
  Un segment tree puede servir.
</details>
<details>
  <summary>Solución + código</summary>
  En verdad el problema es usar un segment tree y al definir los nodos del segment tree tener el cuidado de aplicar el OR o el XOR cuando corresponda.  <a href="https://github.com/PabloMessina/Competitive-Programming-Material/blob/master/Solved%20problems/Codeforces/339D_XeniaAndBitOperations.cpp">Código de ejemplo</a>
</details>



<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 3](../contests#contest-3) > ```{{page.title}}```
