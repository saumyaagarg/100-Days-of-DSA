// Solve the "find all bridges in a graph" problem using Tarjan’s algorithm.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NODES 1000  // Maximum number of nodes in the graph

class TarjansBridges {
    private:
        int time_stamp;
        int adj_matrix[MAX_NODES][MAX_NODES];   // Adjacency matrix for the graph
        bool visited[MAX_NODES];                // Visited nodes
        int discovery_time[MAX_NODES];          // Discovery time of each node
        int low[MAX_NODES];                     // Lowest discovery time reachable
        int parent[MAX_NODES];                  // Parent of each node
        int num_nodes;

        // Recursive function to find bridges
        void dfs(int u) {
            visited[u] = true;
            discovery_time[u] = low[u] = ++time_stamp;

            for (int v = 0; v < num_nodes; v++) {
                if (adj_matrix[u][v] == 0) continue;    // Skip if no edge exists

                if (!visited[v]) {
                    parent[v] = u;
                    dfs(v);

                    // Update low value of u for child v
                    low[u] = min(low[u], low[v]);

                    // Bridge condition
                    if (low[v] > discovery_time[u]) {
                        cout << "Bridge: " << u << " - " << v << endl;
                    }
                } else if (v != parent[u]) {
                    // Update low value for back edge
                    low[u] = min(low[u], discovery_time[v]);
                }
            }
        }

    public:
        TarjansBridges(int n) {
            num_nodes = n;
            memset(adj_matrix, 0, sizeof(adj_matrix));
            memset(visited, false, sizeof(visited));
            memset(discovery_time, -1, sizeof(discovery_time));
            memset(low, -1, sizeof(low));
            memset(parent, -1, sizeof(parent));
            time_stamp = 0;
        }

        // Function to add an edge between two nodes
        void add_edge(int u, int v) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }

        // Function to find all bridges in the graph
        void find_bridges() {
            for (int i = 0; i < num_nodes; i++) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
        }
};

int main() {
    int num_nodes = 5; 
    TarjansBridges graph(num_nodes);
    graph.add_edge(0, 1);
    graph.add_edge(0, 2);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(3, 4);
    cout << "Bridges in the graph are:" << endl;
    graph.find_bridges();
    return 0;
}
