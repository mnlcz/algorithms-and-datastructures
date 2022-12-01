//
// Created by MnLCz on 22/2/2021.
//

#pragma once

struct Nodo
{
    int item;
    Nodo* siguiente;
};

Nodo* CrearNodo(int item, Nodo* siguiente);
Nodo* CrearUltimoNodo(int item);
void MostrarItem(const Nodo* nodo);
void MostrarItemSiguiente(const Nodo* nodo);
bool SonIguales(const Nodo* nodo1, const Nodo* nodo2);
void BorrarNodo(Nodo* nodo);

struct Lista
{
    Nodo* primero;
};

Lista* CrearListaVacia();
Lista* CrearLista(Nodo* primero);
bool EstaVacia(const Lista* lista);
Nodo* ObtenerUltimoNodo(Lista* lista);
void AgregarAlFinal(Lista* lista, Nodo* nodo);
void Quitar(Lista* lista, Nodo* nodo);
void MostrarLista(const Lista* lista);
void BorrarLista(Lista* lista);