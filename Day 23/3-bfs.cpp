// Implement breadth-first search (BFS) for a graph.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 5   // Maximum number of vertices in the graph

// Graph represented using Adjacency List
struct Node {
    int vertex;
    Node* next;
};

// Graph class with BFS functionality
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

    // Function to perform BFS starting from a given vertex
    void bfs(int start) {
        bool visited[MAX] = {false};    // Array to keep track of visited vertices
        queue<int> q;                   // Queue to manage BFS order

        // Mark the starting vertex as visited and enqueue it
        visited[start] = true;
        q.push(start);

        cout << "BFS Traversal starting from vertex " << start << ": ";

        // While the queue is not empty, keep performing BFS
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";     // Print the visited vertex

            // Explore all the neighbors of the current vertex
            Node* temp = adjList[current];
            while (temp != nullptr) {
                if (!visited[temp->vertex]) {   // If the neighbor hasn't been visited
                    visited[temp->vertex] = true;
                    q.push(temp->vertex);       // Enqueue the neighbor
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
    g.bfs(0);
    return 0;
}
