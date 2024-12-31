// Solve the "minimum cost to make at least one path between any two nodes" problem.

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX_NODES 100
#define INF INT_MAX

class MinimumCostPath {
    private:
        int graph[MAX_NODES][MAX_NODES];    // Adjacency matrix to store edge costs
        int num_nodes;

    public:
        MinimumCostPath(int nodes) {
            num_nodes = nodes;
            for (int i = 0; i < num_nodes; i++) {
                for (int j = 0; j < num_nodes; j++) {
                    if (i == j)
                        graph[i][j] = 0;    // No cost for self-loops
                    else
                        graph[i][j] = INF;  // Initialize other edges with INF
                }
            }
        }

        void add_edge(int u, int v, int cost) {
            graph[u][v] = cost;
            graph[v][u] = cost;  // Assuming undirected graph
        }

        int find_minimum_cost() {
            bool visited[MAX_NODES] = {false};  // Track visited nodes
            int min_cost[MAX_NODES];            // Minimum cost to include each node
            for (int i = 0; i < num_nodes; i++) {
                min_cost[i] = INF;      // Initialize all costs to INF
            }
            min_cost[0] = 0;            // Start with the first node

            int total_cost = 0;

            for (int count = 0; count < num_nodes; count++) {
                int u = -1;

                // Find the unvisited node with the smallest cost
                for (int i = 0; i < num_nodes; i++) {
                    if (!visited[i] && (u == -1 || min_cost[i] < min_cost[u])) {
                        u = i;
                    }
                }

                visited[u] = true;          // Mark the node as visited
                total_cost += min_cost[u];  // Add its cost to the total

                // Update costs of adjacent nodes
                for (int v = 0; v < num_nodes; v++) {
                    if (graph[u][v] != INF && !visited[v] && graph[u][v] < min_cost[v]) {
                        min_cost[v] = graph[u][v];
                    }
                }
            }

            return total_cost;  // Return the minimum cost to connect all nodes
        }
};

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;
    MinimumCostPath min_cost_path(num_nodes);
    cout << "Enter the edges (u v cost):" << endl;
    for (int i = 0; i < num_edges; i++) {
        int u, v, cost;
        cin >> u >> v >> cost;
        min_cost_path.add_edge(u, v, cost);
    }
    cout << "Minimum cost to connect all nodes: " << min_cost_path.find_minimum_cost() << endl;
    return 0;
}
