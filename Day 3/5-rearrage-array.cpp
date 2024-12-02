// Solve the problem of rearranging an array with alternate positive and negative numbers.

#include <iostream>
using namespace std;

// Function to rearrange array with alternate positive and negative numbers
void rearrange_arr(int arr[], int n) {
    int pos[n], neg[n];
    int posIndex = 0, negIndex = 0;

    // Separate positives and negatives into two different arrays
    for (int i = 0; i < n; i++) {
        if (arr[i] >= 0) {
            pos[posIndex++] = arr[i];
        }
        else {
            neg[negIndex++] = arr[i];
        }
    }

    int i = 0, p = 0, q = 0;

    // Place elements from positives and negatives alternately
    while (p < posIndex && q < negIndex) {
        arr[i++] = pos[p++];
        arr[i++] = neg[q++];
    }

    // If there are remaining positives, add them
    while (p < posIndex) {
        arr[i++] = pos[p++];
    }

    // If there are remaining negatives, add them
    while (q < negIndex) {
        arr[i++] = neg[q++];
    }
    cout << "Rearranged Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    rearrange_arr(arr, n);
    delete[] arr;
    return 0;
}
