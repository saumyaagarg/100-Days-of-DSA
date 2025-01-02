//  Solve the "range add and range sum query" problem using lazy propagation.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        int tree[MAX * 4];     // Segment Tree array
        int lazy[MAX * 4];     // Lazy propagation array

        // Helper function to propagate the lazy value
        void propagate(int node, int start, int end) {
            if (lazy[node] != 0) {
                tree[node] += lazy[node] * (end - start + 1);
                if (start != end) {
                    lazy[node * 2 + 1] += lazy[node];
                    lazy[node * 2 + 2] += lazy[node];
                }
                lazy[node] = 0;
            }
        }

        // Function to update a range of values
        void updateRange(int node, int start, int end, int l, int r, int value) {
            propagate(node, start, end);
            if (start > end || start > r || end < l) {
                return;
            }

            if (start >= l && end <= r) {
                tree[node] += value * (end - start + 1);
                if (start != end) {
                    lazy[node * 2 + 1] += value;
                    lazy[node * 2 + 2] += value;
                }
                return;
            }

            int mid = (start + end) / 2;
            updateRange(node * 2 + 1, start, mid, l, r, value);
            updateRange(node * 2 + 2, mid + 1, end, l, r, value);
            tree[node] = tree[node * 2 + 1] + tree[node * 2 + 2];
        }

        // Function to query the sum in a range
        int queryRange(int node, int start, int end, int l, int r) {
            propagate(node, start, end);
            if (start > end || start > r || end < l) {
                return 0;
            }

            if (start >= l && end <= r) {
                return tree[node];
            }

            int mid = (start + end) / 2;
            int left_query = queryRange(node * 2 + 1, start, mid, l, r);
            int right_query = queryRange(node * 2 + 2, mid + 1, end, l, r);
            return left_query + right_query;
        }

    public:
        // Constructor to initialize the tree and lazy arrays
        SegmentTree(int n) {
            memset(tree, 0, sizeof(tree));
            memset(lazy, 0, sizeof(lazy));
        }

        // Function to update a range
        void update(int l, int r, int value) {
            updateRange(0, 0, MAX - 1, l, r, value);
        }

        // Function to query the sum in a range
        int query(int l, int r) {
            return queryRange(0, 0, MAX - 1, l, r);
        }
};

int main() {
    int n = 5; 
    SegmentTree st(n);
    st.update(1, 3, 5);
    cout << "Sum in range [2, 4]: " << st.query(2, 4) << endl;
    st.update(0, 2, 3);
    cout << "Sum in range [1, 3]: " << st.query(1, 3) << endl;
    return 0;
}
