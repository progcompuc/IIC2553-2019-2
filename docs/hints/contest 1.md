## Contest 1
### A - Valeriy and Deque
<details> 
  <summary>Hint</summary>
   Ve qué pasa cuando hacer mas de n operaciones.
</details>

<details> 
   <summary>Solución</summary>
   Simula n operaciones. 
   Después de las n operaciones, el más grande queda al comienzo y los demás van rotando.
   Para los mj <= n velo en la simulacion, y para los mj > n calcula modularmente cual va a ser el elemento en ser sacado.
</details>

### B - Roadwork
<details> 
  <summary>Hint</summary>
   En vez de pensar "esta persona, en qué obra se detiene?" puedes pensar "esta obra, a qué personas detiene?".
</details>

<details> 
  <summary>Hint</summary>
   Si una obra detiene a alguien, las obras a la derecha ya no lo pueden detener. Ve las obras en ese orden.
</details>

<details> 
  <summary>Hint</summary>
   Si tienes a las personas ordenadas por tiempo de salida, puedes saber en log n quién va a ser la primera persona en ser bloqueada por cierta obra.
</details>

<details> 
  <summary>Solución</summary>
   Ordena las obras e itera por ellas de izquierda a derecha. 
   Para cada obra, calcula qué tiempos de salida van a ser bloqueados, osea S-X <= D < T-X, y elimina a estas personas de la lista.
   La posicion de la obra es el punto de llegada para estas personas.
   Esto se puede hacer en (#personas x log n) con un multiset.
   El tiempo total es O(N + Q log Q).
</details>

### C - Two Teams

### D - Memory Management

### E - Largest Rectangle in a Histogram

### F - Weird Function

### G - Criss-cross Cables

### H - equeue

### I - Cat Party (Hard Edition)

### J - Back to the Future

### K - Who is The Boss

### L - Daunting device

