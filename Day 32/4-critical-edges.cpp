// Solve the "find critical edges in a graph" problem.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100    // Maximum number of vertices in the graph

class CriticalEdges {
    private:
        int graph[MAX][MAX];  // Adjacency matrix to represent the graph
        bool visited[MAX];    // Array to track visited nodes
        int discovery[MAX];   // Discovery times of visited vertices
        int low[MAX];         // Earliest visited vertex reachable from subtree
        int parent[MAX];      // Parent vertices in DFS tree
        int time;             // Timer for discovery time
        int vertices;         // Number of vertices in the graph

        void dfs(int u) {
            visited[u] = true;
            discovery[u] = low[u] = ++time;

            for (int v = 0; v < vertices; v++) {
                if (graph[u][v]) {      // Check adjacency
                    if (!visited[v]) {
                        parent[v] = u;
                        dfs(v);

                        // Update the low value of the current vertex
                        low[u] = min(low[u], low[v]);

                        // If the edge (u, v) is a critical edge
                        if (low[v] > discovery[u]) {
                            cout << u << " -> " << v << endl;
                        }
                    } else if (v != parent[u]) {
                        low[u] = min(low[u], discovery[v]);
                    }
                }
            }
        }

    public:
        CriticalEdges(int n) {
            vertices = n;
            memset(graph, 0, sizeof(graph));
            memset(visited, false, sizeof(visited));
            memset(discovery, -1, sizeof(discovery));
            memset(low, -1, sizeof(low));
            memset(parent, -1, sizeof(parent));
            time = 0;
        }

        void add_edge(int u, int v) {
            graph[u][v] = 1;
            graph[v][u] = 1;
        }

        void find_critical_edges() {
            for (int i = 0; i < vertices; i++) {
                if (!visited[i]) {
                    dfs(i);
                }
            }
        }
};

int main() {
    int vertices, edges;
    cout << "Enter the number of vertices: ";
    cin >> vertices;
    cout << "Enter the number of edges: ";
    cin >> edges;
    CriticalEdges graph(vertices);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        graph.add_edge(u, v);
    }
    cout << "Critical edges in the graph are:" << endl;
    graph.find_critical_edges();
    return 0;
}
