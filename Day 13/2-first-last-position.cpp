// Solve the "find the first and last position of an element in a sorted array" problem.

#include <iostream>
using namespace std;

// Function to find the first occurrence of the target
int find_first(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            first = mid;    // Update the first occurrence
            high = mid - 1; // Search in the left half
        } else if (arr[mid] > target) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1;  // Search in the right half
        }
    }
    return first;
}

// Function to find the last occurrence of the target
int find_last(int arr[], int n, int target) {
    int low = 0, high = n - 1;
    int last = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            last = mid;    // Update the last occurrence
            low = mid + 1; // Search in the right half
        } else if (arr[mid] > target) {
            high = mid - 1; // Search in the left half
        } else {
            low = mid + 1;  // Search in the right half
        }
    }
    return last;
}

int main() {
    int arr[] = {2, 4, 4, 4, 6, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 4;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int first = find_first(arr, n, target);
    int last = find_last(arr, n, target);
    if (first == -1) {
        cout << "Element " << target << " not found in the array." << endl;
    } else {
        cout << "First occurrence of " << target << ": " << first << endl;
        cout << "Last occurrence of " << target << ": " << last << endl;
    }
    return 0;
}
