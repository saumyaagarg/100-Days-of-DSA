// Solve the "check if a graph is bipartite" problem using BFS.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 10      // Maximum number of vertices

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
        int color[MAX];         // Array to store colors (0 or 1)

    public:
        // Constructor to initialize the graph
        Graph() {
            for (int i = 0; i < MAX; i++) {
                adj_list[i] = nullptr;
                visited[i] = false;
                color[i] = -1;  // No color assigned initially
            }
        }

        // Add an undirected edge
        void add_edge(int src, int dest) {
            Node* new_node = new Node;
            new_node->vertex = dest;
            new_node->next = adj_list[src];
            adj_list[src] = new_node;

            new_node = new Node;
            new_node->vertex = src;
            new_node->next = adj_list[dest];
            adj_list[dest] = new_node;
        }

        // Function to check if the graph is bipartite
        bool is_bipartite(int start) {
            queue<int> q;

            // Start with the given vertex, color it with 0
            color[start] = 0;
            q.push(start);

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                Node* temp = adj_list[u];
                while (temp != nullptr) {
                    int v = temp->vertex;

                    // If the vertex is not visited, color it with opposite color
                    if (color[v] == -1) {
                        color[v] = 1 - color[u];
                        q.push(v);
                    }
                    // If the adjacent vertex has the same color, the graph is not bipartite
                    else if (color[v] == color[u]) {
                        return false;
                    }
                    temp = temp->next;
                }
            }
            return true;
        }

        // Function to check all components for bipartite property
        bool check_bipartite() {
            // Check for each unvisited component
            for (int i = 0; i < MAX; i++) {
                if (!visited[i] && adj_list[i] != nullptr) {
                    if (!is_bipartite(i)) {
                        return false;
                    }
                }
            }
            return true;
        }
};

int main() {
    Graph g;
    g.add_edge(0, 1);
    g.add_edge(1, 2);
    g.add_edge(2, 3);
    g.add_edge(3, 4);
    g.add_edge(4, 5);
    g.add_edge(5, 0);
    if (g.check_bipartite()) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }
    return 0;
}
