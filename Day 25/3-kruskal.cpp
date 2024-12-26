//  Implement Kruskal's algorithm to find the minimum spanning tree of a graph.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100     // Maximum number of vertices in the graph

class Kruskal {
    private:
        int parent[MAX];    // Array to represent the disjoint set
        int edges[MAX][3];  // Array to store the edges (u, v, weight)
        int num_edges;      // Number of edges in the graph
        int num_vertices;   // Number of vertices in the graph

    public:
        // Constructor to initialize the graph
        Kruskal(int vertices) {
            num_vertices = vertices;
            num_edges = 0;
        }

        // Add an edge to the graph
        void add_edge(int u, int v, int weight) {
            edges[num_edges][0] = u;
            edges[num_edges][1] = v;
            edges[num_edges][2] = weight;
            num_edges++;
        }

        // Function to find the parent of a node in the disjoint set
        int find_parent(int node) {
            if (parent[node] == -1) {
                return node;
            }
            return parent[node] = find_parent(parent[node]);    // Path compression
        }

        // Function to perform union of two sets
        void union_sets(int u, int v) {
            int parent_u = find_parent(u);
            int parent_v = find_parent(v);
            parent[parent_u] = parent_v;
        }

        // Manual sorting function for the edges based on weight
        void sort_edges() {
            for (int i = 0; i < num_edges - 1; i++) {
                for (int j = 0; j < num_edges - i - 1; j++) {
                    if (edges[j][2] > edges[j + 1][2]) {
                        // Swap edges[j] and edges[j + 1]
                        for (int k = 0; k < 3; k++) {
                            int temp = edges[j][k];
                            edges[j][k] = edges[j + 1][k];
                            edges[j + 1][k] = temp;
                        }
                    }
                }
            }
        }

        // Function to find the MST using Kruskal's algorithm
        void find_mst() {
            sort_edges();       // Sort edges by weight

            memset(parent, -1, sizeof(parent)); // Initialize disjoint set
            int mst_weight = 0; // Total weight of MST

            cout << "Edges in the Minimum Spanning Tree:" << endl;

            for (int i = 0; i < num_edges; i++) {
                int u = edges[i][0];
                int v = edges[i][1];
                int weight = edges[i][2];

                // Check if adding this edge forms a cycle
                if (find_parent(u) != find_parent(v)) {
                    cout << u << " -- " << v << " == " << weight << endl;
                    mst_weight += weight;
                    union_sets(u, v);
                }
            }

            cout << "Total weight of MST: " << mst_weight << endl;
        }
};

int main() {
    int vertices = 5; 
    Kruskal graph(vertices);
    graph.add_edge(0, 1, 10);
    graph.add_edge(0, 2, 6);
    graph.add_edge(0, 3, 5);
    graph.add_edge(1, 3, 15);
    graph.add_edge(2, 3, 4);
    graph.find_mst();
    return 0;
}
