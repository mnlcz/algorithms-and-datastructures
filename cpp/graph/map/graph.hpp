// TODO: reimplementar usando una clase Grafo

#pragma once
#include <unordered_map>
#include <vector>
#include <functional>
#include <stack>
#include <queue>

template<typename T_NODO>
using GRAFO = std::unordered_map<T_NODO, std::vector<T_NODO>>;
using std::stack;
using std::queue;

template<typename T_NODO>
void DFS(GRAFO<T_NODO>& grafo, T_NODO primerElemento, std::function<void(T_NODO)> operacion)
{
    stack<T_NODO> stack;
    stack.push(primerElemento);
    while (!stack.empty())
    {
        T_NODO current = stack.top();
        stack.pop();
        operacion(current);
        for(auto& vecino : grafo[current])
            stack.push(vecino);
    }
}

template<typename T_NODO>
void BFS(GRAFO<T_NODO>& grafo, T_NODO primerElemento, std::function<void(T_NODO)> operacion)
{
    queue<T_NODO> queue;
    queue.push(primerElemento);
    while(!queue.empty())
    {
        T_NODO current = queue.front();
        queue.pop();
        operacion(current);
        for(auto& vecino : grafo[current])
            queue.push(vecino);
    }
}