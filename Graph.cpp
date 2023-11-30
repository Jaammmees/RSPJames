#include <iostream>
#include <vector>
#include <list>

class Graph {
    int V; // Number of vertices
    std::vector<std::list<int>> adj; // Adjacency list

public:
    Graph(int V) : V(V), adj(V) {}

    // Function to add an edge
    void addEdge(int v, int w) {
        adj[v].push_back(w); // Add w to v’s list.
        adj[w].push_back(v); // Since the graph is undirected
    }

    // Function to print the adjacency list
    void printGraph() {
        for (int v = 0; v < V; ++v) {
            std::cout << "Adjacency list of vertex " << v << ": ";
            for (auto x : adj[v]) {
                std::cout << x << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create a graph given in the above diagram
    Graph g(4);  // 4 vertices
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.printGraph();

    return 0;
}
