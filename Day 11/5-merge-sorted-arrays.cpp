#include <iostream>
#include <algorithm>  // For sort() function
using namespace std;

// Function to merge two sorted arrays into one sorted array in-place
void merge_arrays(int arr1[], int arr2[], int n, int m) {
    int i = n - 1;  // Pointer for the last element of arr1
    int j = 0;      // Pointer for the first element of arr2

    // Traverse both arrays
    while (i >= 0 && j < m) {
        // If arr1[i] is greater than arr2[j], swap them
        if (arr1[i] > arr2[j]) {
            // Swap arr1[i] and arr2[j]
            swap(arr1[i], arr2[j]);
            
            // Move the pointers
            i--;
            j++;
        } else {
            break;  // No need to swap if arr1[i] <= arr2[j]
        }
    }

    // After swapping, arr1 and arr2 might still not be sorted, so sort both arrays
    sort(arr1, arr1 + n);  // Sort arr1
    sort(arr2, arr2 + m);  // Sort arr2
}

void print_array(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    };
}

int main() {
    int arr1[] = {1, 5, 9, 10, 15};
    int arr2[] = {2, 3, 8, 13};

    int n = sizeof(arr1) / sizeof(arr1[0]); // Size of arr1
    int m = sizeof(arr2) / sizeof(arr2[0]); // Size of arr2

    cout << "Original arrays: " << endl;
    cout << "Array 1: ";
    print_array(arr1, n);
    cout << endl;
    cout << "Array 2: ";
    print_array(arr2, m);
    cout << endl;
    merge_arrays(arr1, arr2, n, m);
    cout << "Merged and sorted array: ";
    // Print the combined arrays
    print_array(arr1, n);
    print_array(arr2, m);

    return 0;
}
