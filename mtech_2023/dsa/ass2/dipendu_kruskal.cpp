/*
README:
    The graph is represented with vertices from 0 to the
    number of vertices entered by the user and the edges
    with weights as entered by the user.
    The minimum spanning tree is calculated from the
    weight of each adge as per the input.
    Input:
        Number of vertices(2 to 999).
        Weights of each edge(0 to 999) in an adjacency matrix
        taken as an input from user. Enter the weights
        corresponding to all edges from a vertex separated
        by blank spaces. The range of weight is 0 to 999
        where 0 means there is no edge between the two vertices.
    Output:
        The minimum spanning tree. Edges(2 vertex pair) and their weights
        Total minimum spanning tree weight.
*/

#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

// Class representing a Graph
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
    // Parent array for union-find operations
    int *parent;

    // Function to create edge list from adjacency matrix
    void createAdjacencyList()
    {
        int weight;

        // Populate the edge list with the edge weights
        for (int row = 0; row < V; ++row)
        {
            for (int col = 0; col < V; ++col)
            {
                weight = adjMatrix[row][col];
                // If the weight is entered as 0 set it to INT_MAX
                if (weight == 0)
                {
                    weight = INT_MAX;
                }

                // Store an edge weight with its vertices
                int src;
                int dst;
                src = row;
                dst = col;
                edges[E][0] = src;
                edges[E][1] = dst;
                edges[E][2] = weight;
                E++;
            }
        }

        // Sort edges based on weight in increasing order
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

    // Find operation for union-find algorithm
    int find(int i)
    {
        // If i is the parent of itself
        if (i == parent[i])
            return i;
        else
            // Else if i is not the parent of itself
            // Then i is not the representative of his set,
            // so we recursively call Find on its parent
            return find(parent[i]);
    }

    // Union operation for union-find algorithm
    void Union(int u, int v)
    {
        parent[u] = parent[v];
    }

public:
    // Constructor to initialize the graph
    Graph(int vertices)
    {
        V = vertices;
        E = 0;
        ME = V - 1;

        adjMatrix = new int *[V];
        edges = new int *[V * V];
        mst = new int *[V - 1];
        parent = new int[V];

        // Create the adjacency matrix to store the weights of each vertex
        for (int loop = 0; loop < V; ++loop)
        {
            adjMatrix[loop] = new int[V];
        }

        // Create the edge list to store the weights of each edge
        for (int loop = 0; loop < V * V; ++loop)
        {
            edges[loop] = new int[3];
        }

        // Create the mst list to store the mst
        for (int loop = 0; loop < ME; ++loop)
        {
            mst[loop] = new int[3];
        }

        // Create the parent list for each vertex
        for (int loop = 0; loop < V; loop++)
        {
            parent[loop] = loop;
        }
    }

    // Function to get the adjacency matrix from user
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
                cout << "Weight of edges from Vertex " << row + 1 << " : ";
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
        // Create the adjacency list from the adjacency matrix entered
        createAdjacencyList();
    }

    // Function to find Minimum Spanning Tree using Kruskal's algorithm
    void kruskalMST()
    {
        // Using the Find and Union methods to find the minimum spanning tree
        for (int loop = 0, e = 0; loop < E && e < ME; loop++)
        {
            int u = edges[loop][0];
            int v = edges[loop][1];
            int w = edges[loop][2];

            int x = find(u);
            int y = find(v);

            if (x != y)
            {
                mst[e][0] = u;
                mst[e][1] = v;
                mst[e][2] = w;
                // Check for disjoint graphs
                if (w == INT_MAX)
                {
                    cout << "Disjoint graphs detected which is not supported!!" << endl;
                    exit(0);
                }
                e++;
                Union(x, y);
            }
        }
    }

    // Function to print the adjacency matrix
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

    // Function to print the Minimum Spanning Tree
    void printMst()
    {
        int totalWeight = 0;
        cout << "Minimum Spanning Tree (MST)" << endl;
        for (int e = 0; e < ME; e++)
        {
            cout << "Edge " << e + 1 << " : "
                 << mst[e][0] + 1 << " - "
                 << mst[e][1] + 1 << " : "
                 << mst[e][2] << endl;
            totalWeight = totalWeight + mst[e][2];
        }
        cout << "Total minumum weight of the Minimum Spanning Tree is : " << totalWeight << endl;
    }

    // Destructor to release dynamically allocated memory
    ~Graph()
    {
        for (int row = 0; row < V; ++row)
        {
            delete[] adjMatrix[row];
        }
        delete[] adjMatrix;

        for (int loop = 0; loop < V * V; loop++)
        {
            delete[] edges[loop];
        }
        delete[] edges;

        for (int loop = 0; loop < V - 1; loop++)
        {
            delete[] mst[loop];
        }
        delete[] mst;
    }
};

// Main function
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

    // Create a Graph object with specified number of vertices
    Graph g(V);
    // Get the adjacency matrix from the user
    g.getAdjacencyMatrix();
    // Print the adjacency matrix
    g.printAdjMatrix();
    // Find the Minimum Spanning Tree using Kruskal's algorithm
    g.kruskalMST();
    // Print the Minimum Spanning Tree
    g.printMst();

    return 0;
}
