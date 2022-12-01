# Búsqueda binaria
El algoritmo requiere que la estructura ya se encuentre ordenada, luego mediante una función,
usualmente llamada ___buscar___, se realiza una partición de la estructura, comparando el valor
que se busca (_target_) con el valor que se encuentra en la mitad de esa partición, en caso de ser 
menor se descartan los elementos de la derecha o viceversa. Se continúa particionando hasta que se 
encuentra el elemento buscado o no queda mas rango de búsqueda.

## Implementación
Se utilizan 3 variables auxiliares, _left_, _right_ y _mid_. Las 2 primeras representan, al principio,
el rango desde el indice 0 hasta el final, estas se van actualizando para representar los rangos
acotados debido a las particiones. La variable _mid_ representa el índice de comparación donde se da 
la partición. Primero se verifica que el elemento en el índice _mid_ sea el valor buscado, de no serlo 
se evalúa si es menor o mayor:

### Mayor (_target_ < _mid_)
Los elementos a la derecha del índice _mid_ pueden ser descartados. La variable _right_ actualiza su
valor para apuntar ahora al nuevo límite, el cuál será _mid - 1_, debido a que ya se sabe que en el índice
_mid_ hay un elemento mayor a _target_.

### Menor (_target_ > _mid_)
Se descartan los elementos que estan a la izquierda del índice _mid_. La variable _left_ pasa a valer
_mid + 1_.

### _target_ no está en la estructura
En caso de que no se encuentre _target_ se hace un _return -1_.

## Obtener _mid_
Hay varias fórmulas matemáticas para calcular _mid_, la mas utilizada es: 
__(_left_ + _right_)/2__. Sin embargo, con valores muy grandes, se puede producir un overflow (ver valores posibles de
___int___). <br>
La fórmula que siempre funciona y no produce overflow es: <br>
* __left__ +((__right__ - __left__)/2)