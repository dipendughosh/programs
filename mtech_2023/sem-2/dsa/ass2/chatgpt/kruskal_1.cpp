#include <iostream>

using namespace std;

class Graph {
private:
    int V; // Number of vertices
    int **edges; // Matrix to store edges

public:
    Graph(int vertices, int **adjMatrix) {
        V = vertices;
        edges = new int*[V*(V-1)/2];
        for (int i = 0; i < V*(V-1)/2; ++i) {
            edges[i] = new int[3];
        }
        int k = 0;
        for (int i = 0; i < V; ++i) {
            for (int j = i+1; j < V; ++j) {
                if (adjMatrix[i][j] != 0) {
                    edges[k][0] = i;
                    edges[k][1] = j;
                    edges[k][2] = adjMatrix[i][j];
                    k++;
                }
            }
        }

        // Sort edges based on weight
        heapSort(edges, k);
    }

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

    void heapSort(int **arr, int n) {
        for (int i = n / 2 - 1; i >= 0; i--)
            heapify(arr, n, i);

        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            heapify(arr, i, 0);
        }
    }

    void swap(int *&a, int *&b) {
        int *temp = a;
        a = b;
        b = temp;
    }

    int find(int parent[], int i) {
        if (parent[i] == i)
            return i;
        return find(parent, parent[i]);
    }

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

    void kruskalMST() {
        int parent[V];
        int rank[V];
        for (int i = 0; i < V; i++) {
            parent[i] = i;
            rank[i] = 0;
        }

        cout << "Minimum Spanning Tree (MST):\n";
        for (int i = 0, e = 0; i < V*(V-1)/2 && e < V - 1; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            int x = find(parent, u);
            int y = find(parent, v);

            if (x != y) {
                e++;
                cout << u << " - " << v << " : " << w << endl;
                Union(parent, rank, x, y);
            }
        }
    }

    ~Graph() {
        for (int i = 0; i < V*(V-1)/2; ++i) {
            delete[] edges[i];
        }
        delete[] edges;
    }
};

int main() {
    int V;
    cout << "Enter the number of vertices: ";
    cin >> V;

    int **adjMatrix = new int*[V];
    for (int i = 0; i < V; ++i) {
        adjMatrix[i] = new int[V];
    }

    cout << "Enter the adjacency matrix:\n";
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            cin >> adjMatrix[i][j];
        }
    }

    Graph g(V, adjMatrix);
    g.kruskalMST();

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
