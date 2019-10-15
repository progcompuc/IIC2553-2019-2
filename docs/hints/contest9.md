---
title: contest 9 - hints y códigos de ejemplo
---

[Index](../index) > [Contests](../contests) > [Contest 9](../contests#contest-9) > ```{{page.title}}```

### D - Game of Matchings

<details> 
  <summary>Hint</summary>   
  Si intentamos hacer un match en el string S a partir del i-esimo caracter, y logramos hacer match de j caracteres antes de fallar, entonces no necesitamos volver a la posicion (i+1) y hacer el match todo de nuevo. Podemos aprovechar la estructura del patron y el hecho que hicimos match de j caracteres para hacerlo mas eficiente.
</details>
<details> 
  <summary>Hint 2</summary>   
  Hay que modificar KMP de alguna manera para poder contar los matches en tiempo lineal.
</details>
<details> 
  <summary>Solución + código</summary>
  <p>La solucion consiste en utilizar KMP, pero en lugar de hacer match revisando que los caracteres del patron y string sean iguales, lo que hay que hacer es:</p>

  <ol>
    <li>Leer un caracter del string</li>
    <li>Si el caracter no tiene asignado un numero, entonces revisar que el numero que toca leer en el patron no haya aparecido antes</li>
    <li>Si el caracter si tiene asignado un numero, entonces revisar que el numero que toca leer en el patron sea este mismo numero</li>
  </ol>

  <p>Si lo anterior se cumple, avanzar el match. Si no, entonces retroceder en el patron.</p>

  <p>Para revisar si un caracter tiene asignado un numero, basta computar para cada posicion i el indice de la aparicion anterior del caracter. Por ejemplo,
  para s=aabb computariamos el arreglo prev(s)=[-1,0,-1,2], donde -1 significa que no hemos visto ese caracter antes. Luego si estamos leyendo el caracter i-esimo del string s y lo queremos hacer match con el j-esimo numero del patron p, lo que hay que revisar es 
  </p>
  <ol>
    <li>Si i - prev(s)[i] > j, entonces hay que revisar que prev(p)[j]==-1</li>
    <li>En otro caso, hay que revisar que p[j - (i - prev(s)[i])] == p[j]</li>
  </ol>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest9/D_game_of_matchings.cpp">Código de ejemplo</a>
</details>

### F - Diccionario Portuñol

<details> 
  <summary>Hint</summary>
  <p>
  Que estructura de datos se puede utilizar para enumerar/contar todos los prefijos de un conjunto de strings sin repeticiones?
  </p><p>
  Podemos utilizar esta misma estructura para enumerar/contar los sufijos de un conjunto de strings.
  </p>
</details>
  <summary>Hint 2</summary>
  <p>
  Si tenemos A prefijos de palabras en portugues (sin repeticiones) y B sufijos de palabras en español, entonces tenemos A\*B palabras en portuñol <strong>menos</strong> las palabras que estamos contando dos veces.
  </p><p>
  Por ejemplo, si tenemos la palabra en portugues aabb y la palabra en español cab entonces estamos contando la palabra a+ab y la palabra aa+b, que son la misma palabra. Como contar la cantidad de palabras que estamos contando dos veces? Si tenemos esto, entonces estamos listos: basta descontar esta cantidad de A\*B.
  </p>
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Si contamos una palabra dos veces, es porque hay un prefijo de largo mayor a 1 de una palabra en portugues que termina en un caracter c y un sufijo de largo mayor a 1 de una palabra en español que empieza en ese mismo caracter c.
  </p><p>
  Por ejemplo, si tenemos un prefijo qwe y un sufijo ert, entonces vamos a contar qw+ert y qwe+rt.
  </p><p>
  Por lo tanto, por cada caracter c, hay que sumar la cantidad de prefijos de largo mayor a 1 en portugues que terminan en c y la cantidad de sufijos de largo mayor a 1 en español que empiezan con c, y descontar el producto del contador.
  </p><p>
  En otras palabras, hay que computar A\*B-sum_c((\# prefijos que terminan en c)*(\# sufijos que empiezan con c)), donde A y B estan definidos en el hint 2.
  </p><p>
  Para poder contar estas cosas de manera eficiente se pueden utilizar tries.
  </p><p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest9/F_diccionario_portunol.cpp">Código de ejemplo</a>
  </p>
</details>


### H - Marblecoin

<details> 
  <summary>Hint</summary>
  Podemos ver los marbles que sacamos como un numero en base 365. Si queremos minimizar este numero, es mas importante minimizar los digitos mas significativos.
</details>
<details>
  <summary>Hint 2</summary>
  <p>
  Si un dia los topes de los stacks son todos distintos, entonces podemos codiciosamente sacar el marble de menor valor, y esta decision es optima.
  </p><p>
  Si el minimo valor se repite en varios stacks, tambien existe un criterio que nos permite sacar un marble codiciosamente y armar una solucion optima. Cual es este criterio?
  </p>
</details>
<details>
  <summary>Hint 3</summary>
  <p>
  El criterio optimo es siempre sacar un marble del stack lexicograficamente menor, con la excepcion de que si un stack es prefijo de otro, entonces preferimos el stack mas grande.
  </p><p>
  Una manera de ver esto es: tenemos que sacar un marble de valor minimo. De entre los stacks que tienen este valor minimo en el tope, queremos sacar del stack que tiene valores mas pequenos a continuacion de este marble.
  </p>
  <p>Para poder elegir el stack lexicograficamente menor sin tener que preocuparse del tamaño de los stacks, podemos agregar un marble de valor infinito en la base de cada stack. Como elegir eficientemente el stack lexicograficamente menor en cada paso?</p>
</details>
<details> 
  <summary>Solución + código</summary>
  <p>
  Lo que podemos hacer es concatenar todos los stacks, separandolos por un valor mayor a cualquier marble (por ejemplo, el valor 301). Sea C esta concatenacion de los stacks, y sean s_1,s_2,...,s_n las posiciones de inicio de cada stack en C. Luego computemos el suffix array de C.
  </p>
  <p>
  El menor stack lexicograficamente es el stack i tal que rank[s_i] es minimo. Para poder calcular el minimo eficientemente lo que podemos hacer es mantener un heap que inicialmente llenamos con pares (rank[s_i], s_i).
  </p>
  <p>
  Luego mientras el heap no este vacio hay que sacar el minimo par (rank[idx], idx) del heap, agregar C[idx] al conjunto de marbles que hemos sacado, y luego agregar (rank[idx+1],idx+1) a la priority queue si C[idx+1]!=301 (que indicaria que acabamos este stack).
  </p>
  <p>
  Una vez que sacamos todos los marbles solo queda computar la cantidad de impuestos que hay que pagar.
  </p>
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest9/H_marblecoin.cpp">Código de ejemplo</a>
  </p>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 9](../contests#contest-9) > ```{{page.title}}```
