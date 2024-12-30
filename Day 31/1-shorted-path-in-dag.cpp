// Solve the "shortest path in a directed acyclic graph (DAG)" problem using topological sorting.

#include <iostream>
#include <cstring>
#include <stack>
#include <climits>
using namespace std;

#define MAX_NODES 100

class Graph {
    private:
        int adj_matrix[MAX_NODES][MAX_NODES];   // Adjacency matrix for the graph
        int num_nodes;

        // Function to perform topological sort
        void topological_sort_util(int node, bool visited[], stack<int> &stack) {
            visited[node] = true;

            for (int i = 0; i < num_nodes; i++) {
                if (adj_matrix[node][i] != 0 && !visited[i]) {
                    topological_sort_util(i, visited, stack);
                }
            }

            stack.push(node);
        }

    public:
        // Constructor
        Graph(int nodes) {
            num_nodes = nodes;
            memset(adj_matrix, 0, sizeof(adj_matrix));
        }

        // Function to add a directed edge with weight
        void add_edge(int u, int v, int weight) {
            adj_matrix[u][v] = weight;
        }

        // Function to find shortest path from the source node
        void shortest_path(int source) {
            stack<int> stack;
            bool visited[MAX_NODES] = {false};

            // Perform topological sort
            for (int i = 0; i < num_nodes; i++) {
                if (!visited[i]) {
                    topological_sort_util(i, visited, stack);
                }
            }

            // Initialize distances
            int distance[MAX_NODES];
            for (int i = 0; i < num_nodes; i++) {
                distance[i] = INT_MAX;
            }
            distance[source] = 0;

            // Process nodes in topological order
            while (!stack.empty()) {
                int u = stack.top();
                stack.pop();

                if (distance[u] != INT_MAX) {
                    for (int v = 0; v < num_nodes; v++) {
                        if (adj_matrix[u][v] != 0) {
                            if (distance[v] > distance[u] + adj_matrix[u][v]) {
                                distance[v] = distance[u] + adj_matrix[u][v];
                            }
                        }
                    }
                }
            }

            // Print distances
            cout << "Shortest distances from node " << source << ":" << endl;
            for (int i = 0; i < num_nodes; i++) {
                if (distance[i] == INT_MAX) {
                    cout << "Node " << i << ": INF" << endl;
                } else {
                    cout << "Node " << i << ": " << distance[i] << endl;
                }
            }
        }
};

int main() {
    int nodes = 6;
    Graph graph(nodes);
    graph.add_edge(0, 1, 2);
    graph.add_edge(0, 4, 1);
    graph.add_edge(1, 2, 3);
    graph.add_edge(4, 2, 2);
    graph.add_edge(4, 5, 4);
    graph.add_edge(2, 3, 6);
    graph.add_edge(5, 3, 1);
    int source = 0;
    graph.shortest_path(source);
    return 0;
}
