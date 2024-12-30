// Implement the Union-Find algorithm with path compression.

#include <iostream>
using namespace std;

#define MAX 1000  // Maximum number of elements in the Union-Find structure

class UnionFind {
    private:
        int parent[MAX];  // Parent array to store the leader of each set
        int rank[MAX];    // Rank array to store the depth of trees

    public:
        UnionFind(int n) {
            for (int i = 0; i < n; i++) {
                parent[i] = i;  // Initialize each element as its own parent
                rank[i] = 0;    // Initialize rank as 0
            }
        }

        // Find the leader (root) of a set with path compression
        int find(int element) {
            if (parent[element] != element) {
                parent[element] = find(parent[element]);  // Path compression
            }
            return parent[element];
        }

        // Union of two sets by rank
        void union_sets(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y) {
                // Attach smaller rank tree under the root of the higher rank tree
                if (rank[root_x] < rank[root_y]) {
                    parent[root_x] = root_y;
                } else if (rank[root_x] > rank[root_y]) {
                    parent[root_y] = root_x;
                } else {
                    parent[root_y] = root_x;
                    rank[root_x]++;
                }
            }
        }

        // Check if two elements belong to the same set
        bool are_connected(int x, int y) {
            return find(x) == find(y);
        }
};

int main() {
    int n = 10; // Number of elements
    UnionFind uf(n);
    uf.union_sets(1, 2);
    uf.union_sets(2, 3);
    uf.union_sets(4, 5);
    cout << "Are 1 and 3 connected? " << (uf.are_connected(1, 3) ? "Yes" : "No") << endl;
    cout << "Are 3 and 4 connected? " << (uf.are_connected(3, 4) ? "Yes" : "No") << endl;
    uf.union_sets(3, 4);
    cout << "After union of 3 and 4, are 3 and 4 connected? " << (uf.are_connected(3, 4) ? "Yes" : "No") << endl;
    return 0;
}
