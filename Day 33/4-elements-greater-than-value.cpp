// Implement a segment tree to count the number of elements in a range greater than a given value.

#include <iostream>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        int segment_tree[4 * MAX];
        int arr[MAX];
        int n;

        // Build the segment tree
        void build_tree(int node, int start, int end) {
            if (start == end) {
                segment_tree[node] = (arr[start] > 0) ? 1 : 0;
            } else {
                int mid = (start + end) / 2;
                int left_child = 2 * node + 1;
                int right_child = 2 * node + 2;
                build_tree(left_child, start, mid);
                build_tree(right_child, mid + 1, end);
                segment_tree[node] = segment_tree[left_child] + segment_tree[right_child];
            }
        }

        // Query the segment tree
        int query_tree(int node, int start, int end, int l, int r, int value) {
            if (start > r || end < l) {
                return 0;   // Out of range
            }
            if (start >= l && end <= r) {
                return count_greater(node, start, end, value);
            }
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            int left_result = query_tree(left_child, start, mid, l, r, value);
            int right_result = query_tree(right_child, mid + 1, end, l, r, value);
            return left_result + right_result;
        }

        // Count numbers greater than value in a range
        int count_greater(int node, int start, int end, int value) {
            if (start == end) {
                return (arr[start] > value) ? 1 : 0;
            }
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            return count_greater(left_child, start, mid, value) + count_greater(right_child, mid + 1, end, value);
        }

    public:
        SegmentTree(int input_arr[], int size) {
            n = size;
            for (int i = 0; i < n; i++) {
                arr[i] = input_arr[i];
            }
            build_tree(0, 0, n - 1);
        }

        int query(int l, int r, int value) {
            return query_tree(0, 0, n - 1, l, r, value);
        }
};

int main() {
    int arr[] = {1, 5, 2, 8, 6, 3};
    int n = 6;
    SegmentTree segment_tree(arr, n);
    int l, r, value;
    cout << "Enter range (l r) and value: ";
    cin >> l >> r >> value;
    cout << "Number of elements greater than " << value << " in range (" << l << ", " << r << "): ";
    cout << segment_tree.query(l, r, value) << endl;
    return 0;
}
