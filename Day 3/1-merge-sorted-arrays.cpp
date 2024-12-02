// Implement a function to merge two sorted arrays.

#include <iostream>
using namespace std;

// Function to merge two sorted arrays
void merge_sorted(int arr1[], int arr2[], int n1, int n2) {
    int resn = n1 + n2;           // Total size of the resulting merged array
    int *res_arr = new int[resn]; 
    int i = 0, j = 0, k = 0;

    // Traverse both arrays and merge them
    while (i < n1 || j < n2) {
        // All elements from arr1 are processed
        // Add remaining elements of arr2
        if (i == n1) {
            res_arr[k++] = arr2[j++]; 
        }
        // All elements from arr2 are processed
        // Add remaining elements of arr1
        else if (j == n2) {
            res_arr[k++] = arr1[i++]; 
        }
        // Element in arr1 is smaller
        else if (arr1[i] < arr2[j]) {
            res_arr[k++] = arr1[i++];
        }
        // Element in arr2 is smaller or equal
        else {
            res_arr[k++] = arr2[j++];
        }
    }

    cout << "The merged sorted array is: ";
    for (int i = 0; i < resn; i++) {
        cout << res_arr[i] << " ";
    }
    delete[] res_arr;
}

int main() {
    int n1, n2;
    cout << "Enter number of elements in array 1: ";
    cin >> n1;
    int *arr1 = new int[n1];
    cout << "Enter elements of arr1: ";
    for (int i = 0; i < n1; i++) {
        cin >> arr1[i];
    }

    cout << "Enter number of elements in array 2: ";
    cin >> n2;
    int *arr2 = new int[n2];
    cout << "Enter elements of arr2: ";
    for (int i = 0; i < n2; i++) {
        cin >> arr2[i];
    }

    merge_sorted(arr1, arr2, n1, n2);
    delete[] arr1;
    delete[] arr2;
    return 0;
}
