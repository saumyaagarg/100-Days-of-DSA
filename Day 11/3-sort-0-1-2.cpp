// Solve the "sort an array of 0s, 1s, and 2s" problem.

#include <iostream>
using namespace std;

// Function to sort an array of 0s, 1s, and 2s
void sort_array(int arr[], int n) {
    int low = 0, mid = 0, high = n - 1;

    while (mid <= high) {
        if (arr[mid] == 0) {
            // Swap arr[low] and arr[mid], increment low and mid
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        } else if (arr[mid] == 1) {
            // Move mid pointer
            mid++;
        } else { 
            // arr[mid] == 2
            // Swap arr[mid] and arr[high], decrement high
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

void print_array(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {0, 1, 2, 1, 0, 2, 1, 0, 2};
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Original array: ";
    print_array(arr, n);
    sort_array(arr, n);
    cout << "Sorted array: ";
    print_array(arr, n);
    return 0;
}
