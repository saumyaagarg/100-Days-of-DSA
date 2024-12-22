// Solve the "k largest elements in an array" problem using a min heap.

#include <iostream>
#include <climits>
using namespace std;

// Helper function to maintain the Min Heap property
void heapify(int heap[], int size, int i) {
    int smallest = i;         // Initialize smallest as the root
    int left = 2 * i + 1;     // Left child index
    int right = 2 * i + 2;    // Right child index

    // Check if left child is smaller than the root
    if (left < size && heap[left] < heap[smallest])
        smallest = left;

    // Check if right child is smaller than the current smallest
    if (right < size && heap[right] < heap[smallest])
        smallest = right;

    // If the smallest is not the root, swap and heapify
    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Function to build the Min Heap
void build_heap(int heap[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

// Function to find k largest elements using a Min Heap
void k_largest_elements(int arr[], int n, int k) {
    if (k > n) {
        cout << "Invalid value of k!" << endl;
        return;
    }

    // Step 1: Build a Min Heap with the first k elements of the array
    int heap[k];
    for (int i = 0; i < k; i++) {
        heap[i] = arr[i];
    }
    build_heap(heap, k);

    // Step 2: Process the rest of the array
    for (int i = k; i < n; i++) {
        if (arr[i] > heap[0]) {     // If the current element is larger than the root of the heap
            heap[0] = arr[i];       // Replace the root
            heapify(heap, k, 0);    // Re-heapify the root
        }
    }

    // Step 3: Print the k largest elements (Min Heap will store them)
    cout << "The " << k << " largest elements are: ";
    for (int i = 0; i < k; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}

// Main function to test the k largest elements function
int main() {
    int arr[] = {10, 20, 11, 70, 60, 50, 30, 100};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    k_largest_elements(arr, n, k);
    return 0;
}
