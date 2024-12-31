// Solve the "find the smallest cycle in a graph" problem.

#include <iostream>
#include <queue>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_NODES 1000

class Graph {
    private:
        int adj_matrix[MAX_NODES][MAX_NODES];
        int num_nodes;

    public:
        // Constructor to initialize the graph
        Graph(int nodes) {
            num_nodes = nodes;
            memset(adj_matrix, 0, sizeof(adj_matrix));  // Initialize adjacency matrix
        }

        // Function to add an edge to the graph
        void add_edge(int u, int v) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }

        // Function to find the smallest cycle in the graph
        int find_smallest_cycle() {
            int smallest_cycle = INT_MAX;

            for (int start_node = 0; start_node < num_nodes; start_node++) {
                int distance[MAX_NODES];
                int parent[MAX_NODES];
                memset(distance, -1, sizeof(distance));
                memset(parent, -1, sizeof(parent));

                queue<int> q;
                q.push(start_node);
                distance[start_node] = 0;

                while (!q.empty()) {
                    int current_node = q.front();
                    q.pop();

                    for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
                        if (adj_matrix[current_node][neighbor]) {
                            if (distance[neighbor] == -1) {
                                // Neighbor not visited
                                distance[neighbor] = distance[current_node] + 1;
                                parent[neighbor] = current_node;
                                q.push(neighbor);
                            } else if (parent[current_node] != neighbor) {
                                // Found a cycle
                                int cycle_length = distance[current_node] + distance[neighbor] + 1;
                                smallest_cycle = min(smallest_cycle, cycle_length);
                            }
                        }
                    }
                }
            }

            return (smallest_cycle == INT_MAX) ? -1 : smallest_cycle;   // Return -1 if no cycle found
        }
};

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;
    Graph graph(num_nodes);
    cout << "Enter the edges (u v format):" << endl;
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }
    int result = graph.find_smallest_cycle();
    if (result == -1) {
        cout << "No cycle found in the graph." << endl;
    } else {
        cout << "The smallest cycle length is: " << result << endl;
    }
    return 0;
}
