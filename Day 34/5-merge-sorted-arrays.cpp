// Solve the "merge k sorted arrays using a segment tree" problem.

#include <iostream>
#include <climits>
using namespace std;

#define MAX 1000    // Maximum number of elements in each array
#define INF INT_MAX

// Segment Tree to merge k sorted arrays
class SegmentTree {
    private:
        int tree[4 * MAX];  // Segment Tree array
        int n;              // Size of the array

        // Function to build the segment tree
<<<<<<< Tabnine <<<<<<<
        /**//+
         * @brief Builds the segment tree from the given array.//+
         *//+
         * This function recursively constructs the segment tree from the input array.//+
         * It initializes the leaf nodes with the corresponding array elements and updates//+
         * the internal nodes with the minimum values of their children.//+
         *//+
         * @param arr The input array.//+
         * @param node The index of the current node in the segment tree.//+
         * @param start The start index of the current segment in the array.//+
         * @param end The end index of the current segment in the array.//+
         *///+
        void build(int arr[], int node, int start, int end) {
            if (start == end) {
                tree[node] = arr[start];  // Leaf node holds the element value
            } else {
                int mid = (start + end) / 2;
                build(arr, 2 * node, start, mid);           // Left child
                build(arr, 2 * node + 1, mid + 1, end);     // Right child
                tree[node] = min(tree[2 * node], tree[2 * node + 1]);  // Internal node holds the minimum value
            }
        }
>>>>>>> Tabnine >>>>>>>// {"conversationId":"d7619934-306b-4787-adeb-b678483a762f","source":"instruct"}

        // Function to update an element in the segment tree
        void update(int node, int start, int end, int idx, int value) {
            if (start == end) {
                tree[node] = value;  // Update the value at the leaf node
            } else {
                int mid = (start + end) / 2;
                if (start <= idx && idx <= mid) {
                    update(2 * node, start, mid, idx, value);           // Left child
                } else {
                    update(2 * node + 1, mid + 1, end, idx, value);     // Right child
                }
                tree[node] = min(tree[2 * node], tree[2 * node + 1]);   // Update the internal node
            }
        }

        // Function to get the minimum value in the range
        int query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return INF;     // Out of range, return infinity
            }
            if (l <= start && end <= r) {
                return tree[node];      // Current segment is completely inside the query range
            }
            int mid = (start + end) / 2;
            int left_query = query(2 * node, start, mid, l, r);         // Query the left child
            int right_query = query(2 * node + 1, mid + 1, end, l, r);  // Query the right child
            return min(left_query, right_query);    // Return the minimum of both
        }

    public:
        // Constructor to initialize the segment tree
        SegmentTree(int arr[], int size) {
            n = size;
            build(arr, 1, 0, n - 1);    // Build the segment tree from the array
        }

        // Update an element in the segment tree
        void update(int idx, int value) {
            update(1, 0, n - 1, idx, value);
        }

        // Get the minimum value in the range [l, r]
        int query(int l, int r) {
            return query(1, 0, n - 1, l, r);
        }
};

// Function to merge k sorted arrays using a segment tree
void merge_k_sorted_arrays(int k, int arr[][MAX], int rows, int cols) {
    int result[rows * cols];
    int idx = 0;

    // Flatten the k sorted arrays into one array
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < cols; j++) {
            result[idx++] = arr[i][j];
        }
    }

    // Build the segment tree on the flattened array
    SegmentTree seg_tree(result, rows * cols);

    // Output the merged sorted array
    cout << "Merged Sorted Array: ";
    for (int i = 0; i < rows * cols; i++) {
        cout << seg_tree.query(i, i) << " ";    // Each element is returned as a min query result
    }
    cout << endl;
}

int main() {
    int k = 3; 
    int arr[3][MAX] = {
        {1, 5, 9}, 
        {2, 6, 8},  
        {3, 7, 10}  
    };
    int rows = 3, cols = 3; 
    merge_k_sorted_arrays(k, arr, rows, cols);
    return 0;
}
