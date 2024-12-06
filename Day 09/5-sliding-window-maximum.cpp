// Solve the "sliding window maximum" problem using a deque.

#include <iostream>
#include <deque>
using namespace std;

void sliding_window_maximum(int arr[], int n, int k) {
    // Create a deque to store indices of elements in the window
    deque<int> dq;

    // Loop through the array
    for (int i = 0; i < n; i++) {
        // Remove elements from the front of the deque if they're out of the current window
        if (!dq.empty() && dq.front() <= i - k)
            dq.pop_front();

        // Remove elements from the back of the deque if they are smaller than the current element because they are not useful for future windows
        while (!dq.empty() && arr[dq.back()] <= arr[i])
            dq.pop_back();

        // Add the current element's index to the deque
        dq.push_back(i);

        // The first element in the deque is the maximum element in the current window
        if (i >= k - 1)
            cout << arr[dq.front()] << " ";
    }
    cout << endl;
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the size of the sliding window: ";
    cin >> k;
    // Checking if the window size is valid
    if (k <= 0 || k > n) {
        cout << "Invalid window size!" << endl;
        return 0;
    }
    cout << "Sliding window maximums: ";
    sliding_window_maximum(arr, n, k);
    return 0;
}
