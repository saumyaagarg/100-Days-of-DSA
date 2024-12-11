// Solve the "find the smallest missing positive integer" problem.

#include <iostream>
using namespace std;

// Function to place each number in its correct position
void place_numbers(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        while (arr[i] > 0 && arr[i] <= n && arr[arr[i] - 1] != arr[i]) {
            swap(arr[i], arr[arr[i] - 1]); // Place arr[i] at its correct index
        }
    }
}

// Function to find the smallest missing positive integer
int smallest_missing_positive(int arr[], int n) {
    place_numbers(arr, n);

    // Check for the first missing positive integer
    for (int i = 0; i < n; i++) {
        if (arr[i] != i + 1) {
            return i + 1;
        }
    }

    // If all numbers from 1 to n are present
    return n + 1;
}

int main() {
    int arr[] = {3, 4, -1, 1}; // Input array
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Input array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int result = smallest_missing_positive(arr, n);
    cout << "The smallest missing positive integer is: " << result << endl;

    return 0;
}
