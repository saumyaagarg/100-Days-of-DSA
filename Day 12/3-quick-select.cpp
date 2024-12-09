// Solve the "find kth smallest/largest element in an array" problem using Quick Select.

#include <iostream>
using namespace std;

// Partition function for Quick Select
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as the pivot
    int i = low + 1;      // Pointer for smaller elements
    int j = high;         // Pointer for larger elements

    while (true) {
        // Move i to the right for elements less than or equal to pivot
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        // Move j to the left for elements greater than pivot
        while (i <= j && arr[j] > pivot) {
            j--;
        }

        // If pointers cross, break the loop
        if (i >= j) {
            break;
        }

        // Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
    }

    // Place the pivot in its correct position
    swap(arr[low], arr[j]);
    return j; // Return the pivot's index
}

// Quick Select function
int quick_select(int arr[], int low, int high, int k) {
    if (low <= high) {
        // Partition the array
        int pivot_index = partition(arr, low, high);

        // Check if pivot is the kth element
        if (pivot_index == k) {
            return arr[pivot_index];
        } else if (pivot_index > k) {
            // If kth element is in the left subarray
            return quick_select(arr, low, pivot_index - 1, k);
        } else {
            // If kth element is in the right subarray
            return quick_select(arr, pivot_index + 1, high, k);
        }
    }
    return -1; // Return -1 if k is invalid
}

// Helper function to find kth smallest or largest element
void find_kth_element(int arr[], int n, int k, bool is_smallest) {
    if (k < 1 || k > n) {
        cout << "Invalid value of k!" << endl;
        return;
    }

    // If kth smallest is required
    if (is_smallest) {
        cout << "The " << k << "th smallest element is: " << quick_select(arr, 0, n - 1, k - 1) << endl;
    } else {
        // For kth largest, convert it to the kth smallest problem
        cout << "The " << k << "th largest element is: " << quick_select(arr, 0, n - 1, n - k) << endl;
    }
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k;
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl << "Enter the value of k: ";
    cin >> k;
    // Find kth smallest element
    find_kth_element(arr, n, k, true);
    // Find kth largest element
    find_kth_element(arr, n, k, false);
    return 0;
}
