// Solve the "minimum cost to connect all points" problem using Prim’s algorithm.

#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

#define MAX 100  // Maximum number of points

class MinCostConnectPoints {
    private:
        int graph[MAX][MAX];  // Adjacency matrix for storing distances
        int num_points;       // Number of points

    public:
        // Constructor to initialize the graph
        MinCostConnectPoints(int points) {
            num_points = points;
            for (int i = 0; i < MAX; i++) {
                for (int j = 0; j < MAX; j++) {
                    graph[i][j] = 0;    // No connections initially
                }
            }
        }

        // Function to add edges between points with weights
        void add_edge(int src, int dest, int weight) {
            graph[src][dest] = weight;
            graph[dest][src] = weight;  // Undirected graph
        }

        // Find the point with the minimum key value not included in MST
        int find_min_key(int key[], bool in_mst[]) {
            int min_key = INT_MAX;
            int min_index = -1;

            for (int i = 0; i < num_points; i++) {
                if (!in_mst[i] && key[i] < min_key) {
                    min_key = key[i];
                    min_index = i;
                }
            }

            return min_index;
        }

        // Prim's algorithm to find the minimum cost to connect all points
        int find_min_cost() {
            int key[MAX];       // Minimum weight edge to include each vertex
            bool in_mst[MAX];   // True if vertex is included in MST
            int total_cost = 0;

            // Initialize keys as infinite and in_mst[] as false
            for (int i = 0; i < num_points; i++) {
                key[i] = INT_MAX;
                in_mst[i] = false;
            }

            key[0] = 0;  // Start with the first point

            // Iterate to form the MST
            for (int count = 0; count < num_points; count++) {
                int u = find_min_key(key, in_mst);
                if (u == -1) break;     // No more reachable points

                in_mst[u] = true;       // Include this point in MST
                total_cost += key[u];

                // Update the key values of the adjacent points
                for (int v = 0; v < num_points; v++) {
                    if (!in_mst[v] && graph[u][v] != 0 && graph[u][v] < key[v]) {
                        key[v] = graph[u][v];
                    }
                }
            }

            return total_cost;
        }
};

int main() {
    int points = 4;
    MinCostConnectPoints min_cost(points);
    // Define the points and calculate the Manhattan distances
    int coordinates[4][2] = {{0, 0}, {2, 2}, {3, 10}, {5, 2}};
    for (int i = 0; i < points; i++) {
        for (int j = i + 1; j < points; j++) {
            int weight = abs(coordinates[i][0] - coordinates[j][0]) + abs(coordinates[i][1] - coordinates[j][1]);
            min_cost.add_edge(i, j, weight);
        }
    }
    int result = min_cost.find_min_cost();
    cout << "The minimum cost to connect all points is: " << result << endl;
    return 0;
}
