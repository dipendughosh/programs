README for Assignment 2: Kruskal Algorithm Implementation:

The program is written in C++. Compiled with g++ in Linux and tested.

The graph is represented with vertices numbered from 0 to the number of vertices entered by the user, with edge weights specified by the user.
The minimum spanning tree is calculated based on the weights of each edge provided by the user and also the total weight is calculated.

    Assumptions:
        There should be atleast 2 vertices for the program to run and a maximum of 999 vertices allowed. If any value provided is outside this boundary the program will ask for valid number of vertices within the range provided.

        The Graph taken as input is undirected, connected and has positive edge weights.
        0 is to be entered for no edges between 2 vertices.

        Input for edge weights are taken for each vertex(per row of the adjacency matrix) in a string format. Each weight is space separated. If less number of weights are entered per row then the last cells of the row will be set to 0.

        The weight boundary has been set between 0 to 999. Where 0 is for no edge and maximum weight will be 999. If any value provided is outside the bounday then program will ask to re-enter the entire row once again since the input is taken row wise and in string format.

        If a disconnected graph is given as input then while processing if it is detected then no further processing will be done and the program execution will be stopped.

    How to execute the program:
    	Upon execution, the program prompts the user to input the number of vertices.

        An object 'g' of the Graph class is created.

        For weight of the edges the data needs to be taken from the user using "g.getAdjacencyMatrix()". After the data is taken as input it is converted to an edge-weight list which contains each edge and its weights. This list is then sorted on the weights of the edges and stored.

        After the data is entered, the program prints the adjacency matrix for verification using 'g.printAdjMatrix()'.

        Upon calling the 'kruskalMST()' function, it utilizes the 'find(u)' and 'Union(x, y)' functions to find the minimum spanning tree according to Kruskal's Algorithm.

        After the Kruskal Algorithm is applied the Minimum Spanning Tree is pinted aling with the "Total Minimum Cost" of the tree.

    Input:
        Number of vertices(2 to 999).

        Weights for each edge (ranging from 0 to 999) are input by the user in the form of an adjacency matrix. Enter the weights corresponding to all edges from a vertex separated by blank spaces. The range of weight is 0 to 999 where 0 means there is no edge between the two vertices.

    Output:
        The output includes the edges (represented as pairs of vertices) and their respective weights.

        Additionally, the total weight of the minimum spanning tree is provided as output.

    Implementation Logic:
        The Graph class represents an undirected graph and contains private member variables for the number of vertices (V), the number of edges (E), the number of MST edges (ME), the adjacency matrix (adjMatrix), the edge list (edges), the MST edges list (mst), and an array to track the parent of each vertex (parent).

        The Graph class has several private member functions:

            createAdjacencyList(): Constructs the edge list from the adjacency matrix and sorts the edges based on their weights using heap sort.

            heapify() and heapSort(): Helper functions to perform heapify and heap sort operations.

            find(): Finds the parent of a vertex using the union-find algorithm (path compression).

            Union(): Merges two sets by setting one as the parent of the other.

        The Graph class also has public member functions:

            getAdjacencyMatrix(): Takes input for the adjacency matrix from the user and calls createAdjacencyList() to construct the edge list.

            kruskalMST(): Implements Kruskal's algorithm to find the MST by iterating through sorted edges and applying union-find operations.

            printAdjMatrix(): Prints the adjacency matrix.

            printMst(): Prints the MST edges and their weights and also thetotal minimum cost of the spanning tree.

        In the main() function, the program prompts the user to input the number of vertices (V), creates a Graph object with the specified number of vertices, gets the adjacency matrix from the user, prints the adjacency matrix, finds the MST using Kruskal's algorithm, and finally prints the MST edges and their total weight.
