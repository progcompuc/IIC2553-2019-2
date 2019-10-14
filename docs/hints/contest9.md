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
  La solucion consiste en utilizar KMP, pero en lugar de hacer match revisando que los caracteres del patron y string sean iguales, lo que hay que hacer es:

  <ul>
    <li>Leer un caracter del string</li>
    <li>Si el caracter no tiene asignado un numero, entonces revisar que el numero que toca leer en el patron no haya aparecido antes</li>
    <li>Si el caracter si tiene asignado un numero, entonces revisar que el numero que toca leer en el patron sea este mismo numero</li>
  </ul>

  Si lo anterior se cumple, avanzar el match. Si no, entonces retroceder en el patron.
  <a href="https://github.com/ProgramacionCompetitivaPUC/IIC2553-2019-2/blob/master/code_samples/contest9/D_game_of_matchings.cpp">Código de ejemplo</a>
</details>

<!-- <details> 
  <summary>Hint</summary>   
</details>
<details> 
  <summary>Solución + código</summary>
  <a href="">Código de ejemplo</a>
</details> -->

[Index](../index) > [Contests](../contests) > [Contest 9](../contests#contest-9) > ```{{page.title}}```
