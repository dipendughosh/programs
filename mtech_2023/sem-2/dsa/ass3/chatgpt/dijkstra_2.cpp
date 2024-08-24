#include <iostream>
#include <utility>

#define INF 0x3f3f3f3f

using namespace std;

typedef pair<int, int> iPair;

class Graph
{
    int V;
    int **adj;

public:
    Graph(int V)
    {
        this->V = V;
        adj = new int *[V];
        for (int i = 0; i < V; ++i)
        {
            adj[i] = new int[V];
            for (int j = 0; j < V; ++j)
                adj[i][j] = 0;
        }
    }

    void addEdge(int u, int v, int w)
    {
        adj[u][v] = w;
        adj[v][u] = w;
    }

    int minDistance(int dist[], bool sptSet[])
    {
        int min = INF, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }

    void shortestPath(int src)
    {
        int dist[V];
        bool sptSet[V];

        for (int i = 0; i < V; i++)
            dist[i] = INF, sptSet[i] = false;

        dist[src] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < V; ++v)
            {
                if (!sptSet[v] && adj[u][v] && dist[u] != INF && dist[u] + adj[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adj[u][v];
                }
            }
        }

        printf("Vertex Distance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
};

int main()
{
    int V = 9;
    Graph g(V);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);

    g.shortestPath(0);

    return 0;
}
