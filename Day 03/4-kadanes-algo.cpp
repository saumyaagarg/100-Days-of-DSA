// Implement Kadane's Algorithm to find the maximum sum subarray.

#include <iostream>
using namespace std;

// Function to implement Kadane's Algorithm to find the maximum sum subarray
void max_subarr(int arr[], int n) {
    int max_sum = arr[0], curr_sum = arr[0];
    int start = 0, end = 0, temp_start = 0;

    // Iterate through the array starting from the second element
    for (int i = 1; i < n; i++) {
        // Update current sum by choosing the maximum between the current element or adding it to the current sum
        if (arr[i] > curr_sum + arr[i]) {
            curr_sum = arr[i];
            temp_start = i;
        }
        else {
            curr_sum += arr[i];
        }

        // Update the maximum sum found so far
        if (curr_sum > max_sum) {
            max_sum = curr_sum;
            start = temp_start;
            end = i;
        }
    }

    cout << "Maximum subarray sum is: " << max_sum << endl;

    cout << "Subarray with maximum sum is: ";
    for (int i = start; i <= end; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    max_subarr(arr, n);
    delete[] arr;
    return 0;
}
