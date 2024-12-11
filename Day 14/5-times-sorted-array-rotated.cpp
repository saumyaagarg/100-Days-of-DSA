// Solve the "number of times a sorted array is rotated" problem.

#include <iostream>
using namespace std;

// Function to find the number of rotations in a sorted and rotated array
int rotation_count(int arr[], int n) {
    int low = 0, high = n - 1;

    while (low <= high) {
        // If the array segment is already sorted, the minimum is at `low`
        if (arr[low] <= arr[high]) {
            return low;
        }

        int mid = low + (high - low) / 2;
        int next = (mid + 1) % n;       // Next element (circular index)
        int prev = (mid - 1 + n) % n;   // Previous element (circular index)

        // Check if the mid element is the smallest
        if (arr[mid] <= arr[next] && arr[mid] <= arr[prev]) {
            return mid;
        }

        // Decide which half to search next
        if (arr[mid] <= arr[high]) {
            high = mid - 1;     // Go to the left half
        } else {
            low = mid + 1;      // Go to the right half
        }
    }

    return -1; // This should not happen for a valid rotated sorted array
}

int main() {
    int arr[] = {15, 18, 2, 3, 6, 12}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int rot_count = rotation_count(arr, n);
    cout << "The array is rotated " << rot_count << " times." << endl;
    return 0;
}
