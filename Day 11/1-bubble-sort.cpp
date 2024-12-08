// Implement Bubble Sort and analyze its time complexity.

#include <iostream>
using namespace std;

// Function to perform Bubble Sort
void bubble_sort(int arr[], int n) {
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false; // Track if a swap was made in this pass
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        // If no two elements were swapped, the array is already sorted
        if (!swapped) break;
    }
}

// Function to print an array
void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {1, 4, 2, 6, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Original array: ";
    print_array(arr, n);
    bubble_sort(arr, n);
    cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}
