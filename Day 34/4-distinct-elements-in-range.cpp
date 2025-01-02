// Solve the "number of distinct elements in a range" problem using a segment tree.

#include <iostream>
#include <cstring>
#include <set>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        set<int> segment_tree[4 * MAX];
        int arr[MAX];

        // Helper function to build the segment tree
        void build(int node, int start, int end) {
            if (start == end) {
                segment_tree[node].insert(arr[start]);
            } else {
                int mid = (start + end) / 2;
                build(2 * node, start, mid);
                build(2 * node + 1, mid + 1, end);
                segment_tree[node].insert(segment_tree[2 * node].begin(), segment_tree[2 * node].end());
                segment_tree[node].insert(segment_tree[2 * node + 1].begin(), segment_tree[2 * node + 1].end());
            }
        }

        // Helper function to query the number of distinct elements in range [l, r]
        set<int> query(int node, int start, int end, int l, int r) {
            if (r < start || end < l) {
                return set<int>();  // Return an empty set for out-of-range
            }

            if (l <= start && end <= r) {
                return segment_tree[node];
            }

            int mid = (start + end) / 2;
            set<int> left = query(2 * node, start, mid, l, r);
            set<int> right = query(2 * node + 1, mid + 1, end, l, r);
            left.insert(right.begin(), right.end());
            return left;
        }

    public:
        // Function to initialize the array and build the segment tree
        void init(int n, int input_arr[]) {
            memcpy(arr, input_arr, sizeof(arr));
            build(1, 0, n - 1);
        }

        // Function to get the number of distinct elements in the range [l, r]
        int get_distinct_count(int l, int r) {
            set<int> result = query(1, 0, MAX - 1, l, r);
            return result.size();
        }
};

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[MAX];
    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    SegmentTree tree;
    tree.init(n, arr);
    int q;
    cout << "Enter the number of queries: ";
    cin >> q;
    while (q--) {
        int l, r;
        cout << "Enter the range (l r): ";
        cin >> l >> r;
        cout << "Number of distinct elements in range [" << l << ", " << r << "] is: " 
             << tree.get_distinct_count(l, r) << endl;
    }
    return 0;
}
