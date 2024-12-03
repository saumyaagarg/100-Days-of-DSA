// Given an array containing n-1 distinct integers in the range of 1 to n, write a program to find the missing number in O(n) time using a mathematical formula or XOR.

#include <iostream>
using namespace std;

// Function to find the missing number using the sum formula
int missing_number(int arr[], int n) {
    // Calculate the expected sum of the first n natural numbers
    int correct_sum = n * (n + 1) / 2;

    // Calculate the sum of the given array elements
    int wrong_sum = 0;
    for (int i = 0; i < n - 1; i++) {
        wrong_sum += arr[i];
    }

    // Missing number is the difference between the expected sum and the actual sum
    int missing_num = correct_sum - wrong_sum;
    return missing_num;
}

int main() {
    int n;
    cout << "Enter the size of the array: "; 
    cin >> n;

    int *arr = new int[n - 1];        // Allocate memory for the array of size n-1 as one element is missing
    cout << "Enter the elements of the array: "; 
    for (int i = 0; i < n - 1; i++) {
        cin >> arr[i];
    }
    int a = missing_number(arr, n);
    cout << "The missing number is: " << a;
    delete[] arr; 
    return 0;
}
