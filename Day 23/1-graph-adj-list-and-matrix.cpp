// Represent a graph using an adjacency list and an adjacency matrix.

#include <iostream>
using namespace std;

#define MAX 5   // Maximum number of vertices in the graph

// Graph represented using Adjacency List
struct Node {
    int vertex;
    Node* next;
};

// Graph class with adjacency list and matrix
class Graph {
    private:
        Node* adjList[MAX];                 // Adjacency list for the graph
        int adjMatrix[MAX][MAX];            // Adjacency matrix for the graph

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adjList[i] = nullptr;
                for (int j = 0; j < MAX; j++) {
                    adjMatrix[i][j] = 0;    // Initialize matrix with 0 (no edges)
                }
            }
        }

        // Function to add an edge in the adjacency list
        void add_edge_list(int src, int dest) {
            Node* newNode = new Node;
            newNode->vertex = dest;
            newNode->next = adjList[src];
            adjList[src] = newNode;

            // For undirected graph, add the reverse edge as well
            newNode = new Node;
            newNode->vertex = src;
            newNode->next = adjList[dest];
            adjList[dest] = newNode;
        }

        // Function to add an edge in the adjacency matrix
        void add_edge_matrix(int src, int dest) {
            adjMatrix[src][dest] = 1;
            adjMatrix[dest][src] = 1;       // For undirected graph, mark the reverse edge
        }

        // Function to display the adjacency list
        void display_adj_list() {
            for (int i = 0; i < MAX; i++) {
                cout << "Vertex " << i << ": ";
                Node* temp = adjList[i];
                while (temp != nullptr) {
                    cout << temp->vertex << " ";
                    temp = temp->next;
                }
                cout << endl;
            }
        }

        // Function to display the adjacency matrix
        void display_adj_matrix() {
            cout << "Adjacency Matrix: \n";
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    cout << adjMatrix[i][j] << " ";
                }
                cout << endl;
            }
        }
};

int main() {
    Graph g;
    g.add_edge_list(0, 1);
    g.add_edge_list(0, 4);
    g.add_edge_list(1, 2);
    g.add_edge_list(1, 3);
    g.add_edge_list(1, 4);
    g.add_edge_list(3, 4);
    g.add_edge_matrix(0, 1);
    g.add_edge_matrix(0, 4);
    g.add_edge_matrix(1, 2);
    g.add_edge_matrix(1, 3);
    g.add_edge_matrix(1, 4);
    g.add_edge_matrix(3, 4);
    cout << "Adjacency List Representation:\n";
    g.display_adj_list();
    cout << "\nAdjacency Matrix Representation:\n";
    g.display_adj_matrix();
    return 0;
}
