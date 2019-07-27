---
title: "Información del Curso"
---

# {{page.title}}

## Cálculo de la nota final

- Sea X_temprano = cantidad total de puntos por problemas resueltos entre las 15:30 y las 23:59
- Sea X_tarde = cantidad total de puntos por problemas resueltos pasadas las 23:59
- Sea X_repechaje = cantidad total de puntos por problemas en el contest de repechaje
- Luego, se obtiene X*final = X_temprano + 0.8 * X*tarde + 0.5 * X_repechaje
- Sea E = cantidad mínima de puntos esperados al final del semestre
- Así, se obtiene una nota preliminar
  - Nota_v1 = 1 + 6 \* min(X_final/E, 1)
- Sin embargo, luego se bajará la escala del curso, es decir, si ningún alumno alcanzó el 7, el alumno con mayor nota quedará con 7 (siempre y cuando la escala baje "poco" - i.e. habrá un límite para bajar la escala con el fin de desincentivar posibles conspiraciones).
  - Nota_v2 = aplicar_escala_reducida(Nota_v1)
- Finalmente, se aplicarán las décimas de bonus:
  - Nota_v3 = Nota_v2 + BONUS EXPLICACIÓN PROBLEMA + BONUS RPC + BONUS Codeforces
- Todo lo anterior se encuentra formalizado en el [spreadsheet de notas y asistencia](https://docs.google.com/spreadsheets/d/13NJgv8usjIq8LeWcR_ctjFQHK_Wm9TejJNGIuKvI0Gc/edit?usp=sharing)

## Cómo funciona el curso

### 1) Competencias Semanales

Este curso es 100% práctico. La nota final dependerá de la resolución por parte del alumno de problemas de programación competitiva. Cada semana se publicará un _contest_ (o competencia, en español). Los contests se caracterizan por lo siguiente:

- Se publicarán en [vjudge.net](https://vjudge.net), un sitio web que permite crear competencias utilizando problemas obtenidos de múltiples jueces online, con un scoreboard que se actualiza en tiempo real a medida que los participantes resuelven problemas. Para competir es necesario que te crees una cuenta en [vjudge.net](https://vjudge.net) y posteriormente que te unas con dicha cuenta a los contests a medida que estos vayan siendo publicados. Para facilitarnos el registro de problemas resueltos, te pedimos por favor que registres el **nickname** de tu cuenta en el siguiente [spreadsheet](https://docs.google.com/spreadsheets/d/1FSRolgJukhPfEhVgEwG7SFk91D1FUwVQje0mkaNIGIQ/edit?usp=sharing).

- Casi todas las competencias serán **individuales**, pero hacia el final del semestre habrán 1 o 2 competencias **grupales**.

- En el caso de competencias grupales, les está permitido armar equipos de un máximo de 3 alumn@s. Un detalle: como vjudge.net no permite crear equipos, los integrantes de cada equipo deberán acordar una cuenta en común y registrar dicha cuenta + los nombres de los integrantes en un spreadsheet que se les compartirá oportunamente.

- En general los contests serán temáticos. Es decir, cada contest estará compuesto por problemas que se resuelven utilizando estrategias pertenecientes a una categoría o tema común (ej. fuerza bruta, geometría, grafos, strings, etc.). El tema del contest se avisará con anticipación junto con una recomendación de material de estudio que los alumnos podrán revisar antes de la clase.

- El primer módulo de cada clase (14:00 - 15:30) será de cátedra. La idea es revisar contenidos relevantes para el contest antes de que este comience. Esto significa revisar la teoría, ver códigos de ejemplo y quizá explicar la solución de algún problema introductorio que aparecerá en el contest.

- A partir del segundo módulo (15:30 en adelante) comenzará el contest. La idea es que el segundo y tercer módulo de la clase (15:30 - 18:30) los alumnos trabajen en sus computadores programando. Por esto se recomienda que cada uno traiga su laptop a la clase. Si no tienes laptop, por favor avisa al staff del curso con anticipación para poder coordinar laptops de repuesto.

- Salvo en contest grupales, **cada alumn@ debe programar su propia solución**. Sin embargo, está permitido, y es más **te animamos** a que discutas ideas con tus compañeros y compañeras si es que te sientes complicad@ con algún problema que no sabes cómo resolver. Es más, si alguien quiere pasar a la pizarra ya sea a explicar o guiar una discusión de un problema, es **súper bienvenido**. Además, tanto el profesor como el ayudante estaremos disponibles toda la clase para que nos hagas consultas si lo necesitas.

- Los problemas de cada contest tendrán diferentes niveles de dificultad, y por lo tanto serás premiad@ con más o menos puntos según la dificultad de los problemas que resuelvas. Por ej. un problema fácil te podría dar 1 punto, mientras que un problema muy difícil te podría dar más de 4 o 5 puntos. Estos puntajes se mantendrán intencionalmente ocultos hasta el final de la clase :)

  - UPDATE: regalado (1), fácil (2), medio-fácil (3), medio (4), medio-difícil (5), difícil (6), muy difícil (7), **demasiado** difícil (8 o más)

- En general los contests tendrán una duración de un poco más de una semana (9 o 10 días), lo cual implica que durante los últimos días habrá algo de traslapo con el contest de la siguiente semana. No obstante, con el fin de que se acostumbren a programar contra reloj, habrá una penalización por resolver problemas pasado un cierto horario. En concreto, cada problema resuelto entre las 15:30 y las 23:59 del día que comenzó el contest proporcionará su puntaje original. En cambio, problemas que se resuelvan pasadas las 23:59 serán penalizados por un factor de 0.8. Es decir, _puntaje_tarde_ = _puntaje_original_ \* 0.8

- Al final del semestre habrá un contest de repechaje. Este contest tendrá muchos problemas y durará hasta la fecha del cierre de notas. Sin embargo, el puntaje de estos problemas será penalizado con un factor de 0.5. Es decir, _puntaje_repechaje_ = _puntaje_original_ \* 0.5. Por lo tanto, el consejo obvio es resolver problemas periódicamente de forma responsable, para no tener que trabajar el doble en el contest de repechaje :)

### 2) Asistencia

El curso es con **asistencia reprobatoria**. Los alumnos que registren una asistencia al final del semestre inferior a 65% **reprobarán el curso**. Cada clase se pasará lista. Aunque no es necesario que te quedes los 3 módulos, con que vengas al menos a 1 módulo es suficiente para quedar presente.

### 3) Bonuses

Además de las competencias semanales, existen varias formas de obtener décimas de bonus que se sumarán directamente a tu nota final:

- **BONUS EXPLICACIÓN PROBLEMA** (individual): Este bonus permite obtener hasta un máximo de 2 décimas por explicación. ¿En qué consiste? Cada semana, junto a cada contest se publicará un google doc que será compartido con todos (todos podrán editarlo). La idea de estos google docs es que todos (alumnos y staff) colaboremos en la redacción de explicaciones de las soluciones de los problemas, armando una suerte de "wikipedia" de soluciones. ¿Cómo obtener este bonus?:

  - Para obtener este bonus el primer requisito es haber resuelto el problema que quieres explicar (no puedes explicar un problema que no has resuelto todavía).
  - El segundo requisito es redactar la explicación **ANTES** que se acabe el contest (para que le sirva a alguien)
  - Debes redactar una explicación entendible de la estrategia con la cual resolviste el problema. Puedes agregar dibujos, imágenes, fórmulas, ecuaciones, etc. si crees que hará tu explicación más fácil de entender.
  - Opcionalmente, puedes incluir un link al código de tu solución (por ej. hosteado en un repositorio público en GitHub) al final de tu explicación.
  - Por supueto, no olvides incluir tu nombre y apellido al final de tu explicación para que todos sepan quién lo escribió.
  - Cuando tengas tu explicación lista, debes avisar por medio del Telegram del curso que has agregado una explicación.
  - La cantidad de décimas que recibas dependerá de varios factores, a saber:
    - La dificultad del problema resuelto
    - La calidad de la explicación (lo ideal: una explicación muy clara pero concisa)
    - Si tu explicación es realmente un aporte (en caso de que alguien más ya haya escrito una explicación para el mismo problema)
    - Si tu explicación incluye un análisis / estimación de la complejidad computacional del algoritmo (por qué no da [TLE](https://www.geeksforgeeks.org/overcome-time-limit-exceedtle/)?)
    - Si es que agregaste un link a tu solución en código
      - la calidad de este código (si está ordenado, si está razonablemente comentado)
      - **Si tu código está en C++ (preferiblemente C++11)**. Sabemos que la mayoría se siente más comoda programando en Python, por lo que programar en C++ requiere (al menos al principio) un esfuerzo adicional. Aquellas personas que escriban su código en C++ y lo compartan al final de su explicación tendrán más décimas, como recompensa a su esfuerzo ([tips para programar en C++/C++11](#tips-para-implementación-con-c))

- **BONUS RPC** (grupal): Cada cierto tiempo la [Red de Programación Competitiva (RPC)](http://redprogramacioncompetitiva.com/) organiza competencias de entrenamiento. El calendario y registro para estas competencias se encuentran acá: http://registro.redprogramacioncompetitiva.com/contests, y los scoreboards de las competencias pasadas se pueden encontrar acá: http://redprogramacioncompetitiva.com/Contest. Nótese que se trata de un **bonus grupal**, por ende para obtener este bonus deben:

  - Registrarse en una competencia en grupos de 2 o 3 alumn@s.
  - Participar en la competencia
  - Mandar una foto del grupo con todos sus integrantes juntos frente a un mismo computador (sí, la idea es que se junten físicamente usando un solo computador, [como en este ejemplo](https://youtu.be/BZo23gj9ksk?t=4237)).
  - Al terminar la competencia, deben mandar el link al scoreboard final de la competencia RPC en que participaron.
  - El bonus se calculará como 6 _ (X/N) décimas, donde X = problemas resueltos por el grupo, N = problemas resueltos por el equipo que quedó en primer lugar. Las 6 _ (X/N) décimas obtenidas se sumarán directamente a su nota final.

* **BONUS Codeforces** (individual): Cada cierto tiempo [Codeforces](http://codeforces.com/) organiza competencias individuales, que generalmente duran alrededor de 2 horas, con problemas de diferentes niveles de dificultad. Si se registran en Codeforces, el sitio les debería ir avisando por email sobre las próximas competencias. O bien, pueden revisar el [siguiente calendario](http://codeforces.com/calendar). Para obtener este bonus deben:
  - Registrarse en Codeforces.
  - Participar en una competencia.
  - Al final de la competencia avisarnos en qué competencia participaron (por ej. mandar el link a su perfil de Codeforces).
  - El bonus se calculará como 4 _ (X/N) décimas, donde X = problemas resueltos por el alumno, N = problemas resueltos por la persona que quedó en primer lugar. Las 4 _ (X/N) décimas obtenidas se sumarán directamente a su nota final.

[Index](../index)
