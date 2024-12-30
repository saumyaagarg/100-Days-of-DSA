// Solve the "Bellman-Ford algorithm" problem for graphs with negative weights.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_EDGES 1000
#define INF 1e9

struct Edge {
    int src;
    int dest;
    int weight;
};

class BellmanFord {
    private:
        int num_vertices, num_edges;
        Edge edges[MAX_EDGES];

    public:
        BellmanFord(int vertices, int edges_count) {
            num_vertices = vertices;
            num_edges = edges_count;
        }

        void add_edge(int index, int src, int dest, int weight) {
            edges[index].src = src;
            edges[index].dest = dest;
            edges[index].weight = weight;
        }

        void find_shortest_path(int start_vertex) {
            int distance[num_vertices];
            for (int i = 0; i < num_vertices; i++) {
                distance[i] = INF;      // Initialize distances as infinite
            }
            distance[start_vertex] = 0;

            // Relax all edges (num_vertices - 1) times
            for (int i = 1; i <= num_vertices - 1; i++) {
                for (int j = 0; j < num_edges; j++) {
                    int u = edges[j].src;
                    int v = edges[j].dest;
                    int weight = edges[j].weight;

                    if (distance[u] != INF && distance[u] + weight < distance[v]) {
                        distance[v] = distance[u] + weight;
                    }
                }
            }

            // Check for negative-weight cycles
            for (int j = 0; j < num_edges; j++) {
                int u = edges[j].src;
                int v = edges[j].dest;
                int weight = edges[j].weight;

                if (distance[u] != INF && distance[u] + weight < distance[v]) {
                    cout << "Graph contains negative weight cycle." << endl;
                    return;
                }
            }

            // Print distances from the source vertex
            cout << "Vertex Distance from Source" << endl;
            for (int i = 0; i < num_vertices; i++) {
                cout << i << " \t\t " << (distance[i] == INF ? "INF" : to_string(distance[i])) << endl;
            }
        }
};

int main() {
    int num_vertices = 5;
    int num_edges = 8;
    BellmanFord graph(num_vertices, num_edges);
    graph.add_edge(0, 0, 1, -1);
    graph.add_edge(1, 0, 2, 4);
    graph.add_edge(2, 1, 2, 3);
    graph.add_edge(3, 1, 3, 2);
    graph.add_edge(4, 1, 4, 2);
    graph.add_edge(5, 3, 2, 5);
    graph.add_edge(6, 3, 1, 1);
    graph.add_edge(7, 4, 3, -3);
    graph.find_shortest_path(0);
    return 0;
}
