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

using namespace std;

#define USER_INPUT true

class Graph {
private:
    // Number of vertices
    int V;
    // Matrix to store edges
    int **edges;
    //Number of edges
    int E;

public:
    // Initialize the number of vertices, edges, adjacency matrix
    Graph(int vertices, int **adjMatrix) {
        V = vertices;
        E = 0;
        edges = new int*[V*V];

        // Create the edge list along with their weights
        for (int i = 0; i < V*V; ++i) {
            edges[i] = new int[3];
        }
        
        // Populate the edge list with the edge weights
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    int S;
                    int D;

                    S = i;
                    D = j;
                    if (S > D) {
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
    void heapify(int **arr, int n, int i) {
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;

        if (l < n && arr[l][2] > arr[largest][2])
            largest = l;

        if (r < n && arr[r][2] > arr[largest][2])
            largest = r;

        if (largest != i) {
            swap(arr[i], arr[largest]);
            heapify(arr, n, largest);
        }
    }

    // Function to perform the sort on the edges based on the weughts
    void heapSort(int **arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    // Swap 2 edges
    void swap(int *&a, int *&b) {
        int *temp = a;
        a = b;
        b = temp;
    }

    // Find/adjust the parent of a vertex
    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

    // Union the partitions of the components
    void Union(int parent[], int rank[], int x, int y) {
        int xroot = find(parent, x);
        int yroot = find(parent, y);

        if (rank[xroot] < rank[yroot])
            parent[xroot] = yroot;
        else if (rank[xroot] > rank[yroot])
            parent[yroot] = xroot;
        else {
            parent[yroot] = xroot;
            rank[xroot]++;
        }
    }

    // Call the helper functions to create the minimum spanning tree
    void kruskalMST() {
        int parent[V];
        int rank[V];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        int totalWeight = 0;
        cout << "Minimum Spanning Tree (MST)"<<endl;
        for (int i = 0, e = 0; i < E && e < V - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y) {
                e++;
                cout << "Edge " << e << " : " << u << " - " << v << " : " << w << endl;
                totalWeight = totalWeight + w;
                Union(parent, rank, x, y);
            }
        }

        cout << "Total minumum weight of the Minimum Spanning Tree is : " << totalWeight << endl;
    }

    ~Graph() {
        for (int i = 0; i < V*(V-1)/2; ++i) {
            delete[] edges[i];
        }
        delete[] edges;
    }
};

// Generate a random adjacecny matrix on the number of vertices provided
void generateRandomAdjMatrix(int **&adjMatrix, int V, bool parallel=false, bool loop=false) {
    
    srand(time(0));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (parallel && loop) {
                adjMatrix[i][j] = rand() % 10;
            }
            if (parallel && !loop) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j] = rand() % 10;
                }
            }
            if (!parallel && loop) {
                adjMatrix[i][j]=adjMatrix[j][i]=rand() % 10;
            }
            if (!parallel && !loop) {
                if (i == j) {
                    adjMatrix[i][j] = 0;
                }
                else {
                    adjMatrix[i][j]=adjMatrix[j][i]=rand() % 10;
                }
            }
        }
    }
}

// Print the adjacency matrix
void printAdjMatrix(int **adjMatrix, int V) {
    cout << "Random Adjacency Matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int V = 5;

    while (true) {
        cout << "Enter the number of vertices(0 to 999): ";
        cin >> V;
        if ( V < 2 || V > 999) {
            cout << "Enter again" << endl;
        }
        else {
            break;
        }
    }

    int **adjMatrix = new int*[V];
    for (int i = 0; i < V; ++i) {
        adjMatrix[i] = new int[V];
    }

#if USER_INPUT
    // Take input from user
    cout << "Enter the adjacency matrix weights(0 to 999):" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            while (true) {
                cout << "Weight of edge (" << i << "," << j << "): ";
                cin >> adjMatrix[i][j];
                if ( adjMatrix[i][j] < 0 || adjMatrix[i][j] > 999 ) {
                    cout << "Enter again" << endl;
                }
                else {
                    break;
                }
            }
        }
    }

    printAdjMatrix(adjMatrix, V);
    Graph g(V, adjMatrix);
    g.kruskalMST();
#else
    // Generate random matrix
    // Graph contains parallel edges and loops
    generateRandomAdjMatrix(adjMatrix, V, true, true);
    printAdjMatrix(adjMatrix, V);
    Graph g1(V, adjMatrix);
    g1.kruskalMST();
    // Graph contains no parallel edges but contains loops
    generateRandomAdjMatrix(adjMatrix, V, false, true);
    printAdjMatrix(adjMatrix, V);
    Graph g2(V, adjMatrix);
    g2.kruskalMST();
    // Graph contains parallel edges but does not contain loops
    generateRandomAdjMatrix(adjMatrix, V, true, false);
    printAdjMatrix(adjMatrix, V);
    Graph g3(V, adjMatrix);
    g3.kruskalMST();
    // Graph does not contains parallel edges or loops
    generateRandomAdjMatrix(adjMatrix, V, false, false);
    printAdjMatrix(adjMatrix, V);
    Graph g4(V, adjMatrix);
    g4.kruskalMST();
#endif

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
