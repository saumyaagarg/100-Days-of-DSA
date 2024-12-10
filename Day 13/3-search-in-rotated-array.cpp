// Solve the "search in a rotated sorted array" problem.

#include <iostream>
using namespace std;

// Function to perform binary search on a rotated sorted array
int rotated_array_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if the target is at mid
        if (arr[mid] == target) {
            return mid;
        }

        // Determine which half is sorted
        if (arr[low] <= arr[mid]) {
            // Left half is sorted
            if (target >= arr[low] && target < arr[mid]) {
                high = mid - 1; // Search in the left half
            } else {
                low = mid + 1;  // Search in the right half
            }
        } else {
            // Right half is sorted
            if (target > arr[mid] && target <= arr[high]) {
                low = mid + 1;  // Search in the right half
            } else {
                high = mid - 1; // Search in the left half
            }
        }
    }
    return -1; 
}

int main() {
    int arr[] = {4, 5, 6, 7, 0, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 0;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int result = rotated_array_search(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    return 0;
}
