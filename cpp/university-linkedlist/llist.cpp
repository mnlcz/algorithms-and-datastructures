//
// Created by MnLCz on 22/2/2021.
//

#include <iostream>
#include "llist.hpp"
using std::cout, std::endl;

Nodo* CrearNodo(int item, Nodo* siguiente)
{
    auto nuevoNodo = new Nodo;
    nuevoNodo->item = item;
    nuevoNodo->siguiente = siguiente;
    return nuevoNodo;
}

Nodo* CrearUltimoNodo(int item)
{
    return CrearNodo(item, nullptr);
}

void MostrarItem(const Nodo* nodo)
{
    cout << "Item: " << nodo->item << endl;
}

void MostrarItemSiguiente(const Nodo* nodo)
{
    MostrarItem(nodo->siguiente);
}

bool SonIguales(const Nodo* nodo1, const Nodo* nodo2)
{
    return nodo1 == nodo2;
}

void BorrarNodo(Nodo* nodo)
{
    delete nodo;
}

Lista* CrearListaVacia()
{
    auto nuevaLista = new Lista;
    nuevaLista->primero = nullptr;
    return nuevaLista;
}

Lista* CrearLista(Nodo* primero)
{
    auto nuevaLista = new Lista;
    nuevaLista->primero = primero;
    return nuevaLista;
}

bool EstaVacia(const Lista* lista)
{
    return lista->primero == nullptr;
}

Nodo* ObtenerUltimoNodo(Lista* lista)
{
    Nodo* iterador = lista->primero;
    if(EstaVacia(lista))
        return iterador;
    while(iterador->siguiente != nullptr)
    {
        iterador = iterador->siguiente;
    }
    return iterador;
}

void AgregarAlFinal(Lista* lista, Nodo* nodo)
{
    cout << "AGREGANDO A LA LISTA" << endl;
    if(EstaVacia(lista))
    {
        lista->primero = nodo;
    }
    else
    {
        ObtenerUltimoNodo(lista)->siguiente = nodo;
    }
}

void Quitar(Lista* lista, Nodo* nodo) // Quita 1 solo nodo (ver linea 96).
{
    cout << "QUITANDO ITEM: " << nodo->item << endl;
    if(EstaVacia(lista))
    {
        cout << "Lista vacia" << endl;
        return;
    }
    else
    {
        Nodo* iterador = lista->primero;
        Nodo* auxiliar;
        while(iterador != nullptr)
        {
            if(SonIguales(iterador->siguiente, nodo))
            {
                auxiliar = iterador->siguiente;
                iterador->siguiente = iterador->siguiente->siguiente;
                BorrarNodo(auxiliar);
                return;
            }
            iterador = iterador->siguiente;
        }
    }
}

void MostrarLista(const Lista* lista)
{
    cout << "MOSTRANDO LISTA" << endl;
    if(EstaVacia(lista))
    {
        cout << "Lista vacia" << endl;
        return;
    }
    else
    {
        Nodo* iterador = lista->primero;
        while(iterador != nullptr)
        {
            MostrarItem(iterador);
            iterador = iterador->siguiente;
        }
    }
}

void BorrarLista(Lista* lista)
{
    auto iterador = lista->primero;
    while(iterador != nullptr)
    {
        auto aux = iterador;
        iterador = iterador->siguiente;
        BorrarNodo(aux);
    }
    delete lista;
}