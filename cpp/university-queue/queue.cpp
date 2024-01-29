//
// Created by MnLCz on 1/3/2021.
//

#include "Queue.hpp"
#include <iostream>

using std::cout, std::endl;

// Nodos
struct Queue_List::Nodo
{
    int item;
    Nodo* siguiente;
};

Queue_List::Nodo* CrearUltimoNodo(int item)
{
    auto nuevoNodo = new Queue_List::Nodo;
    nuevoNodo->item = item;
    nuevoNodo->siguiente = nullptr;
    return nuevoNodo;
}

void EliminarNodo(Queue_List::Nodo* nodo)
{
    delete nodo;
}

bool EsUltimo(Queue_List::Nodo* nodo)
{
    return nodo->siguiente == nullptr;
}

Queue_List::Nodo* ObtenerUltimoNodo(Queue_List* cola)
{
    Queue_List::Nodo* iterador = cola->primero;
    while(!EsUltimo(iterador))
    {
        iterador = iterador->siguiente;
    }
    return iterador;
}

// Queue
Queue_List::Queue_List()
{
    this->primero = nullptr;
    this->ultimo = nullptr;
}

Queue_List::Queue_List(int primero)
{
    this->primero = CrearUltimoNodo(primero);
    this->ultimo = ObtenerUltimoNodo(this);
}

Queue_List::~Queue_List()
{
    auto iterador = this->primero;
    while(iterador != nullptr)
    {
        auto aux = iterador;
        iterador = iterador->siguiente;
        EliminarNodo(aux);
    }
}

void Queue_List::Encolar(int nuevoUltimo)
{
    auto ultimoFila = CrearUltimoNodo(nuevoUltimo);
    this->ultimo->siguiente = ultimoFila;
    this->ultimo = ultimoFila;
}

void Queue_List::Desencolar()
{
    auto aux = this->primero;
    this->primero = this->primero->siguiente;
    EliminarNodo(aux);
}

void Queue_List::MostrarPrimero() const
{
    cout << "PRIMERO: " << this->primero->item << endl;
}

void Queue_List::MostrarUltimo() const
{
    cout << "ULTIMO: " << this->ultimo->item << endl;
}
