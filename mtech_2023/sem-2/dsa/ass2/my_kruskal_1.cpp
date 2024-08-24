/*
README:
    The graph is represented with vertices from 0 to the
    number of vertices entered by the user and the edges
    with weights as entered by the user.
    The minimum spanning tree is calculated from the
    weight of each adge as per the input.
    Input:
        Number of vertices(2 to 999).
        Weights of each edge(0 to 999) in an
        adjacency matrix(which can be taken as an input
        from user or generated on the fly)
    Output:
        The minimum spanning tree.
        Total minimum spanning tree weight.

    kruskalMST():
        Follows the Kruskal's Algorithm and uses find(parent, i)
        and union(parent, rank, x, y) to generate the minimum
        spanning tree.
    find(parent, i):
        Adjusts the parent of i
    union(parent, rank, x, y):
        Generates the union of the componets of the partition.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <string.h>
#include <limits>
#include <cctype>

using namespace std;

#define USER_INPUT false

class Graph
{
private:
    // Number of vertices
    int V;
    // Number of edges
    int E;
    // Number of MST edges
    int ME;
    // Adjacency Matrix
    int **adjMatrix;
    // Matrix to store edges
    int **edges;
    // Minimum Spanning Tree
    int **mst;

    void createAdjacencyList()
    {
        // Populate the edge list with the edge weights
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (adjMatrix[i][j] != 0)
                {
                    int S;
                    int D;

                    S = i;
                    D = j;
                    if (S > D)
                    {
                        S = j;
                        D = i;
                    }
                    edges[E][0] = S;
                    edges[E][1] = D;
                    edges[E][2] = adjMatrix[i][j];
                    E++;
                }
            }
        }

        // Sort edges based on weight
        heapSort(edges, E);
    }

    // Function to heapify a subtree rooted at index
    void heapify(int **arr, int n, int i)
    {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l][2] > arr[largest][2])
            largest = l;

        if (r < n && arr[r][2] > arr[largest][2])
            largest = r;

        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to perform the sort on the edges based on the weughts
    void heapSort(int **arr, int n)
    {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    // Swap 2 edges
    void swap(int *&a, int *&b)
    {
        int *temp = a;
        a = b;
        b = temp;
    }

    // Find/adjust the parent of a vertex
    int find(int parent[], int i)
    {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    // Union the partitions of the components
    void Union(int parent[], int rank[], int x, int y)
    {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else
        {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

public:
    // Initialize the number of vertices, edges, adjacency matrix
    Graph(int vertices)
    {
        V = vertices;
        E = 0;
        ME = V - 1;

        adjMatrix = new int *[V];
        edges = new int *[V * V];
        mst = new int *[V - 1];

        for (int i = 0; i < V; ++i)
        {
            adjMatrix[i] = new int[V];
        }

        // Create the edge list along with their weights
        for (int i = 0; i < V * V; ++i)
        {
            edges[i] = new int[3];
        }

        // Create the mst list along with their weights
        for (int i = 0; i < ME; ++i)
        {
            mst[i] = new int[3];
        }
    }

    // Generate a random adjacecny matrix on the number of vertices provided
    void generateRandomAdjMatrix(bool parallel = false, bool loop = false)
    {

        srand(time(0));

        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                if (parallel && loop)
                {
                    adjMatrix[i][j] = rand() % 1000;
                }
                if (parallel && !loop)
                {
                    if (i == j)
                    {
                        adjMatrix[i][j] = 0;
                    }
                    else
                    {
                        adjMatrix[i][j] = rand() % 1000;
                    }
                }
                if (!parallel && loop)
                {
                    adjMatrix[i][j] = adjMatrix[j][i] = rand() % 1000;
                }
                if (!parallel && !loop)
                {
                    if (i == j)
                    {
                        adjMatrix[i][j] = 0;
                    }
                    else
                    {
                        adjMatrix[i][j] = adjMatrix[j][i] = rand() % 1000;
                    }
                }
            }
        }
        createAdjacencyList();
    }

    void getAdjacencyMatrix()
    {
        // Take input from user in int format one edge at a time
        // cout << "Enter the adjacency matrix weights(0 to 999):" << endl;
        // for (int i = 0; i < V; ++i)
        // {
        //     for (int j = 0; j < V; ++j)
        //     {
        //         while (true)
        //         {
        //             cout << "Weight of edge (" << i << "," << j << "): ";
        //             cin >> adjMatrix[i][j];
        //             if (adjMatrix[i][j] < 0 || adjMatrix[i][j] > 999)
        //             {
        //                 cout << "Enter again" << endl;
        //             }
        //             else
        //             {
        //                 break;
        //             }
        //         }
        //     }
        // }
        // Take input from user in string format for all edges from a vetex
        cout << "Enter the adjacency matrix weights(0 to 999):" << endl;
        string inputString;
        string eachInput;
        getline(cin, inputString);
        for (int i = 0; i < V; i++)
        {
            while (true)
            {
                int j = 0;
                int weight = 0;
                int len = 0;
                cout << "Weight of edges from Vertex " << i + 1 << " : ";
                getline(cin, inputString);
                istringstream iss(inputString);
                while (getline(iss, eachInput, ' '))
                {
                    if (eachInput.length() == 0)
                    {
                        continue;
                    }
                    len++;
                    if (j == V)
                    {
                        break;
                    }
                    weight = stoi(eachInput);
                    if (weight < 0 || weight > 999)
                    {
                        cout << "Enter again" << endl;
                        j = 0;
                        break;
                    }
                    adjMatrix[i][j] = weight;
                    j++;
                }
                if (j == V || j == len)
                {
                    break;
                }
            }
        }
        createAdjacencyList();
    }

    // Call the helper functions to create the minimum spanning tree
    void kruskalMST()
    {
        int parent[V];
        int rank[V];
        for (int i = 0; i < V; i++)
        {
            parent[i] = i;
            rank[i] = 0;
        }

        for (int i = 0, e = 0; i < E && e < ME; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y)
            {
                mst[e][0] = u;
                mst[e][1] = v;
                mst[e][2] = w;
                e++;
                Union(parent, rank, x, y);
            }
        }
    }

    // Print the adjacency matrix
    void printAdjMatrix()
    {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; ++i)
        {
            for (int j = 0; j < V; ++j)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void printMst()
    {
        int totalWeight = 0;
        cout << "Minimum Spanning Tree (MST)" << endl;
        for (int e = 0; e < ME; e++)
        {
            cout << "Edge " << e + 1 << " : " << mst[e][0] << " - " << mst[e][1] << " : " << mst[e][2] << endl;
            totalWeight = totalWeight + mst[e][2];
        }
        cout << "Total minumum weight of the Minimum Spanning Tree is : " << totalWeight << endl;
    }

    ~Graph()
    {
        for (int i = 0; i < V; ++i)
        {
            delete[] adjMatrix[i];
        }
        delete[] adjMatrix;

        for (int i = 0; i < V * V; i++)
        {
            delete[] edges[i];
        }
        delete[] edges;

        for (int j = 0; j < V - 1; j++)
        {
            delete[] mst[j];
        }
        delete[] mst;
    }
};

int main()
{
    int V = 5;

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

#if USER_INPUT
    Graph g(V);
    g.getAdjacencyMatrix();
    g.printAdjMatrix();
    g.kruskalMST();
    g.printMst();
#else
    // Generate random matrix
    // Graph contains parallel edges and loops
    Graph g1(V);
    g1.generateRandomAdjMatrix(true, true);
    g1.printAdjMatrix();
    g1.kruskalMST();
    g1.printMst();
    // Graph contains no parallel edges but contains loops
    Graph g2(V);
    g2.generateRandomAdjMatrix(false, true);
    g2.printAdjMatrix();
    g2.kruskalMST();
    g2.printMst();
    // Graph contains parallel edges but does not contain loops
    Graph g3(V);
    g3.generateRandomAdjMatrix(true, false);
    g3.printAdjMatrix();
    g3.kruskalMST();
    g3.printMst();
    // Graph does not contains parallel edges or loops
    Graph g4(V);
    g4.generateRandomAdjMatrix(false, false);
    g4.printAdjMatrix();
    g4.kruskalMST();
    g4.printMst();
#endif

    return 0;
}
