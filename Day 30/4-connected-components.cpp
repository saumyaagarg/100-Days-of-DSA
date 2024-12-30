// Solve the "connected components in an undirected graph" problem using Union-Find.

#include <iostream>
using namespace std;

#define MAX 1000

class UnionFind {
    private:
        int parent[MAX];  // Array to store parent of each node
        int rank[MAX];    // Array to store rank of each node

    public:
        // Constructor to initialize the parent and rank arrays
        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;   // Each node is its own parent initially
                rank[i] = 0;     // Rank is initialized to 0
            }
        }

        // Function to find the representative of a set
        int find(int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]);  // Path compression
            }
            return parent[node];
        }

        // Function to union two sets
        void union_sets(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);

            if (root_u != root_v) {
                if (rank[root_u] > rank[root_v]) {
                    parent[root_v] = root_u;    // Attach smaller rank tree under root of higher rank tree
                } else if (rank[root_u] < rank[root_v]) {
                    parent[root_u] = root_v;
                } else {
                    parent[root_v] = root_u;
                    rank[root_u]++;
                }
            }
        }

        // Function to count connected components
        int count_connected_components(int n) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                if (parent[i] == i) {   // Nodes that are their own parent are representatives
                    count++;
                }
            }
            return count;
        }
};

int main() {
    int n, edges;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> edges;
    UnionFind uf(n);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v;
        cin >> u >> v;
        uf.union_sets(u, v);
    }
    cout << "Number of connected components: " << uf.count_connected_components(n) << endl;
    return 0;
}
