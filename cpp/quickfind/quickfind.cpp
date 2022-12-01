// Implementacion del algoritmo QuickFind para resolver la conectividad de los elementos de un array.
#include <iostream>
#define SIZE 10

void Inicializar(int* array);
void Mostrar(int* array);
void Conectar(int* array, int num1, int num2); // Modifica todos los elementos iguales a array[num1] por array[num2]
bool Conectados(int* array, int num1, int num2);
void Pruebas(int* array);

int main() {
    int nums[SIZE];
    Inicializar(nums);
    Pruebas(nums);

    return 0;
}

void Inicializar(int* array)
{
    for(int i = 0; i < SIZE; i++)
        array[i] = i;
}

void Mostrar(int* array)
{
    for(int i = 0; i < SIZE; i++)
        std::cout<<array[i]<<" ";
    std::cout<<std::endl;
}

void Conectar(int* array, int num1, int num2)
{
    const int AUX = array[num1]; // Para poder modificar los elementos que fueron previamente conectados a otros.
    if(!Conectados(array, num1, num2))
        for(int i = 0; i < SIZE; i++)
        {
            if(array[i] == AUX)
                array[i] = array[num2];
        }
}

bool Conectados(int* array, int num1, int num2)
{
    return array[num1] == array[num2];
}

void Pruebas(int* array)
{
    std::cout<<"Inicializando:"<<std::endl;
    Mostrar(array);
    std::cout<<std::endl;
    std::cout<<"Conectando indice 4 y 3:"<<std::endl;
    Conectar(array, 4, 3);
    Mostrar(array);
    std::cout<<std::endl;
    std::cout<<"Conectando indice 3 y 8:"<<std::endl;
    Conectar(array, 3, 8);
    Mostrar(array);
    std::cout<<std::endl;
    std::cout<<"Conectando indice 6 y 5:"<<std::endl;
    Conectar(array, 6, 5);
    Mostrar(array);
    std::cout<<std::endl;
    std::cout<<"Conectando indice 9 y 4:"<<std::endl;
    Conectar(array, 9, 4);
    Mostrar(array);
    std::cout<<std::endl;
    std::cout<<"Conectando indice 2 y 1:"<<std::endl;
    Conectar(array, 2, 1);
    Mostrar(array);
}