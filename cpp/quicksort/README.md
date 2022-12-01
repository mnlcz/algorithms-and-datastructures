# Quicksort
Dado un array no ordenado, el algoritmo Quicksort se encarga de ordenarlo mediante 2 funciones (Quicksort y Partition).
### Función Partition
En la función partition se selecciona un elemento como ___pivot___, luego se busca el indice dentro del array en el cuál todos los elementos a la derecha sean mayores
al ___pivot___ y los de la izquierda menores. <br> <br>
__Pasos línea por línea:__
1. Se selecciona al ___pivot___, en este caso se optó porque sea el ultimo elemento (puede elegirse cualquiera).
2. Se declara la variable __partitionIndex__, la cual representará el índice a retornar, la misma empieza con el valor 0 y se irá actualizando dentro del ciclo _for_. 
3. Con un ciclo _for_ se recorre el array desde el inicio hasta el anteúltimo elemento (el último es el ___pivot___).
    * Si el elemento en un determinado índice es menor o igual al ___pivot___ se realiza un _swap_ con el elemento en la posición de la variable __partitionIndex__, 
      dicho de otra manera, se "tira a la izquierda" a los valores mas chicos al ___pivot___.
      
### Función Quicksort
1. Se verifica que no sea un array vacío o de 1 elemento.
2. Con el valor que retorna la función _Partition_ se hacen 2 llamadas a _Quicksort_ para los elementos menores y mayores al __pivot__.