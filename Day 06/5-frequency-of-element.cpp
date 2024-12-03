// Write a program to count the frequency of each element in an array in O(n) time without using extra space (modify the array temporarily if needed).

#include <iostream>
using namespace std;

//Function to count frequencies of each element in array
void count_frequencies(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        // Get the index of the current element, assuming elements are in the range [0, n-1]
        int index = arr[i] % n; // Use modulo to avoid out-of-bound access

        // Increment the value at the calculated index by n
        arr[index] += n;
    }

    for (int i = 0; i < n; i++) {
        // The frequency of the element at index 'i' is the number of times n has been added
        cout << "Element " << i << " appears " << arr[i] / n << " times." << endl;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] % n; // Restore the original array values
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
    count_frequencies(arr, n);
    delete[] arr;
    return 0;
}