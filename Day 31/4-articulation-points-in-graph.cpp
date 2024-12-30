// Solve the "find articulation points in a graph" problem using Tarjan’s algorithm.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

class Graph {
    private:
        int adj_matrix[MAX][MAX];       // Adjacency matrix to represent the graph
        int num_nodes;                  // Number of nodes in the graph
        int visited[MAX];               // Visited array
        int discovery[MAX];             // Discovery time of each node
        int low[MAX];                   // Lowest discovery time reachable
        int parent[MAX];                // Parent of each node in the DFS tree
        bool articulation_point[MAX];   // Boolean array to store articulation points
        int timer;                      // Timer for discovery time

        void dfs(int node) {
            visited[node] = true;
            discovery[node] = low[node] = ++timer;
            int children = 0;

            for (int neighbor = 0; neighbor < num_nodes; neighbor++) {
                if (adj_matrix[node][neighbor]) {
                    if (!visited[neighbor]) {
                        children++;
                        parent[neighbor] = node;
                        dfs(neighbor);

                        // Update the low value of the current node
                        low[node] = min(low[node], low[neighbor]);

                        // Check if the current node is an articulation point
                        if (parent[node] == -1 && children > 1) {
                            articulation_point[node] = true;
                        }
                        if (parent[node] != -1 && low[neighbor] >= discovery[node]) {
                            articulation_point[node] = true;
                        }
                    } else if (neighbor != parent[node]) {
                        // Update the low value if the neighbor is already visited
                        low[node] = min(low[node], discovery[neighbor]);
                    }
                }
            }
        }

    public:
        Graph(int nodes) {
            num_nodes = nodes;
            memset(adj_matrix, 0, sizeof(adj_matrix));
            memset(visited, 0, sizeof(visited));
            memset(discovery, -1, sizeof(discovery));
            memset(low, -1, sizeof(low));
            memset(parent, -1, sizeof(parent));
            memset(articulation_point, false, sizeof(articulation_point));
            timer = 0;
        }
        void add_edge(int u, int v) {
            adj_matrix[u][v] = 1;
            adj_matrix[v][u] = 1;
        }
        void find_articulation_points() {
            for (int i = 0; i < num_nodes; i++) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
            cout << "Articulation Points: ";
            bool found = false;
            for (int i = 0; i < num_nodes; i++) {
                if (articulation_point[i]) {
                    cout << i << " ";
                    found = true;
                }
            }
            if (!found) {
                cout << "None";
            }
            cout << endl;
        }
};

int main() {
    int nodes, edges;
    cout << "Enter number of nodes and edges: ";
    cin >> nodes >> edges;
    Graph graph(nodes);
    cout << "Enter edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        u--;    // Convert to 0-based index
        v--;
        graph.add_edge(u, v);
    }
    graph.find_articulation_points();
    return 0;
}
