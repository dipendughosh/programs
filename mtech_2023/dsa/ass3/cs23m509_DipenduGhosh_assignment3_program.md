README for Assignment 3: Dijkstra Algorithm Implementation:

The program is written in C++. Compiled with g++ in Linux and tested.

The graph is represented with vertices numbered from 1 to the number of vertices entered by the user, with edge weights specified by the user.
The single source shortest path is calculated based on the weights of each edge provided by the user.

    Assumptions:
        There should be atleast 2 vertices for the program to run and a maximum of 999 vertices allowed. If any value provided is outside this boundary the program will ask for valid number of vertices within the range provided.

        The Graph taken as input is undirected, connected and has positive edge weights.
        0 is to be entered for no edges between 2 vertices.

        Input for edge weights are taken for each vertex(per row of the adjacency matrix) in a string format. Each weight is space separated. If less number of weights are entered per row then the last cells of the row will be set to 0.

        The weight boundary has been set between 0 to 999. Where 0 is for no edge and maximum weight will be 999. If any value provided is outside the bounday then program will ask to re-enter the entire row once again since the input is taken row wise and in string format.

    	The source vertex is taken from the userand it should be between 1 and total number of vertices entered.

        If a disconnected graph is given as input then while processing if it is detected then no further processing will be done and the program execution will be stopped.

    How to execute the program:
    	Upon execution, the program prompts the user to input the number of vertices.

        An object 'g' of the Graph class is created.

        For weight of the edges the data needs to be taken from the user using "g.getAdjacencyMatrix()". After the data is taken as input it is validated for multiple edges between same pair of vertices and the minimum edge it taken into consideration andstored in the original adjacencyMatrix itself.

        After the data is entered and converted, the program prints the adjacency matrix for verification using 'g.printadjacencyMatrix()'.

    	After printing the adjacency matrix the source vertex is taken as input from the user using 'g.getSourceVertex()'.

        Upon calling the 'g.getDijkstrasShortestPath(sourceVertex)' function, it finds the shortest path to all vertices from the source vertex using the Dijkstra Algorithm.

        After the Dijkstra Algorithm is applied the Single Shortest Path to all vertices from the source vertex is printed.

    Input:
        Number of vertices(2 to 999).

        Weights for each edge (ranging from 0 to 999) are input by the user in the form of an adjacency matrix. Enter the weights corresponding to all edges from a vertex separated by blank spaces. The range of weight is 0 to 999 where 0 means there is no edge between the two vertices.

    	Source vertex between 1 and the total number of vertices.

    Output:
        The Single Source Shortest Path is printed from the source vertex entered.

    Implementation Logic:
        The Graph class represents an undirected graph and contains private member variables for the number of vertices (V), the adjacency matrix (adjacencyMatrix), the minimum distance list (distance) and the shortest path list (shortestPathList).

    	Private variables :
    		V - Number of vertices

    		adjacencyMatrix - Adjacency matrix

    		distance - shortest Distance list for vertex i from source

    		shortestPathList - Array to store whether the shortest distance from source to i is finalized

    	The Graph class has several private member functions:
    		adjustMatrix(): Create the adjacency matrix after validating multiple edges between same pair of vertices and taking the minimum edge into consideration.

    		minDistance(int distance[], bool shortestPathList[]) : Calculates the minimum distance for vertex i from the source.

    		checkDisjoint(): Check for disjoint graphs.

    	The Graph class also has public member functions:
    		getAdjacencyMatrix(): Takes input for the adjacency matrix from the user and calls adjustMatrix() to create the adjacency matrix.

    		printadjacencyMatrix(): Prints the adjacency matrix.

    		getSourceVertex() : Take user input for the source vertex.

    		getDijkstrasShortestPath(int source) : Implements Dijkstras Single Source Shortest Path algorithm to calculate the minimum distance from source.

    		printDijkstrasShortestPath(int source): Prints the Single Source Shortest path for each vertex from the source.

In the main() function :
Prompts the user to input the number of vertices
Creates a Graph object with the specified number of vertices
Gets the adjacency matrix from the user
Print the adjacency matrix
Get the source vertex from the user and find the Single Source Shortest path using Dijkstra's algorithm
Print the Single Source Shortest path for each vertex from the source

Sample Input :-

    Enter the number of vertices(0 to 999): 9
    Enter the adjacency matrix weights between 1 to 9999 (0 if no edge exists) :
    Weight of edges from Vertex 1 : 0 4 0 0 0 0 0 8 0
    Weight of edges from Vertex 2 : 4 0 8 0 0 0 0 11 0
    Weight of edges from Vertex 3 : 0 8 0 7 0 4 0 0 2
    Weight of edges from Vertex 4 : 0 0 7 0 9 14 0 0 0
    Weight of edges from Vertex 5 : 0 0 0 9 0 10 0 0 0
    Weight of edges from Vertex 6 : 0 0 4 14 10 0 2 0 0
    Weight of edges from Vertex 7 : 0 0 0 0 0 2 0 1 6
    Weight of edges from Vertex 8 : 8 11 0 0 0 0 1 0 7
    Weight of edges from Vertex 9 : 0 0 2 0 0 0 6 7 0

    Enter the source vertex between 1 to 9 : 1

Sample Output :-

    Adjacency Matrix:
    0 4 0 0 0 0 0 8 0
    4 0 8 0 0 0 0 11 0
    0 8 0 7 0 4 0 0 2
    0 0 7 0 9 14 0 0 0
    0 0 0 9 0 10 0 0 0
    0 0 4 14 10 0 2 0 0
    0 0 0 0 0 2 0 1 6
    8 11 0 0 0 0 1 0 7
    0 0 2 0 0 0 6 7 0

    Vertex Distance from Source
    1                0
    2                4
    3                12
    4                19
    5                21
    6                11
    7                9
    8                8
    9                14
