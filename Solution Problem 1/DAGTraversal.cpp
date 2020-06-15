#include<iostream>
#include <list>
using namespace std;
 
// A directed graph using adjacency list representation
class Graph
{
    int V; // No. of vertices in graph
    list<int> *adj; // Pointer to an array containing adjacency lists
 
    // A recursive function used by printAllPaths()
    void printAllPathsUtil(int , bool [], int [], int &);
 
public:
    Graph(int V); // Constructor
    void addEdge(int u, int v);
    void printAllPaths(int s);
};
 
Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}
 
void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v); // Add v to u’s list.
}
 
// Prints all paths from 'source' to 'destination'
void Graph::printAllPaths(int s)
{
    // Marking all the vertices as not visited
    bool *visited = new bool[V];
 
    // Create an array to store paths
    int *path = new int[V];
    int path_index = 0; // Initialize path[] as empty
 
    // Initialize all vertices as not visited
    for (int i = 0; i < V; i++)
        visited[i] = false;
 
    // Call the recursive helper function to print all paths
    printAllPathsUtil(s,visited, path, path_index);
}
 
// A recursive function to print all paths from 'u' to 'd'.
// visited[] keeping track of vertices in current path.
// path[] stores actual vertices and path_index is current
// index in path[]
void Graph::printAllPathsUtil(int u, bool visited[],
                            int path[], int &path_index)
{
    // Mark the current node and store it in path[]
    visited[u] = true;
    path[path_index] = u;
    path_index++;
 
    // If current vertex is same as destination, then print
    // current path[]
    list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (!visited[*i])
                printAllPathsUtil(*i, visited, path, path_index);
               
    if (adj[u].size() == 0)
    {
        for (int i = 0; i<path_index; i++)
            cout << path[i] << " ";
        cout << endl;
    }
 
    // Remove current vertex from path[] and mark it as unvisited
    path_index--;
    visited[u] = false;
}
 
// Driver/Main program
int main()
{
    // Create a graph given in the problem statement
    Graph g(9);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(1, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 6);
    g.addEdge(3, 7);
    g.addEdge(4, 7);
    g.addEdge(4, 8);
    g.addEdge(5, 8);
 
    int s = 1;
    cout << "Following are all different paths from " << s << endl;
    g.printAllPaths(s);
 
    return 0;
} 