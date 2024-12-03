// Write a program to find the contiguous subarray with the maximum sum in O(n) time.

#include <iostream>
#include <climits>
using namespace std;

void max_subarray_sum(int arr[], int n) {
    int max_sum = INT_MIN;  // Store the maximum sum
    int cum_sum = 0;        // Track the running cumulative sum
    int min_sum = 0;        // Track the minimum cumulative sum encountered so far

    // To store the starting and ending indices of the subarray with the maximum sum
    int start = 0, end = 0, temp_start = 0;

    for (int i = 0; i < n; i++) {
        cum_sum += arr[i]; // Update the cumulative sum

        // Check if the current subarray gives a larger sum
        if (cum_sum - min_sum > max_sum) {
            max_sum = cum_sum - min_sum;
            start = temp_start;
            end = i;
        }

        // Update the minimum cumulative sum and potential start of the subarray
        if (cum_sum < min_sum) {
            min_sum = cum_sum;
            temp_start = i + 1;
        }
    }

    // Print the result
    cout << "The maximum sum of a contiguous subarray is: " << max_sum << endl;
    cout << "The subarray with the maximum sum is: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    max_subarray_sum(arr, n);
    delete[] arr;
    return 0;
}
