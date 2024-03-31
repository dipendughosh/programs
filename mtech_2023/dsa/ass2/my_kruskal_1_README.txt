README:
    The graph is represented with vertices from 0 to the number of vertices entered by the user and the edges with weights as entered by the user.
    The minimum spanning tree is calculated from the weight of each adge as per the input.
    Input:
        Number of vertices(2 to 999).
        Weights of each edge(0 to 999) in an adjacency matrix(which can be taken as an input from user or generated on the fly)
    Output:
        The minimum spanning tree.
        Total minimum spanning tree weight.

    kruskalMST():
        Follows the Kruskal's Algorithm and uses find(parent, i) and union(parent, rank, x, y) to generate the minimum spanning tree.
    find(parent, i):
        Adjusts the parent of i
    union(parent, rank, x, y):
        Generates the union of the componets of the partition.
	
	How to execute the program?
		On execution the program takes the number of vertices as input from the user.
		For weight of the edges the data can be taken from the user or on generated synthetic random data generated using the function generateRandomAdjMatrix(adjMatrix, V, parallel, loop). The matrix generated can take values for generating an adjacency matrix which may or may not have parallel edges and/or loops depnding on how the flags(parallel and loop) are set. This can be done by setting the value of the macro "USER_INPUT" to "true" to take data from user or "false" to generate the synthetic random data.
		After data is entered/generated the adjacency ,atrix is printed for verification.
		An object of the "Graph" class is created with the number of vertices and the adjacency matrix. In the class the data is converted to an edge-weight list which contains each edge and its weights. This list is then sorted on the weights of the edges ad stored.
		On calling the function kruskalMST() it uses the functions find(parent, u) and Union(parent, rank, x, y) to find the minimum spanning tree as per the Kruskal's Algorithm and also prints the same.		