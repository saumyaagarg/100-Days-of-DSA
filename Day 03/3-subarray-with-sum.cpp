#include <iostream>
using namespace std;

// Function to locate all subarrays with the given sum
void find_subarrays(int arr[], int n, int target_sum) {
    int i = 0, current_sum = 0;

    // Iterate through the array
    for (int j = 0; j < n; j++) {
        // Add the current element to the running sum
        current_sum += arr[j];

        // Shrink the window if the sum exceeds the target
        while (current_sum > target_sum && i < j) {
            current_sum -= arr[i];
            i++;
        }

        // If the current sum matches the target sum, print the subarray
        if (current_sum == target_sum) {
            cout << "Subarray with the target sum " << target_sum
                 << " is found from index " << i << " to " << j << "." << endl;
        }
    }

    // If no subarray with the given sum is found
    if (current_sum != target_sum) {
        cout << "No subarray with the target sum found." << endl;
    }
}

int main() {
    int n, target_sum;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the target sum: ";
    cin >> target_sum;

    // Find all subarrays with the target sum
    find_subarrays(arr, n, target_sum);

    delete[] arr;
    return 0;
}
