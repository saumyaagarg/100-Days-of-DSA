// Implement Dijkstra's algorithm for finding the shortest path in a weighted graph.

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 100     // Maximum number of vertices in the graph

class Graph {
    private:
        int adj_matrix[MAX][MAX];   // Adjacency matrix to store edge weights
        int num_vertices;           // Number of vertices in the graph

    public:
        // Constructor to initialize the graph
        Graph(int vertices) {
            num_vertices = vertices;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    adj_matrix[i][j] = (i == j) ? 0 : INT_MAX;  // No edge between nodes initially
                }
            }
        }

        // Add edge to the graph
        void add_edge(int src, int dest, int weight) {
            adj_matrix[src][dest] = weight;
        }

        // Function to find the vertex with the minimum distance that is not yet processed
        int find_min_distance(int distance[], bool visited[]) {
            int min_distance = INT_MAX;
            int min_index = -1;

            for (int i = 0; i < num_vertices; i++) {
                if (!visited[i] && distance[i] < min_distance) {
                    min_distance = distance[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        // Dijkstra's algorithm to find the shortest path from a source vertex
        void dijkstra(int source) {
            int distance[MAX];      // Array to store shortest distance from source to each vertex
            bool visited[MAX];      // Array to mark visited vertices

            // Initialize distances to infinity and visited array to false
            for (int i = 0; i < num_vertices; i++) {
                distance[i] = INT_MAX;
                visited[i] = false;
            }

            distance[source] = 0;   // Distance from source to itself is 0

            // Process each vertex
            for (int count = 0; count < num_vertices - 1; count++) {
                int u = find_min_distance(distance, visited);
                if (u == -1) break; // If no vertex is reachable, break

                visited[u] = true;

                // Update distance for all adjacent vertices of the chosen vertex
                for (int v = 0; v < num_vertices; v++) {
                    if (!visited[v] && adj_matrix[u][v] != INT_MAX && distance[u] + adj_matrix[u][v] < distance[v]) {
                        distance[v] = distance[u] + adj_matrix[u][v];
                    }
                }
            }

            // Print the shortest distances
            cout << "Vertex\tDistance from Source" << endl;
            for (int i = 0; i < num_vertices; i++) {
                cout << i << "\t" << (distance[i] == INT_MAX ? -1 : distance[i]) << endl;
            }
        }
};

int main() {
    int vertices = 6;
    Graph graph(vertices);
    graph.add_edge(0, 1, 4);
    graph.add_edge(0, 2, 2);
    graph.add_edge(1, 2, 5);
    graph.add_edge(1, 3, 10);
    graph.add_edge(2, 4, 3);
    graph.add_edge(4, 3, 4);
    graph.add_edge(3, 5, 11);
    int source = 0;
    cout << "Dijkstra's Algorithm (Source: " << source << ")" << endl;
    graph.dijkstra(source);
    return 0;
}
