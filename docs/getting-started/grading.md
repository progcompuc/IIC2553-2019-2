---
title: "Cálculo de la Nota Final"
---

[Index](../index) > ```{{page.title}}```

# {{page.title}}

- Sea P_i = total puntos por problemas resueltos **dentro** de plazo en el contest i-ésimo
- Sea T_i = total puntos por problemas resueltos **fuera** de plazo en el contest i-ésimo
- Sea M_i = puntaje mínimo esperado para el contest i-ésimo
- Sea A la asistencia promedio del alumno

Así, se calcula:
- D_i = max(M_i - P_i, 0) = deuda de puntaje del contest i-ésimo
- E_i = max(P_i - M_i, 0) + T_i = excedente de puntaje del contest i-ésimo
- X_i = 1 - D_i/M_i = fracción completada del mínimo esperado para el contest i-ésimo
- D = suma de todos los D_i
- E = suma de todos los E_i
- X = promedio de todos los X_i

Así, E se usa para reducir la deuda D de la siguiente manera:
- D' = max(D - E*0.33, 0)
- X' = X + (1-X) * (D-D')/D

Así, se obtiene una nota preliminar
- Nota_v1 = (1 + 6 * X') * 0.75 + (1 + 6 * A) * 0.25

Sin embargo, luego se bajará la escala del curso, es decir, si ningún alumno alcanzó el 7, el alumno con mayor nota quedará con 7 (siempre y cuando la escala baje "poco" - i.e. habrá un límite para bajar la escala con el fin de prevenir "hacks" al sistema).
- Nota_v2 = aplicar_escala_reducida(Nota_v1)

Luego se calcula las décimas de bonus efectivas:
- B = (BEP + BRPC + BCI + BR) * ((Nota_v1 - 1)/6)

Finalmente, la nota final está dada por:
- Nota_v3 = Nota_v2 + B

Todo lo anterior se encuentra formalizado en el spreadsheet de notas y asistencia (**TODO: AGREGAR SPREADSHEET**)

[Index](../index) > ```{{page.title}}```