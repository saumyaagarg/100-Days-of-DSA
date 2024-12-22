// Implement a max heap and min heap from scratch using arrays.

#include <iostream>
using namespace std;

class MaxHeap {
    private:
        int* heap;
        int capacity;
        int size;

        // Helper functions
        int parent(int i) { return (i - 1) / 2; }
        int left_child(int i) { return 2 * i + 1; }
        int right_child(int i) { return 2 * i + 1 + 1; }

        void heapify(int i) {
            int largest = i;
            int left = left_child(i);
            int right = right_child(i);

            if (left < size && heap[left] > heap[largest])
                largest = left;
            if (right < size && heap[right] > heap[largest])
                largest = right;
            if (largest != i) {
                swap(heap[i], heap[largest]);
                heapify(largest);
            }
        }

    public:
        MaxHeap(int cap) {
            capacity = cap;
            size = 0;
            heap = new int[capacity];
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "Heap is full!" << endl;
                return;
            }
            heap[size] = value;
            int current = size;
            size++;

            while (current > 0 && heap[parent(current)] < heap[current]) {
                swap(heap[current], heap[parent(current)]);
                current = parent(current);
            }
        }

        int extract_max() {
            if (size <= 0) {
                cout << "Heap is empty!" << endl;
                return -1;
            }
            if (size == 1) {
                size--;
                return heap[0];
            }

            int root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);

            return root;
        }

        int get_max() {
            if (size <= 0) {
                cout << "Heap is empty!" << endl;
                return -1;
            }
            return heap[0];
        }
};

class MinHeap {
    private:
        int* heap;
        int capacity;
        int size;

        // Helper functions
        int parent(int i) { return (i - 1) / 2; }
        int left_child(int i) { return 2 * i + 1; }
        int right_child(int i) { return 2 * i + 1 + 1; }

        void heapify(int i) {
            int smallest = i;
            int left = left_child(i);
            int right = right_child(i);

            if (left < size && heap[left] < heap[smallest])
                smallest = left;
            if (right < size && heap[right] < heap[smallest])
                smallest = right;
            if (smallest != i) {
                swap(heap[i], heap[smallest]);
                heapify(smallest);
            }
        }

    public:
        MinHeap(int cap) {
            capacity = cap;
            size = 0;
            heap = new int[capacity];
        }

        void insert(int value) {
            if (size == capacity) {
                cout << "Heap is full!" << endl;
                return;
            }
            heap[size] = value;
            int current = size;
            size++;

            while (current > 0 && heap[parent(current)] > heap[current]) {
                swap(heap[current], heap[parent(current)]);
                current = parent(current);
            }
        }

        int extract_min() {
            if (size <= 0) {
                cout << "Heap is empty!" << endl;
                return -1;
            }
            if (size == 1) {
                size--;
                return heap[0];
            }

            int root = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);

            return root;
        }

        int get_min() {
            if (size <= 0) {
                cout << "Heap is empty!" << endl;
                return -1;
            }
            return heap[0];
        }
};

int main() {
    MaxHeap maxHeap(10);
    maxHeap.insert(20);
    maxHeap.insert(15);
    maxHeap.insert(30);
    maxHeap.insert(40);
    maxHeap.insert(10);
    cout << "Max Heap:" << endl;
    cout << "Max Element: " << maxHeap.get_max() << endl;
    cout << "Extract Max: " << maxHeap.extract_max() << endl;
    cout << "Max Element after extraction: " << maxHeap.get_max() << endl;

    MinHeap minHeap(10);
    minHeap.insert(20);
    minHeap.insert(15);
    minHeap.insert(30);
    minHeap.insert(40);
    minHeap.insert(10);
    cout << "Min Heap:" << endl;
    cout << "Min Element: " << minHeap.get_min() << endl;
    cout << "Extract Min: " << minHeap.extract_min() << endl;
    cout << "Min Element after extraction: " << minHeap.get_min() << endl;
    return 0;
}
