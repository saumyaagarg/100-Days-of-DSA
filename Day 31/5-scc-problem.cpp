// Solve the "strongly connected components (SCC)" problem using Kosaraju's algorithm.

#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

#define MAX 1000

class Kosaraju {
    private:
        int num_vertices;
        int graph[MAX][MAX];
        int reverse_graph[MAX][MAX];
        bool visited[MAX];

        // Helper function to perform DFS on the original graph
        void dfs_original(int node, stack<int>& finish_stack) {
            visited[node] = true;
            for (int i = 0; i < num_vertices; i++) {
                if (graph[node][i] && !visited[i]) {
                    dfs_original(i, finish_stack);
                }
            }
            finish_stack.push(node);
        }

        // Helper function to perform DFS on the transposed graph
        void dfs_transpose(int node) {
            cout << node << " ";
            visited[node] = true;
            for (int i = 0; i < num_vertices; i++) {
                if (reverse_graph[node][i] && !visited[i]) {
                    dfs_transpose(i);
                }
            }
        }

    public:
        Kosaraju(int vertices) {
            num_vertices = vertices;
            memset(graph, 0, sizeof(graph));
            memset(reverse_graph, 0, sizeof(reverse_graph));
            memset(visited, false, sizeof(visited));
        }

        // Add a directed edge from 'u' to 'v'
        void add_edge(int u, int v) {
            graph[u][v] = 1;
        }

        // Transpose the graph
        void transpose_graph() {
            for (int i = 0; i < num_vertices; i++) {
                for (int j = 0; j < num_vertices; j++) {
                    reverse_graph[j][i] = graph[i][j];
                }
            }
        }

        // Find and print all SCCs
        void find_scc() {
            stack<int> finish_stack;

            // Step 1: Perform DFS on the original graph and store finish times
            memset(visited, false, sizeof(visited));
            for (int i = 0; i < num_vertices; i++) {
                if (!visited[i]) {
                    dfs_original(i, finish_stack);
                }
            }

            // Step 2: Transpose the graph
            transpose_graph();

            // Step 3: Perform DFS on the transposed graph in the order of finish times
            memset(visited, false, sizeof(visited));
            cout << "Strongly Connected Components are:" << endl;
            while (!finish_stack.empty()) {
                int node = finish_stack.top();
                finish_stack.pop();

                if (!visited[node]) {
                    dfs_transpose(node);
                    cout << endl;
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
    Kosaraju kosaraju(vertices);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        kosaraju.add_edge(u, v);
    }
    kosaraju.find_scc();
    return 0;
}
