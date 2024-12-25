// Implement depth-first search (DFS) for a graph.

#include <iostream>
#include <stack>
using namespace std;

#define MAX 5           // Maximum number of vertices in the graph

// Graph represented using Adjacency List
struct Node {
    int vertex;
    Node* next;
};

// Graph class with DFS functionality
class Graph {
    private:
        Node* adjList[MAX];     // Adjacency list for the graph

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adjList[i] = nullptr;   // Initialize all lists as empty
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

        // Function to perform DFS starting from a given vertex
        void dfs(int start) {
            bool visited[MAX] = {false}; // Array to keep track of visited vertices
            stack<int> s; // Stack to simulate the recursion of DFS

            // Push the starting vertex onto the stack
            s.push(start);
            visited[start] = true;

            cout << "DFS Traversal starting from vertex " << start << ": ";

            // While the stack is not empty, keep performing DFS
            while (!s.empty()) {
                int current = s.top();
                s.pop();
                cout << current << " "; // Print the visited vertex

                // Explore all the neighbors of the current vertex
                Node* temp = adjList[current];
                while (temp != nullptr) {
                    if (!visited[temp->vertex]) { // If the neighbor hasn't been visited
                        visited[temp->vertex] = true;
                        s.push(temp->vertex); // Push the neighbor onto the stack
                    }
                    temp = temp->next;
                }
            }
            cout << endl;
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
    g.dfs(0);
    return 0;
}
