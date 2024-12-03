// Write a function to rotate an array to the left by k positions.

#include <iostream>
using namespace std;

// Function to reverse a portion of the array
void reverse(int arr[], int start, int end) {
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}

// Function to rotate an array to the left by k positions
void rotate_left(int arr[], int n, int k) {
    k = k % n; // Handle cases where k >= n

    // Step 1: Reverse the first k elements
    reverse(arr, 0, k - 1);

    // Step 2: Reverse the remaining n-k elements
    reverse(arr, k, n - 1);

    // Step 3: Reverse the entire array
    reverse(arr, 0, n - 1);
}

int main() {
    int n, k;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Enter the number of positions to rotate: ";
    cin >> k;
    rotate_left(arr, n, k);
    cout << "The rotated array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
