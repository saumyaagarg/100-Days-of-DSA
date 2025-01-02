// Solve the "maximum prefix sum in a range" problem using a segment tree.

#include <iostream>
#include <climits>
using namespace std;

#define MAX 1000    // Maximum size of array

// Segment Tree class
class SegmentTree {
    private:
        int seg_tree[MAX * 4];   // Segment tree array

        // Function to build the segment tree
        void build(int this_case, int start, int end, int arr[]) {
            if (start == end) {
                seg_tree[this_case] = arr[start];   // Leaf node stores the element
            } else {
                int mid = (start + end) / 2;
                build(2 * this_case + 1, start, mid, arr);     // Left child
                build(2 * this_case + 2, mid + 1, end, arr);   // Right child
                seg_tree[this_case] = max(seg_tree[2 * this_case + 1], seg_tree[2 * this_case + 2]);
                // Store maximum prefix sum in current node
            }
        }

        // Function to query the segment tree
        int query(int this_case, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return INT_MIN;     // No overlap
            }
            if (l <= start && end <= r) {
                return seg_tree[this_case];  // Total overlap
            }

            int mid = (start + end) / 2;
            int left_result = query(2 * this_case + 1, start, mid, l, r);       // Left query
            int right_result = query(2 * this_case + 2, mid + 1, end, l, r);    // Right query
            return max(left_result, right_result);      // Return maximum prefix sum
        }

    public:
        // Function to initialize the segment tree
        void init(int arr[], int n) {
            build(0, 0, n - 1, arr);    // Build segment tree for given array
        }

        // Function to get maximum prefix sum in a range [l, r]
        int get_max_prefix_sum(int l, int r) {
            return query(0, 0, MAX - 1, l, r);      // Query the segment tree
        }
};

int main() {
    int arr[MAX];
    int n, q;
    cout << "Enter the number of elements: ";
    cin >> n;
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree segment_tree;
    segment_tree.init(arr, n);
    cout << "Enter the number of queries: ";
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r;
        cout << "Enter the range (l r): ";
        cin >> l >> r;
        cout << "Maximum Prefix Sum in range [" << l << ", " << r << "] is: " << segment_tree.get_max_prefix_sum(l, r) << endl;
    }
    return 0;
}
