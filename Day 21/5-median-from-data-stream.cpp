// Solve the "find median from a data stream" problem using two heaps.

#include <iostream>
#include <queue>
#include <functional>
using namespace std;

#define MAX 1000        // Maximum size for the heaps

class MedianFinder {
private:
    int maxHeap[MAX];  // Max Heap to store the smaller half of the numbers
    int minHeap[MAX];  // Min Heap to store the larger half of the numbers
    int maxHeapSize;   // Current size of Max Heap
    int minHeapSize;   // Current size of Min Heap

    // Helper functions for Max Heap
    void max_heapify(int idx) {
        int largest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < maxHeapSize && maxHeap[left] > maxHeap[largest])
            largest = left;

        if (right < maxHeapSize && maxHeap[right] > maxHeap[largest])
            largest = right;

        if (largest != idx) {
            swap(maxHeap[idx], maxHeap[largest]);
            max_heapify(largest);
        }
    }

    void insert_max_heap(int value) {
        maxHeap[maxHeapSize] = value;
        int current = maxHeapSize;
        maxHeapSize++;

        while (current > 0 && maxHeap[(current - 1) / 2] < maxHeap[current]) {
            swap(maxHeap[current], maxHeap[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    int extract_max() {
        int root = maxHeap[0];
        maxHeap[0] = maxHeap[--maxHeapSize];
        max_heapify(0);
        return root;
    }

    // Helper functions for Min Heap
    void min_heapify(int idx) {
        int smallest = idx;
        int left = 2 * idx + 1;
        int right = 2 * idx + 2;

        if (left < minHeapSize && minHeap[left] < minHeap[smallest])
            smallest = left;

        if (right < minHeapSize && minHeap[right] < minHeap[smallest])
            smallest = right;

        if (smallest != idx) {
            swap(minHeap[idx], minHeap[smallest]);
            min_heapify(smallest);
        }
    }

    void insert_min_heap(int value) {
        minHeap[minHeapSize] = value;
        int current = minHeapSize;
        minHeapSize++;

        while (current > 0 && minHeap[(current - 1) / 2] > minHeap[current]) {
            swap(minHeap[current], minHeap[(current - 1) / 2]);
            current = (current - 1) / 2;
        }
    }

    int extract_min() {
        int root = minHeap[0];
        minHeap[0] = minHeap[--minHeapSize];
        min_heapify(0);
        return root;
    }

public:
    MedianFinder() {
        maxHeapSize = 0;
        minHeapSize = 0;
    }

    void addNum(int num) {
        if (maxHeapSize == 0 || num <= maxHeap[0]) {
            insert_max_heap(num);
        } else {
            insert_min_heap(num);
        }

        // Balance the heaps
        if (maxHeapSize > minHeapSize + 1) {
            insert_min_heap(extract_max());
        } else if (minHeapSize > maxHeapSize) {
            insert_max_heap(extract_min());
        }
    }

    double find_median() {
        if (maxHeapSize == minHeapSize)
            return (maxHeap[0] + minHeap[0]) / 2.0;
        return maxHeap[0];
    }
};

int main() {
    MedianFinder mf;
    // Simulate adding numbers to the data stream
    int nums[] = {5, 2, 1, 3, 8, 7, 9};
    int n = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < n; i++) {
        mf.addNum(nums[i]);
        cout << "Median after adding " << nums[i] << ": " << mf.find_median() << endl;
    }
    return 0;
}
