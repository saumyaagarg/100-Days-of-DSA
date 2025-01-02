// Solve the "range minimum query (RMQ)" problem using a segment tree.

#include <iostream>
#include <climits>
using namespace std;

#define MAX 1000

class Segment_Tree {
    private:
        int segment_tree[4 * MAX]; // Array to store the segment tree
        int array[MAX];            // Input array
        int size;                  // Size of the input array

        // Build the segment tree
        void build_tree(int node, int start, int end) {
            if (start == end) {
                segment_tree[node] = array[start];  // Leaf node
            } else {
                int mid = (start + end) / 2;
                build_tree(2 * node + 1, start, mid);       // Build left child
                build_tree(2 * node + 2, mid + 1, end);     // Build right child
                segment_tree[node] = min(segment_tree[2 * node + 1], segment_tree[2 * node + 2]);   // Store minimum
            }
        }

        // Query the segment tree for minimum in range [left, right]
        int query_tree(int node, int start, int end, int left, int right) {
            if (start > right || end < left) {
                return INT_MAX;             // Out of range
            }
            if (start >= left && end <= right) {
                return segment_tree[node];  // Fully within range
            }
            int mid = (start + end) / 2;
            int left_min = query_tree(2 * node + 1, start, mid, left, right);
            int right_min = query_tree(2 * node + 2, mid + 1, end, left, right);
            return min(left_min, right_min); // Return minimum of both ranges
        }

    public:
        // Initialize the segment tree
        void initialize(int arr[], int n) {
            size = n;
            for (int i = 0; i < n; i++) {
                array[i] = arr[i];
            }
            build_tree(0, 0, size - 1);     // Build the segment tree
        }

        // Query for minimum in range [left, right]
        int range_minimum_query(int left, int right) {
            return query_tree(0, 0, size - 1, left, right);
        }
};

int main() {
    int array[MAX], n, queries, left, right;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    Segment_Tree seg_tree;
    seg_tree.initialize(array, n);
    cout << "Enter the number of queries: ";
    cin >> queries;
    while (queries--) {
        cout << "Enter range (left and right): ";
        cin >> left >> right;
        cout << "Minimum in range [" << left << ", " << right << "] is: " << seg_tree.range_minimum_query(left, right) << endl;
    }
    return 0;
}
