// Implement a program to find the peak element in an array using binary search.

#include <iostream>
using namespace std;

// Function to find the peak element using binary search
int peak_element(int arr[], int low, int high) {
    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid is the peak element
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == high || arr[mid + 1] <= arr[mid])) {
            return mid; // Found peak element
        }

        // If the element on the left is greater, move to the left half
        else if (mid > 0 && arr[mid - 1] > arr[mid]) {
            high = mid - 1;
        }
        // If the element on the right is greater, move to the right half
        else {
            low = mid + 1;
        }
    }
    return -1; 
}

int main() {
    int arr[] = {1, 3, 20, 4, 1, 0}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    cout << "Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int peakIndex = peak_element(arr, 0, n - 1);
    if (peakIndex != -1) {
        cout << "Peak element is: " << arr[peakIndex] << " at index " << peakIndex << endl;
    } else {
        cout << "No peak element found." << endl;
    }
    return 0;
}
