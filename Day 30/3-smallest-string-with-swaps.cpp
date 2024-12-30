// Solve the "smallest string with swaps" problem using Union-Find.

#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

#define MAX 1000

class UnionFind {
    private:
        int parent[MAX];
        int rank[MAX];

    public:
        UnionFind(int size) {
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int find(int node) {
            if (parent[node] != node) {
                parent[node] = find(parent[node]); // Path compression
            }
            return parent[node];
        }

        void union_sets(int u, int v) {
            int root_u = find(u);
            int root_v = find(v);

            if (root_u != root_v) {
                if (rank[root_u] > rank[root_v]) {
                    parent[root_v] = root_u;
                } else if (rank[root_u] < rank[root_v]) {
                    parent[root_u] = root_v;
                } else {
                    parent[root_v] = root_u;
                    rank[root_u]++;
                }
            }
        }
};

string smallest_string_with_swaps(string s, pair<int, int> pairs[], int pair_count) {
    int n = s.size();
    UnionFind uf(n);

    // Build the Union-Find structure from the pairs
    for (int i = 0; i < pair_count; i++) {
        uf.union_sets(pairs[i].first, pairs[i].second);
    }

    // Group indices by their connected components
    map<int, multiset<char>> component_chars;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);
        component_chars[root].insert(s[i]);
    }

    // Construct the smallest string
    string result = s;
    for (int i = 0; i < n; i++) {
        int root = uf.find(i);
        result[i] = *component_chars[root].begin();
        component_chars[root].erase(component_chars[root].begin());
    }

    return result;
}

int main() {
    string s = "dcab";
    pair<int, int> pairs[] = {{0, 3}, {1, 2}, {0, 2}};
    int pair_count = sizeof(pairs) / sizeof(pairs[0]);
    cout << "Smallest String: " << smallest_string_with_swaps(s, pairs, pair_count) << endl;
    return 0;
}
