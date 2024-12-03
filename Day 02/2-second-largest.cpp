// Implement a program to find the second largest element in an array.

#include <iostream>
#include <climits>
using namespace std;

// Function to find and display the second largest element in an array
void second_largest(int arr[], int n) {
    // Initialize the largest and second largest elements
    int largest = arr[0];
    int second = INT_MIN; // Use INT_MIN for second largest to handle edge cases

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            // Update second largest before changing the largest
            second = largest;
            largest = arr[i];
        }
        else if (arr[i] > second && arr[i] != largest) {
            // Update second largest if the current element is smaller than the largest
            second = arr[i];
        }
    }

    // Check if a valid second largest element exists
    if (second == INT_MIN) {
        cout << "Second largest element does not exist." << endl;
    }
    else {
        cout << "The second largest element is: " << second << endl;
    }
}

int main() {
    int n;
    cout << "Enter number of elements in array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    second_largest(arr, n);
    delete[] arr;
    return 0; 
}