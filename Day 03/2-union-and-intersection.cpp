// Write a program to find the union and intersection of two arrays.

#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the union of two arrays
void arr_union(int arr1[], int arr2[], int n1, int n2) {
    // Combine both arrays into a temporary array
    int *temp_arr = new int[n1 + n2];
    int k = 0;

    // Copy elements of the first array into temp_arr
    for (int i = 0; i < n1; i++) {
        temp_arr[k++] = arr1[i];
    }
    // Copy elements of the second array into temp_arr
    for (int i = 0; i < n2; i++) {
        temp_arr[k++] = arr2[i];
    }

    // Sort the combined array to make duplicate removal easier
    sort(temp_arr, temp_arr + k);

    // Remove duplicates and store unique elements in res_arr
    int *res_arr = new int[k];
    int res_n = 0;
    for (int i = 0; i < k; i++) {
        if (i == 0 || temp_arr[i] != temp_arr[i - 1]) {
            res_arr[res_n++] = temp_arr[i];
        }
    }

    cout << "The union of arrays is: [ ";
    for (int i = 0; i < res_n; i++) {
        cout << res_arr[i] << " ";
    }
    cout << "]" << endl;
    delete[] temp_arr;
    delete[] res_arr;
}

// Function to calculate the intersection of two arrays
void arr_intersection(int arr1[], int arr2[], int n1, int n2) {
    // Sort both arrays to facilitate efficient comparison
    sort(arr1, arr1 + n1);
    sort(arr2, arr2 + n2);

    int i = 0, j = 0;
    int *res_arr = new int[min(n1, n2)];
    int k = 0;

    // Use two-pointer technique to find common elements
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            i++; // Move pointer in arr1 forward if its element is smaller
        }
        else if (arr1[i] > arr2[j]) {
            j++; // Move pointer in arr2 forward if its element is smaller
        }
        else {
            // Avoid adding duplicates to the result
            if (k == 0 || res_arr[k - 1] != arr1[i]) {
                res_arr[k++] = arr1[i];
            }
            i++;
            j++;
        }
    }

    cout << "The intersection of arrays is: [ ";
    for (int i = 0; i < k; i++) {
        cout << res_arr[i] << " ";
    }
    cout << "]" << endl;
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

    arr_union(arr1, arr2, n1, n2);
    arr_intersection(arr1, arr2, n1, n2);

    delete[] arr1;
    delete[] arr2;
    return 0;
}
