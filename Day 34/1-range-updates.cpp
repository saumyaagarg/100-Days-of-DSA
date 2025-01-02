// Implement a lazy propagation mechanism for range updates in a segment tree.

#include <iostream>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        int tree[MAX * 4];     // Segment tree array
        int lazy[MAX * 4];     // Lazy array for range updates

        // Helper function to propagate the updates
        void propagate(int node, int start, int end) {
            if (lazy[node] != 0) {
                tree[node] += lazy[node];               // Apply the pending update to the current node
                if (start != end) {                     // Not a leaf node
                    lazy[2 * node + 1] += lazy[node];   // Mark the left child for lazy propagation
                    lazy[2 * node + 2] += lazy[node];   // Mark the right child for lazy propagation
                }
                lazy[node] = 0;     // Clear the lazy value after propagation
            }
        }

        // Function to update the range [l, r] with the value val
        void update_range(int node, int start, int end, int l, int r, int val) {
            propagate(node, start, end);    // Apply any pending updates before processing the current range

            if (start > end || start > r || end < l)    // No overlap
                return;

            if (start >= l && end <= r) {   // Total overlap
                tree[node] += val;
                if (start != end) {
                    lazy[2 * node + 1] += val;      // Mark the left child for lazy propagation
                    lazy[2 * node + 2] += val;      // Mark the right child for lazy propagation
                }
                return;
            }

            // Partial overlap: Recurse for left and right children
            int mid = (start + end) / 2;
            update_range(2 * node + 1, start, mid, l, r, val);
            update_range(2 * node + 2, mid + 1, end, l, r, val);
            tree[node] = tree[2 * node + 1] + tree[2 * node + 2];   // Update the current node after the changes
        }

        // Function to query the sum in the range [l, r]
        int query_range(int node, int start, int end, int l, int r) {
            propagate(node, start, end);    // Apply any pending updates before processing the current range

            if (start > end || start > r || end < l)    // No overlap
                return 0;

            if (start >= l && end <= r) {   // Total overlap
                return tree[node];
            }

            // Partial overlap: Recurse for left and right children
            int mid = (start + end) / 2;
            int left_sum = query_range(2 * node + 1, start, mid, l, r);
            int right_sum = query_range(2 * node + 2, mid + 1, end, l, r);
            return left_sum + right_sum;
        }

    public:
        // Function to initialize the segment tree
        void init(int n) {
            for (int i = 0; i < n * 4; i++) {
                tree[i] = 0;
                lazy[i] = 0;
            }
        }

        // Wrapper function to update the range
        void update(int l, int r, int val, int n) {
            update_range(0, 0, n - 1, l, r, val);
        }

        // Wrapper function to query the range sum
        int query(int l, int r, int n) {
            return query_range(0, 0, n - 1, l, r);
        }
};

int main() {
    SegmentTree st;
    int n = 10;  
    st.init(n);
    st.update(2, 5, 3, n);  
    st.update(0, 3, 2, n);
    cout << "Sum of elements from index 1 to 4: " << st.query(1, 4, n) << endl;  
    st.update(4, 8, 5, n);  
    cout << "Sum of elements from index 3 to 7: " << st.query(3, 7, n) << endl;  
    return 0;
}
