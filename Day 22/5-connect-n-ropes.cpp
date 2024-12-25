// Solve the "connect n ropes to minimize cost" problem using a priority queue.

#include <iostream>
#include <queue>
using namespace std;

#define MAX 100 // Maximum number of ropes

void connect_ropes(int ropes[], int n) {
    priority_queue<int, vector<int>, greater<int>> min_heap; // Min heap to store rope lengths

    // Step 1: Insert all the ropes into the min heap
    for (int i = 0; i < n; i++) {
        min_heap.push(ropes[i]);
    }

    int tot_cost = 0;

    // Step 2: Connect ropes while more than one rope remains
    while (min_heap.size() > 1) {
        // Get the two shortest ropes
        int first = min_heap.top();
        min_heap.pop();
        int second = min_heap.top();
        min_heap.pop();

        // The cost to connect them is the sum of their lengths
        int cost = first + second;
        tot_cost += cost;

        // Insert the new rope back into the heap
        min_heap.push(cost);
    }

    // Step 3: Output the minimum total cost
    cout << "Minimum cost to connect all ropes: " << tot_cost << endl;
}

int main() {
    int ropes[MAX] = {4, 3, 2, 6}; 
    int n = 4;  // Number of ropes
    connect_ropes(ropes, n);
    return 0;
}
