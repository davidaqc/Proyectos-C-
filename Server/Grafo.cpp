#include <iostream>
#include <list>
#include <queue>
#define INFINITO 10000000

using namespace std;

class Grafo
{
private:
    int V; // numero de vertices

    // Puntero a un array que contiene la matriz de adyacencia.
    list<pair<int, int> > * adj;

public:

    // construtor
    Grafo(int V)
    {
        this->V = V; // asigna el numero de vertices

        /*
        Crea las listas, donde cada lista es una
        lista de pares, donde cada par
        está formado por el vértice y el peso
        */
        adj = new list<pair<int, int> >[V];
    }

    // agrega un arista al grafo de v1 a v2
    void addAresta(int v1, int v2, int custo)
    {
        adj[v1].push_back(make_pair(v2, custo));
    }

    // algoritmo de Dijkstra
    int dijkstra(int orig, int dest)
    {
        // vector de distancias
        int dist[V];

        /*
        El vector visitado se usa si el vértice ya
        se ha expandido (visitado), no se expanda más
        */
        int visitados[V];

        // fila de prioridades del par (distancia, vértice)
        priority_queue < pair<int, int>,
                       vector<pair<int, int> >, greater<pair<int, int> > > pq;

        // comienza la distancia y el vector visitado
        for(int i = 0; i < V; i++)
        {
            dist[i] = INFINITO;
            visitados[i] = false;
        }

        // la distancia de origen a origen es 0
        dist[orig] = 0;

        // inserta una fila
        pq.push(make_pair(dist[orig], orig));

        // loop del algoritmo
        while(!pq.empty())
        {
            pair<int, int> p = pq.top(); // extrae el par de la parte superior
            int u = p.second; // obtiene un vertice del par
            pq.pop(); // remover una fila

            // verifica que el vértice no se ha expandido
            if(visitados[u] == false)
            {
                // marca como visitado
                visitados[u] = true;

                list<pair<int, int> >::iterator it;

                // recorre los vértices adyacentes "v" de "u"
                for(it = adj[u].begin(); it != adj[u].end(); it++)
                {
                    // obtiene el vértice adyacente y el peso del arista
                    int v = it->first;
                    int custo_aresta = it->second;

                    // relajación (u, v)
                    if(dist[v] > (dist[u] + custo_aresta))
                    {
                        // actuaaliza la distancia de "v" e inserta una fila
                        dist[v] = dist[u] + custo_aresta;
                        pq.push(make_pair(dist[v], v));
                    }
                }
            }
        }

        // devuelve la distancia mínima al destino
        return dist[dest];
    }
};
