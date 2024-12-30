// Solve the "detect a cycle in an undirected graph" problem using Union-Find.

#include <iostream>
using namespace std;

#define MAX 1000

class UnionFind {
    private:
        int parent[MAX]; // Parent array to track roots of elements
        int rank[MAX];   // Rank array to optimize union operation

    public:
        // Initialize the Union-Find structure
        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent[i] = i; // Each node is its own parent initially
                rank[i] = 0;   // All ranks start as 0
            }
        }

        // Find the root of a set, with path compression
        int find(int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);  // Path compression
            }
            return parent[node];
        }

        // Union by rank to merge two sets
        bool union_sets(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);

            if (root_u == root_v) {
                return true;    // Cycle detected
            }

            // Union by rank
            if (rank[root_u] > rank[root_v]) {
                parent[root_v] = root_u;
            } else if (rank[root_u] < rank[root_v]) {
                parent[root_u] = root_v;
            } else {
                parent[root_v] = root_u;
                rank[root_u]++;
            }
            return false;
        }
};

int main() {
    int num_nodes, num_edges;
    cout << "Enter the number of nodes and edges: ";
    cin >> num_nodes >> num_edges;
    UnionFind uf(num_nodes);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < num_edges; i++) {
        int u, v;
        cin >> u >> v;
        if (uf.union_sets(u, v)) {
            cout << "Cycle detected in the graph." << endl;
            return 0;
        }
    }
    cout << "No cycle detected in the graph." << endl;
    return 0;
}
