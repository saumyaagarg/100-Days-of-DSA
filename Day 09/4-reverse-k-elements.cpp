// Solve the "reverse first k elements of a queue" problem.

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverse_first_k_elements(queue<int> &q, int k) {
    // If k is greater than the size of the queue, we do nothing.
    if (k <= 0 || k > q.size())
        return;

    stack<int> s;

    // Step 1: Dequeue the first k elements and push them into a stack
    for (int i = 0; i < k; i++) {
        s.push(q.front());
        q.pop();
    }

    // Step 2: Enqueue the elements from the stack to the queue (reversed order)
    while (!s.empty()) {
        q.push(s.top());
        s.pop();
    }

    // Step 3: Dequeue the remaining elements and enqueue them back to the queue
    int remainingElements = q.size() - k;
    for (int i = 0; i < remainingElements; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    int n, k;
    cout << "Enter the size of the queue: ";
    cin >> n;
    cout << "Enter the elements of the queue: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        q.push(val);
    }
    cout << "Enter the value of k (number of elements to reverse): ";
    cin >> k;
    reverse_first_k_elements(q, k);
    cout << "Queue after reversing the first " << k << " elements: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    return 0;
}
