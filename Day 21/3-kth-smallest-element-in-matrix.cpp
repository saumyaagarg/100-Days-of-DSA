// Solve the "kth smallest element in a matrix" problem using a min heap.

#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100 // Define the maximum matrix size

struct HeapNode {
    int value;  // Matrix element value
    int row;    // Row index of the element
    int col;    // Column index of the element
};

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

// Function to extract the smallest element from the heap
HeapNode extract_min(HeapNode heap[], int &size) {
    if (size <= 0) {
        return {INT_MAX, -1, -1};
    }
    HeapNode root = heap[0];
    heap[0] = heap[size - 1];
    size--;
    heapify(heap, size, 0);
    return root;
}

// Function to insert a new element into the heap
void insert_heap(HeapNode heap[], int &size, HeapNode node) {
    if (size >= MAX) {
        cout << "Heap overflow!" << endl;
        return;
    }

    heap[size] = node;
    int current = size;
    size++;

    while (current != 0 && heap[(current - 1) / 2].value > heap[current].value) {
        swap(heap[current], heap[(current - 1) / 2]);
        current = (current - 1) / 2;
    }
}

int kth_smallest(int matrix[MAX][MAX], int n, int k) {
    HeapNode heap[MAX];
    int heapSize = 0;

    // Step 1: Insert the first element of each row into the heap
    for (int i = 0; i < n && i < k; i++) {
        insert_heap(heap, heapSize, {matrix[i][0], i, 0});
    }

    // Step 2: Extract the smallest element k times
    HeapNode node;
    for (int i = 0; i < k; i++) {
        node = extract_min(heap, heapSize);
        int nextCol = node.col + 1;

        // If there is a next column in the same row, insert it into the heap
        if (nextCol < n) {
            insert_heap(heap, heapSize, {matrix[node.row][nextCol], node.row, nextCol});
        }
    }

    return node.value;
}

int main() {
    int matrix[MAX][MAX] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {25, 29, 37, 48},
        {32, 33, 39, 50}
    };
    int n = 4; 
    int k = 7; 
    cout << "The " << k << "th smallest element is: " << kth_smallest(matrix, n, k) << endl;
    return 0;
}
