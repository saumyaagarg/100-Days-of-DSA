// Solve the "three sum" problem using two pointers.

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find all unique triplets with a sum of zero
void three_sum(int arr[], int n) {
    sort(arr, arr + n);          // Sort the array for two-pointer approach

    for (int i = 0; i < n - 2; i++) {
        // Avoid duplicates for the first element
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        int target = -arr[i];   // Fix arr[i] and find two numbers with sum equal to -arr[i]
        int left = i + 1, right = n - 1;

        while (left < right) {
            int current_sum = arr[left] + arr[right];

            if (current_sum == target) {
                cout << "Triplet: (" << arr[i] << ", " << arr[left] << ", " << arr[right] << ")" << endl;

                // Avoid duplicates for the second and third elements
                while (left < right && arr[left] == arr[left + 1]) left++;
                while (left < right && arr[right] == arr[right - 1]) right--;

                left++;
                right--;
            } 
            else if (current_sum < target) {
                left++;         // Move left pointer to increase the sum
            } 
            else {
                right--;        // Move right pointer to decrease the sum
            }
        }
    }
}

int main() {
    int arr[] = {-1, 0, 1, 2, -1, -4};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unique triplets with sum zero:" << endl;
    three_sum(arr, n);
    return 0;
}
