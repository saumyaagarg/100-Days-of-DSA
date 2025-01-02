// Implement a segment tree to find the sum of a range in an array.

#include <iostream>
using namespace std;

#define MAX 1000

class SegmentTree {
    private:
        int segment_tree[4 * MAX];
        int array[MAX];
        int size;

        // Helper function to build the segment tree
        void build_tree(int node, int start, int end) {
            if (start == end) {
                segment_tree[node] = array[start];
            } else {
                int mid = (start + end) / 2;
                int left_child = 2 * node + 1;
                int right_child = 2 * node + 2;
                build_tree(left_child, start, mid);
                build_tree(right_child, mid + 1, end);
                segment_tree[node] = segment_tree[left_child] + segment_tree[right_child];
            }
        }

        // Helper function for range sum query
        int range_sum(int node, int start, int end, int left, int right) {
            if (right < start || left > end) {
                return 0;                   // Outside range
            }
            if (left <= start && end <= right) {
                return segment_tree[node];  // Fully inside range
            }
            int mid = (start + end) / 2;
            int left_child = 2 * node + 1;
            int right_child = 2 * node + 2;
            int sum_left = range_sum(left_child, start, mid, left, right);
            int sum_right = range_sum(right_child, mid + 1, end, left, right);
            return sum_left + sum_right;
        }

        // Helper function to update the segment tree
        void update_tree(int node, int start, int end, int idx, int value) {
            if (start == end) {
                array[idx] = value;
                segment_tree[node] = value;
            } else {
                int mid = (start + end) / 2;
                int left_child = 2 * node + 1;
                int right_child = 2 * node + 2;
                if (idx <= mid) {
                    update_tree(left_child, start, mid, idx, value);
                } else {
                    update_tree(right_child, mid + 1, end, idx, value);
                }
                segment_tree[node] = segment_tree[left_child] + segment_tree[right_child];
            }
        }

    public:
        // Initialize the segment tree
        void initialize(int arr[], int n) {
            size = n;
            for (int i = 0; i < n; i++) {
                array[i] = arr[i];
            }
            build_tree(0, 0, size - 1);
        }

        // Perform a range sum query
        int get_range_sum(int left, int right) {
            return range_sum(0, 0, size - 1, left, right);
        }

        // Update a specific index in the array
        void update(int idx, int value) {
            update_tree(0, 0, size - 1, idx, value);
        }
};

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    SegmentTree segment_tree;
    segment_tree.initialize(arr, n);
    cout << "Sum of range [1, 3]: " << segment_tree.get_range_sum(1, 3) << endl;
    segment_tree.update(1, 10);
    cout << "Sum of range [1, 3]: " << segment_tree.get_range_sum(1, 3) << endl; 
    return 0;
}
