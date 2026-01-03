#include "Graph.h"
#include <iostream>
#include <queue>
#include <algorithm>

// Добавление человека
void Graph::addPerson(const std::string& name)
{
    names.push_back(name);
    adj.push_back(std::vector<int>());
}

// Добавление знакомства
void Graph::addEdge(int a, int b)
{
    // Проверка выхода за пределы массива
    if (a < 0 || b < 0 || a >= size() || b >= size())
    {
        std::cerr << "Ошибка: некорректные индексы вершин\n";
        return;
    }

    // Защита от петли (вершина не соединяется сама с собой)
    if (a == b)
        return;

    // Проверка: если ребро уже существует, ничего не делаем
    if (std::find(adj[a].begin(), adj[a].end(), b) != adj[a].end())
        return;

    // Так как граф неориентированный,
    // добавляем ребро в оба списка смежности
    adj[a].push_back(b);
    adj[b].push_back(a);
}

int Graph::size() const
{
    return names.size();
}

// Основной алгоритм
void Graph::findPairsThreeHandshakes() const
{
    int n = size();

    for (int start = 0; start < n; start++)
    {
        std::vector<int> distance(n, -1);
        std::queue<int> q;

        distance[start] = 0;
        q.push(start);

        while (!q.empty())
        {
            int v = q.front();
            q.pop();

            if (distance[v] == 3)
                continue;

            for (int to : adj[v])
            {
                if (distance[to] == -1)
                {
                    distance[to] = distance[v] + 1;
                    q.push(to);
                }
            }
        }

        for (int i = start + 1; i < n; i++)
        {
            if (distance[i] != -1 && distance[i] <= 3)
            {
                std::cout << names[start]
                    << " знаком с "
                    << names[i]
                    << " через "
                    << distance[i]
                    << " рукопожатия\n";
            }
        }
    }
}