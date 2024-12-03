//  Write a program to find the largest and smallest elements in an array.

#include <iostream> 
using namespace std;

// Function to find and display the largest and smallest elements in an array
void min_max(int arr[], int n) {
    int largest = arr[0];  // Initialize the largest element as the first element
    int smallest = arr[0]; // Initialize the smallest element as the first element

    // Traverse the array to find the smallest and largest elements
    for (int i = 0; i < n; i++) {
        if (arr[i] < smallest) { // Update smallest if the current element is smaller
            smallest = arr[i];
        }
        else if (arr[i] > largest) { // Update largest if the current element is larger
            largest = arr[i];
        }
    }

    cout << "The largest element is: " << largest << endl;
    cout << "The smallest element is: " << smallest << endl;
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
    min_max(arr, n);
    delete[] arr;
    return 0;
}
