// Create a program to count the number of occurrences of a given element in an array.

#include <iostream>
using namespace std;

// Function to count the occurrences of an element in the array
void occurrences(int arr[], int n, int x) {
    int count = 0; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {     // Check if the current element matches x
            count++;           // Increment counter if there's a match
        }
    }
    cout << "There are " << count << " occurrences of element " << x << "." << endl;
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
    int x;
    cout << "Enter element whose number of occurrences to check: ";
    cin >> x;
    occurrences(arr, n, x);
    delete[] arr;
    return 0;
}
