// Implement Binary Search and use it to find an element in a sorted array.

#include <iostream>
using namespace std;

// Function to perform Binary Search
int binary_search(int arr[], int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2; // Calculate the middle index

        // Check if the middle element is the target
        if (arr[mid] == target) {
            return mid; 
        }

        // If the target is smaller, search in the left half
        if (arr[mid] > target) {
            high = mid - 1;
        }
        // If the target is larger, search in the right half
        else {
            low = mid + 1;
        }
    }
    return -1;
}

int main() {
    int arr[] = {1, 3, 5, 7, 9, 11, 13, 15};
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 7; 
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int result = binary_search(arr, 0, n - 1, target);
    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array." << endl;
    }
    return 0;
}
