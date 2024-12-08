// Implement Insertion Sort and count the number of shifts/swaps during sorting.

#include <iostream>
using namespace std;

// Function to perform Insertion Sort and count shifts
int insertion_sort(int arr[], int n) {
    int count = 0; 

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        // Shift elements of arr[0..i-1] that are greater than key
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
            count++; // Increment shift counter
        }

        // Place the key in its correct position
        arr[j + 1] = key;
        count++; // Increment for the final placement of key
    }

    return count;
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {5, 3, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    print_array(arr, n);
    int shiftCount = insertion_sort(arr, n);
    cout << "Sorted array: ";
    print_array(arr, n);
    cout << "Number of shifts: " << shiftCount << endl;
    return 0;
}
