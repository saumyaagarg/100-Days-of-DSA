// Solve the "detect a cycle in an undirected graph" problem using DFS.

#include <iostream>
using namespace std;

#define MAX 5   // Maximum number of vertices in the graph

// Graph represented using Adjacency List
struct Node {
    int vertex;
    Node* next;
};

// Graph class with cycle detection functionality
class Graph {
    private:
        Node* adjList[MAX];     // Adjacency list for the graph

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adjList[i] = nullptr; // Initialize all lists as empty
            }
        }

        // Function to add an edge in the graph (undirected)
        void add_edge(int src, int dest) {
            // Add edge from src to dest
            Node* newNode = new Node;
            newNode->vertex = dest;
            newNode->next = adjList[src];
            adjList[src] = newNode;

            // Add edge from dest to src (for undirected graph)
            newNode = new Node;
            newNode->vertex = src;
            newNode->next = adjList[dest];
            adjList[dest] = newNode;
        }

        // Helper function to perform DFS and detect cycles
        bool dfs(int current, bool visited[MAX], bool parent[MAX]) {
            visited[current] = true;

            // Explore all the neighbors of the current vertex
            Node* temp = adjList[current];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {
                    // Recur for unvisited neighbors
                    if (dfs(temp->vertex, visited, parent)) {
                        return true;
                    }
                }
                // If an adjacent vertex is visited and not the parent, a cycle is found
                else if (visited[temp->vertex] && parent[current] != temp->vertex) {
                    return true;
                }
                temp = temp->next;
            }
            return false;
        }

        // Function to detect a cycle in the graph
        bool detect_cycle() {
            bool visited[MAX] = {false}; // Array to keep track of visited vertices
            bool parent[MAX] = {false};  // Array to keep track of the parent vertices

            // Run DFS from each unvisited vertex
            for (int i = 0; i < MAX; i++) {
                if (!visited[i]) {
                    if (dfs(i, visited, parent)) {
                        return true; // Cycle found
                    }
                }
            }
            return false; // No cycle found
        }
};

int main() {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(0, 4);
    g.add_edge(1, 2);
    g.add_edge(1, 3);
    g.add_edge(1, 4);
    g.add_edge(3, 4);
    if (g.detect_cycle()) {
        cout << "Cycle detected in the graph." << endl;
    } else {
        cout << "No cycle detected in the graph." << endl;
    }
    return 0;
}
