// FindPairsThreeHandshakes_BFS.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Graph.h"

int main()
{
    setlocale(LC_ALL, "");

    Graph g;    // Создаем граф социальных связей

    // Пример из задания:
    // Олег - Никита - Настя - Ваня - Женя
    g.addPerson("Олег");
    g.addPerson("Никита");
    g.addPerson("Настя");
    g.addPerson("Ваня");
    g.addPerson("Женя");

    // Добавляем знакомства между людьми (ребра)
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 4);

    g.findPairsThreeHandshakes();

    return 0;
}
