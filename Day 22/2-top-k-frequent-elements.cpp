// Solve the "top k frequent elements" problem using a priority queue.

#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

#define MAX 1000        // Maximum size for input array

struct ElementFrequency {
    int element;
    int frequency;
    bool operator<(const ElementFrequency &other) const {
        return frequency > other.frequency; // Min Heap property
    }
};

void top_k_frequent(int nums[], int n, int k, int result[]) {
    unordered_map<int, int> freqMap;

    // Step 1: Calculate frequencies
    for (int i = 0; i < n; i++) {
        freqMap[nums[i]]++;
    }

    // Step 2: Use a Min Heap to store the top k elements
    priority_queue<ElementFrequency> min_heap;

    for (auto &entry : freqMap) {
        min_heap.push({entry.first, entry.second});
        if (min_heap.size() > k) {
            min_heap.pop();
        }
    }

    // Step 3: Extract elements from the Min Heap
    int index = 0;
    while (!min_heap.empty()) {
        result[index++] = min_heap.top().element;
        min_heap.pop();
    }
}

int main() {
    int nums[MAX] = {1, 1, 1, 2, 2, 3};
    int n = 6; // Number of elements in the array
    int k = 2; // Number of top frequent elements to find
    int result[MAX];
    top_k_frequent(nums, n, k, result);
    cout << "Top " << k << " frequent elements: ";
    for (int i = 0; i < k; i++) {
        cout << result[i] << " ";
    }
    return 0;
}
