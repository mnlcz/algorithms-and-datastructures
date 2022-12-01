//
// Created by MnLCz on 1/3/2021.
//

#pragma once

struct Stack_List
{
    struct Nodo* cima;

    Stack_List();
    ~Stack_List();
    explicit Stack_List(int item);
    void MostrarCima() const;
    void Apilar(int item);
    void Desapilar();
    bool EstaVacio() const;
};