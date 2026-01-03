#include "Graph.h"
#include <iostream>
#include <queue>

// Добавление человека
void Graph::addPerson(const std::string& name)
{
    names.push_back(name);
    adj.push_back(std::vector<int>());
}

// Добавление знакомства
void Graph::addEdge(int a, int b)
{
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