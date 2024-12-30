// Solve the "accounts merge" problem using Union-Find.

#include <iostream>
#include <string>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
using namespace std;

class UnionFind {
    private:
        int parent[1000];
        int rank[1000];

    public:
        // Constructor initializes each node as its own parent
        UnionFind(int size) {
            for (int i = 0; i < size; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        // Find the root of the set containing 'x'
        int find(int x) {
            if (parent[x] != x) {
                parent[x] = find(parent[x]); // Path compression
            }
            return parent[x];
        }

        // Union two sets by rank
        void union_sets(int x, int y) {
            int root_x = find(x);
            int root_y = find(y);

            if (root_x != root_y) {
                if (rank[root_x] > rank[root_y]) {
                    parent[root_y] = root_x;
                } else if (rank[root_x] < rank[root_y]) {
                    parent[root_x] = root_y;
                } else {
                    parent[root_y] = root_x;
                    rank[root_x]++;
                }
            }
        }
};

void accounts_merge(string accounts[][2], int n) {
    unordered_map<string, int> email_to_id; // Map email to unique ID
    map<int, set<string>> id_to_emails;    // Map ID to unique emails
    UnionFind uf(n);

    // Associate each email with an account ID
    for (int i = 0; i < n; i++) {
        for (int j = 1; accounts[i][j] != ""; j++) {
            string email = accounts[i][j];
            if (email_to_id.find(email) == email_to_id.end()) {
                email_to_id[email] = i;
            } else {
                uf.union_sets(i, email_to_id[email]);
            }
        }
    }

    // Group emails by root ID
    for (auto &entry : email_to_id) {
        string email = entry.first;
        int id = uf.find(entry.second);
        id_to_emails[id].insert(email);
    }

    // Print merged accounts
    for (auto &entry : id_to_emails) {
        int id = entry.first;
        cout << accounts[id][0]; // Account name
        for (const string &email : entry.second) {
            cout << " " << email;
        }
        cout << endl;
    }
}

int main() {
    string accounts[4][2] = {
        {"John", "johnsmith@mail.com"},
        {"John", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    accounts_merge(accounts, 4);
    return 0;
}
