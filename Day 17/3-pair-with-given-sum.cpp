// Solve the "find a pair with a given sum in a sorted array" problem using two pointers.

#include <iostream>
using namespace std;

// Function to find a pair with the given sum k
bool find_pair_with_sum(int arr[], int n, int k) {
    int left = 0;       // Start pointer
    int right = n - 1;  // End pointer

    while (left < right) {
        int current_sum = arr[left] + arr[right];

        // Check if the current sum matches the target
        if (current_sum == k) {
            cout << "Pair found: (" << arr[left] << ", " << arr[right] << ")" << endl;
            return true;
        }
        // If the current sum is less, move the left pointer to the right
        else if (current_sum < k) {
            left++;
        }
        // If the current sum is greater, move the right pointer to the left
        else {
            right--;
        }
    }

    cout << "No pair found with the given sum." << endl;
    return false;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 10; 
    find_pair_with_sum(arr, n, k);
    return 0;
}
