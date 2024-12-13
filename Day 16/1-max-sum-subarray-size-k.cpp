// Solve the "maximum sum subarray of size k" problem.

#include <iostream>
using namespace std;

int max_sum_subarray(int arr[], int n, int k) {
    if (n < k) {
        cout << "Invalid input: Array size is smaller than k." << endl;
        return -1;
    }

    // Calculate the sum of the first window of size k
    int max_sum = 0;
    for (int i = 0; i < k; i++) {
        max_sum += arr[i];
    }

    // Sliding window to calculate sum of remaining subarrays of size k
    int window_sum = max_sum;
    for (int i = k; i < n; i++) {
        window_sum += arr[i] - arr[i - k];  // Slide the window
        max_sum = max(max_sum, window_sum); // Update the maximum sum
    }

    return max_sum;
}

int main() {
    int arr[] = {2, 1, 5, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Enter the value of k: ";
    cin >> k;
    int result = max_sum_subarray(arr, n, k);
    if (result != -1) {
        cout << "Maximum sum of subarray of size " << k << " is: " << result << endl;
    }
    return 0;
}
