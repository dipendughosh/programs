/*
README:
    The graph is represented with vertices from 0 to the
    number of vertices entered by the user and the edges
    with weights as entered by the user.
    The single shortest path is calculated from the
    weight of each adge as per the input.
    Input:
        Number of vertices(2 to 999).
        Weights of each edge(0 to 999) in an adjacency matrix
        taken as an input from user. Enter the weights
        corresponding to all edges from a vertex separated
        by blank spaces. The range of weight is 0 to 999
        where 0 means there is no edge between the two vertices.
        The source vertex from which the path needs to be calculated.
        It is between 1 and the number of vertices entered.
    Output:
        The Single Shortest Path from the source vertex to all other vertices.
*/

#include <iostream>
#include <sstream>
#include <climits>

using namespace std;

// Class representing a Graph
class Graph
{
    // Number of vertices
    int V;
    // Adjacency Matrix
    int **adjacencyMatrix;
    // Minimum Distance List
    int *distance;
    // Shortest Path list
    bool *shortestPathList;

    // Adjust the adjacency matrix to remove parallel edges and keep the minimum weight
    void adjustMatrix()
    {
        for (int row = 0; row < V; row++)
        {
            for (int col = row; col < V; col++)
            {
                if (adjacencyMatrix[row][col] < adjacencyMatrix[col][row])
                    adjacencyMatrix[col][row] = adjacencyMatrix[row][col];
                else
                    adjacencyMatrix[row][col] = adjacencyMatrix[col][row];
            }
            adjacencyMatrix[row][row] = 0;
        }
    }

    // Find the minimum distance
    int minDistance(int distance[], bool shortestPathList[])
    {
        int min = INT_MAX, min_index;
        for (int v = 0; v < V; v++)
            if (shortestPathList[v] == false && distance[v] <= min)
                min = distance[v], min_index = v;
        return min_index;
    }

    // Check if the graph entered is disjoint or not
    void checkDisjoint()
    {
        // Check for disjoint graphs
        for (int i = 0; i < V; ++i)
        {
            if (distance[i] == INT_MAX)
            {
                cout << "Disjoint graphs detected which is not supported!!" << endl;
                exit(0);
            }
        }
    }

public:
    // Constructor to initialize the graph
    Graph(int vertices)
    {
        V = vertices;
        adjacencyMatrix = new int *[V];
        distance = new int[V];
        shortestPathList = new bool[V];

        // Create the adjacency matrix to store the weights of each vertex
        for (int loop = 0; loop < V; ++loop)
        {
            adjacencyMatrix[loop] = new int[V];
        }
        // Create the distance list to store the minimum distance of each edge
        for (int loop = 0; loop < V; loop++)
        {
            distance[loop] = INT_MAX;
        }
        // Create the shortest path list to store the shortest path of each edge
        for (int loop = 0; loop < V; loop++)
        {
            shortestPathList[loop] = false;
        }
    }

    // Function to get the adjacency matrix from user
    void getAdjacencyMatrix()
    {
        // Take input from user the weights of each edge from one vertex to
        // all other vertices in string format separated by a blank space.
        // Weight will be between 0 to 999 where 0 is for no edge.
        cout << "Enter the adjacency matrix weights between 1 to 999 (0 if no edge exists) : " << endl;
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
                cout << "Weight of edges from Vertex " << (row + 1) << " : ";
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
                    adjacencyMatrix[row][col] = weight;
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

    // Function to print the adjacency matrix
    void printadjacencyMatrix()
    {
        cout << "Adjacency Matrix:\n";
        for (int row = 0; row < V; ++row)
        {
            for (int col = 0; col < V; ++col)
            {
                cout << adjacencyMatrix[row][col] << " ";
            }
            cout << endl;
        }
    }

    // Get the source vertex from the user
    int getSourceVertex()
    {
        int source = INT_MAX;
        while (true)
        {
            cout << "Enter the source vertex between 1 to " << V << " : ";
            cin >> source;
            if (source < 1 || source > V)
            {
                cout << "Enter again" << endl;
            }
            else
            {
                break;
            }
        }
        return (source - 1);
    }

    // Run the actual dijkstra algorithm to find the shortest path
    void getDijkstrasShortestPath(int source)
    {
        distance[source] = 0;

        for (int count = 0; count < V - 1; count++)
        {
            int u = minDistance(distance, shortestPathList);
            shortestPathList[u] = true;

            for (int v = 0; v < V; ++v)
            {
                if (!shortestPathList[v] && adjacencyMatrix[u][v] && distance[u] != INT_MAX && distance[u] + adjacencyMatrix[u][v] < distance[v])
                {
                    distance[v] = distance[u] + adjacencyMatrix[u][v];
                }
            }
        }

        checkDisjoint();
    }

    // Print the Single Shortest Path from the source vertex
    void printDijkstrasShortestPath(int source)
    {
        cout << "Vertex Distance from Source - " << source << endl;
        for (int i = 0; i < V; ++i)
            cout << (i + 1) << "\t\t" << distance[i] << endl;
    }
};

int main()
{
    int V = 5;
    int sourceVertex = 0;

    // Input validation for number of vertices
    while (true)
    {
        cout << "Enter the number of vertices(2 to 999): ";
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

    // Creates a Graph object with the specified number of vertices
    Graph g(V);
    // Gets the adjacency matrix from the user
    g.getAdjacencyMatrix();
    // Print the adjacency matrix
    g.printadjacencyMatrix();
    // Get the source vertex from the user
    sourceVertex = g.getSourceVertex();
    // Find the Single Source Shortest path using Dijkstra's algorithm
    g.getDijkstrasShortestPath(sourceVertex);
    // Print the Single Source Shortest path for each vertex from source
    g.printDijkstrasShortestPath(sourceVertex);

    return 0;
}
