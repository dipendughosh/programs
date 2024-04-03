// Kruskal's algorithm in C++

#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include <climits>

using namespace std;

#define edge pair<int, int>

class Graph
{
private:
    vector<pair<int, edge>> graph; // graph
    vector<pair<int, edge>> mst;   // mst
    int *parent;
    int V; // number of vertices/nodes in graph
public:
    Graph()
    {
        int V = 0;
    }
    void setNewGraph(int n)
    {
        int V = n;

        // i 0 1 2 3 4 5
        // parent[i] 0 1 2 3 4 5
        parent = new int[V];

        for (int i = 0; i < V; i++)
            parent[i] = i;

        graph.clear();
        mst.clear();
    }
    void addWeightedEdge(int u, int v, int w)
    {
        graph.push_back(make_pair(w, edge(u, v)));
    }
    int findSet(int i)
    {
        // If i is the parent of itself
        if (i == parent[i])
            return i;
        else
            // Else if i is not the parent of itself
            // Then i is not the representative of his set,
            // so we recursively call Find on its parent
            return findSet(parent[i]);
    }
    void setUnion(int u, int v)
    {
        parent[u] = parent[v];
    }
    void getKruskalMST()
    {
        int i, uRep, vRep;
        sort(graph.begin(), graph.end()); // increasing weight
        for (i = 0; i < graph.size(); i++)
        {
            uRep = findSet(graph[i].second.first);
            vRep = findSet(graph[i].second.second);
            if (uRep != vRep)
            {
                mst.push_back(graph[i]); // add to tree
                setUnion(uRep, vRep);
            }
        }
    }
    void printMST()
    {
        int weight = 0;
        cout << "Edge :"
             << " Weight" << endl;
        for (int i = 0; i < mst.size(); i++)
        {
            cout << mst[i].second.first << " - " << mst[i].second.second << " : "
                 << mst[i].first;
            cout << endl;
            weight += mst[i].first;
        }
        cout << "Minimum cost = " << weight << endl;
    }
    void getAdjacencyList(int V)
    {
        int weight, adjacentVertex, currentVertex = 0;
        string inputString, eachInput;

        getline(cin, inputString); // consume the newline from the previous command

        cout << "Enter the adjacency matrix weights(0 to 999):" << endl;

        while (currentVertex < V)
        {
            while (true)
            {
                adjacentVertex = 0;
                int len = 0;
                cout << "Enter Weight of edges from Vertex " << (currentVertex + 1) << " : ";

                getline(cin, inputString);
                istringstream iss(inputString);
                while (getline(iss, eachInput, ' '))
                {
                    // Skip multiple spaces
                    if (eachInput.length() == 0)
                    {
                        continue;
                    }
                    len++;
                    // If more than V no of entries are provided
                    if (adjacentVertex == V)
                    {
                        break;
                    }
                    weight = stoi(eachInput);
                    if (weight < 0 || weight > 999)
                    {
                        cout << "Enter again" << endl;
                        adjacentVertex = 0;
                        break;
                    }
                    if (weight == 0)
                    {
                        weight = INT_MAX;
                    }
                    addWeightedEdge(currentVertex, adjacentVertex++, weight);
                }
                // If number of adjacent vertices is is reached
                if (adjacentVertex == V || adjacentVertex == len)
                {
                    currentVertex++;
                    break;
                }
            }
        }
        // printPriorityQueue();
    }
    void createNewGraph()
    {
        int n;
        bool input_ok;
        do
        {
            cout << "Please enter the no. of vertices in the graph : ";
            cin >> n;

            if (n >= 100 || n <= 0)
            {
                cout << "Error: Acceptable Vertices range is (1 to 99)\n";
                input_ok = false;
            }
            else
            {
                input_ok = true;
            }
        } while (!input_ok);
        setNewGraph(n);
        getAdjacencyList(n);
    }
};

int main()
{
    Graph g;

    // Enter 1st graph
    g.createNewGraph();
    g.getKruskalMST();
    g.printMST();

    // Enter 2nd graph
    g.createNewGraph();
    g.getKruskalMST();
    g.printMST();

    // Enter 3rd graph
    g.createNewGraph();
    g.getKruskalMST();
    g.printMST();

    // Enter 4th graph
    g.createNewGraph();
    g.getKruskalMST();
    g.printMST();
    return 0;
}