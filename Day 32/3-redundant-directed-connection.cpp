// Solve the "find the redundant directed connection in a graph" problem.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_NODES 1000

class Graph {
    private:
        int parent[MAX_NODES];

        // Helper function to find the root of a node
        int find_root(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find_root(parent[node]);  // Path compression
        }

        // Helper function to unite two nodes
        bool union_nodes(int u, int v) {
            int root_u = find_root(u);
            int root_v = find_root(v);

            if (root_u == root_v) {
                return false;           // A cycle is detected
            }
            parent[root_u] = root_v;    // Union operation
            return true;
        }

    public:
        Graph() {
            memset(parent, -1, sizeof(parent)); // Initialize all nodes as their own roots
        }

        // Function to find the redundant directed connection
        pair<int, int> find_redundant_connection(int edges[][2], int edge_count) {
            pair<int, int> redundant_edge;

            for (int i = 0; i < edge_count; i++) {
                int u = edges[i][0];
                int v = edges[i][1];

                if (!union_nodes(u, v)) {
                    redundant_edge = {u, v};    // Store the redundant edge
                }
            }

            return redundant_edge;
        }
};

int main() {
    int edge_count;
    cout << "Enter the number of edges: ";
    cin >> edge_count;
    int edges[MAX_NODES][2];
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edge_count; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    Graph graph;
    pair<int, int> redundant_edge = graph.find_redundant_connection(edges, edge_count);
    cout << "Redundant Edge: " << redundant_edge.first << " -> " << redundant_edge.second << endl;
    return 0;
}
