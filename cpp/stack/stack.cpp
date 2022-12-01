//
// Created by MnLCz on 1/3/2021.
//

#include "Stack.h"
#include <iostream>

using std::cout, std::endl;

struct Nodo
{
    int item;
    Nodo* siguiente;
};
Nodo* CrearUltimoNodo(int);
Nodo* CrearNodo(int, Nodo*);
void EliminarNodo(Nodo*);

Stack_List::Stack_List()
{
    this->cima = nullptr;
}

Stack_List::Stack_List(int item)
{
    auto aux = CrearUltimoNodo(item);
    this->cima = aux;
}

Stack_List::~Stack_List()
{
    cout << endl << "Eliminando pila..." << endl;
    Nodo* iterador = this->cima;
    while(iterador != nullptr)
    {
        auto aux = iterador;
        iterador = iterador->siguiente;
        EliminarNodo(aux);
    }
}

// O(1)
void Stack_List::Apilar(int item)
{
    this->cima = CrearNodo(item, this->cima);
}

// O(1)
void Stack_List::Desapilar()
{
    if(!EstaVacio())
    {
        this->cima = this->cima->siguiente;
    }
}

void Stack_List::MostrarCima() const
{
    if(EstaVacio())
    {
        cout << "Stack Vacio" << endl << endl;
        return;
    }
    cout << "CIMA: " << this->cima->item << endl << endl;
}

bool Stack_List::EstaVacio() const
{
    return this->cima == nullptr;
}

// Nodos
Nodo* CrearUltimoNodo(int i)
{
    auto nuevoNodo = new Nodo;
    nuevoNodo->item = i;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}
Nodo* CrearNodo(int i, Nodo* s)
{
    auto nuevoNodo = CrearUltimoNodo(i);
    nuevoNodo->siguiente = s;
    return nuevoNodo;
}
void EliminarNodo(Nodo* n)
{
    delete n;
}