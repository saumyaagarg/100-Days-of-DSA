//  Implement Quick Sort and analyze its time complexity.

#include <iostream>
using namespace std;

// Function to partition the array around the pivot
int partition(int arr[], int low, int high) {
    int pivot = arr[low]; // Choose the first element as pivot
    int i = low + 1;      // Index for smaller elements
    int j = high;         // Index for larger elements

    while (true) {
        // Find elements greater than or equal to pivot
        while (i <= j && arr[i] <= pivot) {
            i++;
        }

        // Find elements less than or equal to pivot
        while (i <= j && arr[j] > pivot) {
            j--;
        }

        if (i >= j) {
            break; // Pointers crossed; partition is complete
        }

        // Swap arr[i] and arr[j]
        swap(arr[i], arr[j]);
    }

    // Swap pivot with the element at j (correct position)
    swap(arr[low], arr[j]);
    return j; // Return pivot's final position
}

// Function to perform Quick Sort
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        // Partition the array
        int pivot_index = partition(arr, low, high);

        // Recursively sort elements before and after the pivot
        quick_sort(arr, low, pivot_index - 1);
        quick_sort(arr, pivot_index + 1, high);
    }
}

// Function to print an array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    print_array(arr, n);
    quick_sort(arr, 0, n - 1);
    cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}
