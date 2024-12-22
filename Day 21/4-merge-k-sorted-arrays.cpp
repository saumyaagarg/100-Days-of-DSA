// Solve the "merge k sorted arrays" problem using a heap.

#include <iostream>
#include <climits>
using namespace std;

#define MAX 1000 // Define the maximum size for the heap

struct HeapNode {
    int value;  // Value of the current element
    int arrayIdx; // Index of the array the element belongs to
    int nextIdx;  // Index of the next element in the array
};

// Function to maintain the Min Heap property
void heapify(HeapNode heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left].value < heap[smallest].value)
        smallest = left;

    if (right < size && heap[right].value < heap[smallest].value)
        smallest = right;

    if (smallest != i) {
        swap(heap[i], heap[smallest]);
        heapify(heap, size, smallest);
    }
}

// Function to merge k sorted arrays
void merge_arrays(int arrays[][MAX], int sizes[], int k, int result[], int &resultSize) {
    HeapNode heap[MAX];
    int heapSize = 0;

    // Step 1: Insert the first element of each array into the heap
    for (int i = 0; i < k; i++) {
        if (sizes[i] > 0) { // Check if the array is not empty
            heap[heapSize++] = {arrays[i][0], i, 1}; // Insert first element
        }
    }

    // Build the initial Min Heap
    for (int i = heapSize / 2 - 1; i >= 0; i--) {
        heapify(heap, heapSize, i);
    }

    // Step 2: Extract elements and build the merged array
    resultSize = 0;
    while (heapSize > 0) {
        // Extract the smallest element from the heap
        HeapNode root = heap[0];
        result[resultSize++] = root.value;

        // If there are more elements in the array, insert the next element
        if (root.nextIdx < sizes[root.arrayIdx]) {
            heap[0] = {arrays[root.arrayIdx][root.nextIdx], root.arrayIdx, root.nextIdx + 1};
        } else { // If no more elements in the array, reduce the heap size
            heap[0] = heap[--heapSize];
        }

        // Re-heapify the heap
        heapify(heap, heapSize, 0);
    }
}

// Main function to test the merge function
int main() {
    int arrays[3][MAX] = {
        {1, 4, 7, 10},
        {2, 5, 8},
        {3, 6, 9, 12, 15}
    };
    int sizes[] = {4, 3, 5};    // Sizes of the individual arrays
    int k = 3;                  // Number of arrays
    int result[MAX];
    int resultSize;
    merge_arrays(arrays, sizes, k, result, resultSize);
    cout << "Merged array: ";
    for (int i = 0; i < resultSize; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
