//Solve the "network delay time" problem using Dijkstra's algorithm.

#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

#define MAX 100     // Maximum number of vertices in the graph

class NetworkDelay {
    private:
        int adj_matrix[MAX][MAX];   // Adjacency matrix to store edge weights
        int num_vertices;           // Number of vertices in the graph

    public:
        // Constructor to initialize the graph
        NetworkDelay(int vertices) {
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

        // Dijkstra's algorithm to calculate network delay time
        int network_delay(int source) {
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

            // Find the maximum distance from the source
            int max_distance = 0;
            for (int i = 0; i < num_vertices; i++) {
                if (distance[i] == INT_MAX) {
                    return -1;      // If any vertex is unreachable
                }
                max_distance = max(max_distance, distance[i]);
            }
            return max_distance;
        }
};

int main() {
    int vertices = 4; 
    NetworkDelay network(vertices);
    network.add_edge(0, 1, 1);
    network.add_edge(0, 2, 3);
    network.add_edge(1, 2, 1);
    network.add_edge(2, 3, 1);
    int source = 0;
    int result = network.network_delay(source);
    if (result == -1) {
        cout << "Not all nodes are reachable from the source." << endl;
    } else {
        cout << "The network delay time is: " << result << " units." << endl;
    }
    return 0;
}
