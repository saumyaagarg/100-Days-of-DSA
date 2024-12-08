// Implement Selection Sort and analyze its time complexity.

#include <iostream>
using namespace std;

// Function to perform Selection Sort
void selection_sort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;             // Assume the first element is the smallest
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;         // Update the index of the smallest element
            }
        }
        // Swap the found minimum element with the first element of the unsorted part
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 50, 20, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Original array: ";
    print_array(arr, n);
    selection_sort(arr, n);
    cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}
