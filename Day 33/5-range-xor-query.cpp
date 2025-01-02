// Solve the "range XOR query" problem using a segment tree.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

class Segment_Tree {
    private:
        int segment_tree[4 * MAX];  // Segment tree array
        int array[MAX];             // Input array
        int size;                   // Size of the input array

        // Build the segment tree
        void build(int node, int start, int end) {
            if (start == end) {
                segment_tree[node] = array[start];
            } else {
                int mid = (start + end) / 2;
                build(2 * node, start, mid);
                build(2 * node + 1, mid + 1, end);
                segment_tree[node] = segment_tree[2 * node] ^ segment_tree[2 * node + 1];
            }
        }

        // Query the XOR for a range
        int query(int node, int start, int end, int left, int right) {
            if (right < start || left > end) {
                return 0;   // No overlap
            }
            if (left <= start && end <= right) {
                return segment_tree[node];  // Complete overlap
            }
            int mid = (start + end) / 2;
            int left_xor = query(2 * node, start, mid, left, right);
            int right_xor = query(2 * node + 1, mid + 1, end, left, right);
            return left_xor ^ right_xor;    // Partial overlap
        }

    public:
        // Initialize the segment tree
        void initialize(int arr[], int n) {
            size = n;
            memcpy(array, arr, n * sizeof(int));
            build(1, 0, n - 1);
        }

        // Public function to query the range XOR
        int range_xor(int left, int right) {
            return query(1, 0, size - 1, left, right);
        }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[MAX];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    Segment_Tree seg_tree;
    seg_tree.initialize(arr, n);
    int queries;
    cout << "Enter the number of queries: ";
    cin >> queries;
    while (queries--) {
        int left, right;
        cout << "Enter the range (0-based index): ";
        cin >> left >> right;
        cout << "Range XOR (" << left << ", " << right << "): " << seg_tree.range_xor(left, right) << endl;
    }
    return 0;
}
