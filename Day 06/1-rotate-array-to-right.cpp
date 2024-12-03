// Write a program to rotate an array of size n by k steps to the right in O(n) time without using extra space.

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

// Function to rotate the array
void rotateArray(int arr[], int n, int k) {
    // Handle cases where k > n
    k = k % n;

    // Step 1: Reverse the entire array
    reverse(arr, 0, n - 1);

    // Step 2: Reverse the first k elements
    reverse(arr, 0, k - 1);

    // Step 3: Reverse the remaining n-k elements
    reverse(arr, k, n - 1);
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
    cout << "Enter the number of steps to rotate: ";
    cin >> k;
    rotateArray(arr, n, k);
    cout << "The rotated array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
