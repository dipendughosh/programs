#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void generateRandomAdjMatrix(int **&adjMatrix, int V, bool parallel, bool loop) {
    

    srand(time(0)); // Seed the random number generator with current time

    // Generate random adjacency matrix
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
    int V = 5; // Number of vertices
    int **adjMatrix;

    // cout<<"Enter number of vertices - ";
    // cin>>V;

    adjMatrix = new int*[V];
    for (int i = 0; i < V; ++i) {
        adjMatrix[i] = new int[V];
    }

    // Graph contains parallel edges and loops
    generateRandomAdjMatrix(adjMatrix, V, true, true);
    printAdjMatrix(adjMatrix, V);
    // Graph contains no parallel edges but contains loops
    generateRandomAdjMatrix(adjMatrix, V, false, true);
    printAdjMatrix(adjMatrix, V);
    // Graph contains parallel edges but does not contain loops
    generateRandomAdjMatrix(adjMatrix, V, true, false);
    printAdjMatrix(adjMatrix, V);
    // Graph does not contains parallel edges or loops
    generateRandomAdjMatrix(adjMatrix, V, false, false);
    printAdjMatrix(adjMatrix, V);

    // Free dynamically allocated memory
    for (int i = 0; i < V; ++i) {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    return 0;
}
