#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

class Graph
{
    int V;
    int **adjMatrix;
    int *dist;
    bool *sptSet;

public:
    Graph(int vertices)
    {
        V = vertices;
        adjMatrix = new int *[V];
        dist = new int[V];
        sptSet = new bool[V];

        for (int loop = 0; loop < V; ++loop)
        {
            adjMatrix[loop] = new int[V];
        }
        for (int loop = 0; loop < V; loop++)
        {
            dist[loop] = INT_MAX;
        }
        for (int loop = 0; loop < V; loop++)
        {
            sptSet[loop] = false;
        }
    }

    void getAdjacencyMatrix()
    {
        // Take input from user the weights of each edge from one vertex to
        // all other vertices in string format separated by a blank space.
        // Weight will be between 0 to 999 where 0 is for no edge.
        cout << "Enter the adjacency matrix weights(0 to 999):" << endl;
        string inputString;
        string eachInput;
        // Consume the last newline
        getline(cin, inputString);
        for (int row = 0; row < V; row++)
        {
            while (true)
            {
                int col = 0;
                int weight = 0;
                int len = 0;
                // Weight of all vertices from a single vertex
                cout << "Weight of edges from Vertex " << row << " : ";
                getline(cin, inputString);
                istringstream iss(inputString);
                while (getline(iss, eachInput, ' '))
                {
                    if (eachInput.length() == 0)
                    {
                        continue;
                    }
                    len++;
                    if (col == V)
                    {
                        break;
                    }
                    weight = stoi(eachInput);
                    // Re-enter if weight entered is out of range.
                    if (weight < 0 || weight > 999)
                    {
                        cout << "Enter again. Weight " << weight << " entered is out of permissible range 0 to 999" << endl;
                        col = 0;
                        // Break out of the loop to allow for re-entering weight
                        break;
                    }
                    adjMatrix[row][col] = weight;
                    col++;
                }
                // Break the infinite loop if all weights are entered.
                if (col == V || col == len)
                {
                    break;
                }
            }
        }
        adjustMatrix();
    }

    void adjustMatrix()
    {
        for (int row = 0; row < V; row++)
        {
            for (int col = row; col < V; col++)
            {
                if (adjMatrix[row][col] < adjMatrix[col][row])
                    adjMatrix[col][row] = adjMatrix[row][col];
                else
                    adjMatrix[row][col] = adjMatrix[col][row];
            }
            adjMatrix[row][row] = 0;
        }
    }

    int minDistance(int dist[], bool sptSet[])
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (sptSet[v] == false && dist[v] <= min)
                min = dist[v], min_index = v;
        return min_index;
    }

    void shortestPath(int src)
    {
        dist[src] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(dist, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < V; ++v)
            {
                if (!sptSet[v] && adjMatrix[u][v] && dist[u] != INT_MAX && dist[u] + adjMatrix[u][v] < dist[v])
                {
                    dist[v] = dist[u] + adjMatrix[u][v];
                }
            }
        }

        checkDisjoint();
    }

    void checkDisjoint()
    {
        // Check for disjoint graphs
        for (int i = 0; i < V; ++i)
        {
            if (dist[i] == INT_MAX)
            {
                cout << "Disjoint graphs detected which is not supported!!" << endl;
                exit(0);
            }
        }
    }

    void printAdjMatrix()
    {
        cout << "Adjacency Matrix:\n";
        for (int row = 0; row < V; ++row)
        {
            for (int col = 0; col < V; ++col)
            {
                cout << adjMatrix[row][col] << " ";
            }
            cout << endl;
        }
    }

    void printShortestPath()
    {
        printf("Vertex Distance from Source\n");
        for (int i = 0; i < V; ++i)
            printf("%d \t\t %d\n", i, dist[i]);
    }
};

int main()
{
    int V = 5;

    // Input validation for number of vertices
    while (true)
    {
        cout << "Enter the number of vertices(0 to 999): ";
        cin >> V;
        if (V < 2 || V > 999)
        {
            cout << "Enter again" << endl;
        }
        else
        {
            break;
        }
    }

    Graph g(V);
    g.getAdjacencyMatrix();

    g.printAdjMatrix();

    g.shortestPath(0);

    g.printShortestPath();

    return 0;
}
