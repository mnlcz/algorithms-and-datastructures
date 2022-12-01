//
// Created by MnLCz on 1/3/2021.
//

#pragma once

// FIFO
struct Queue_List
{
    struct Nodo;
    Nodo* primero;
    Nodo* ultimo;

    Queue_List();
    explicit Queue_List(int primero);
    ~Queue_List();
    void Encolar(int nuevoUltimo);
    void Desencolar();
    void MostrarPrimero() const;
    void MostrarUltimo() const;
};
