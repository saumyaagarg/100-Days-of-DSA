// Modify the segment tree to support point updates and range queries.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        int tree[MAX * 4];  // Segment tree array
        int arr[MAX];       // Input array
        int size;           // Size of the input array

        // Build the segment tree
        void build_tree(int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];    // Leaf node
            } else {
                int mid = (start + end) / 2;
                int left_child = 2 * node + 1;
                int right_child = 2 * node + 2;

                build_tree(left_child, start, mid);
                build_tree(right_child, mid + 1, end);

                tree[node] = tree[left_child] + tree[right_child];  // Combine results
            }
        }

        // Perform a point update on the segment tree
        void update_tree(int node, int start, int end, int idx, int value) {
            if (start == end) {
                arr[idx] = value;   // Update the array
                tree[node] = value; // Update the tree
            } else {
                int mid = (start + end) / 2;
                int left_child = 2 * node + 1;
                int right_child = 2 * node + 2;

                if (idx <= mid) {
                    update_tree(left_child, start, mid, idx, value);
                } else {
                    update_tree(right_child, mid + 1, end, idx, value);
                }

                tree[node] = tree[left_child] + tree[right_child];  // Recalculate parent
            }
        }

        // Perform a range query
        int query_tree(int node, int start, int end, int l, int r) {
            if (r < start || l > end) {
                return 0;   // Out of range
            }

            if (l <= start && r >= end) {
                return tree[node];  // Completely in range
            }

            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;

            int left_sum = query_tree(left_child, start, mid, l, r);
            int right_sum = query_tree(right_child, mid + 1, end, l, r);

            return left_sum + right_sum;    // Combine results
        }

    public:
        // Initialize the segment tree
        void initialize(int input_arr[], int n) {
            size = n;
            for (int i = 0; i < n; i++) {
                arr[i] = input_arr[i];
            }
            build_tree(0, 0, size - 1);
        }

        // Update a value at a specific index
        void update(int idx, int value) {
            update_tree(0, 0, size - 1, idx, value);
        }

        // Query the sum of a range
        int query(int l, int r) {
            return query_tree(0, 0, size - 1, l, r);
        }
};

int main() {
    int n = 6;
    int input_arr[] = {1, 3, 5, 7, 9, 11};
    SegmentTree seg_tree;
    seg_tree.initialize(input_arr, n);
    cout << "Initial range sum (1 to 3): " << seg_tree.query(1, 3) << endl;
    seg_tree.update(1, 10);
    cout << "After update, range sum (1 to 3): " << seg_tree.query(1, 3) << endl;
    seg_tree.update(3, 6);
    cout << "After another update, range sum (0 to 5): " << seg_tree.query(0, 5) << endl;
    return 0;
}
