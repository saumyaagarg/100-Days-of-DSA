// Rearrange an array such that the first element is the largest, the second is the smallest, the third is the second largest, and so on. Solve this in O(n) time using no extra space.

#include <iostream>
#include <algorithm>
using namespace std;

void rearrange_array(int arr[], int n) {
    // Initialize variables for maximum and minimum indices
    int max_idx = n - 1;                // Index for the largest element
    int min_idx = 0;                    // Index for the smallest element
    int max_elem = arr[max_idx] + 1;    // Store a number greater than the maximum element

    // Traverse the array and rearrange elements
    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            // Place the largest element at even indices
            arr[i] += (arr[max_idx] % max_elem) * max_elem;
            max_idx--;
        }
        else {
            // Place the smallest element at odd indices
            arr[i] += (arr[min_idx] % max_elem) * max_elem;
            min_idx++;
        }
    }

    // Divide all elements by max_elem to get the final rearranged array
    for (int i = 0; i < n; i++) {
        arr[i] /= max_elem;
    }
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    rearrange_array(arr, n);
    cout << "The rearranged array is: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}
