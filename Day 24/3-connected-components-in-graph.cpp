// Solve the "find connected components in a graph" problem using BFS/DFS.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10  // Maximum number of vertices

// Structure to represent the adjacency list
struct Node {
    int vertex;
    Node* next;
};

// Graph class
class Graph {
    private:
        Node* adj_list[MAX];    // Adjacency list
        bool visited[MAX];      // Visited array

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adj_list[i] = nullptr;
                visited[i] = false;
            }
        }

        // Add an undirected edge
        void add_edge(int src, int dest) {
            // Add edge from src to dest
            Node* new_node = new Node;
            new_node->vertex = dest;
            new_node->next = adj_list[src];
            adj_list[src] = new_node;

            // Add edge from dest to src
            new_node = new Node;
            new_node->vertex = src;
            new_node->next = adj_list[dest];
            adj_list[dest] = new_node;
        }

        // DFS to explore a connected component
        void dfs(int v) {
            visited[v] = true;
            cout << v << " ";

            Node* temp = adj_list[v];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    dfs(temp->vertex);
                }
                temp = temp->next;
            }
        }

        // Function to find and print all connected components
        void connected_components() {
            for (int i = 0; i < MAX; i++) {
                if (!visited[i] && adj_list[i] != nullptr) {    // Check for unvisited vertex
                    cout << "Connected Component: ";
                    dfs(i);     // Explore the component using DFS
                    cout << endl;
                }
            }
        }
};

int main() {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(3, 4);
    g.add_edge(5, 6);
    g.add_edge(7, 8);
    g.add_edge(8, 9);
    cout << "Connected Components in the Graph:" << endl;
    g.connected_components();
    return 0;
}
