// Solve the "trap rainwater" problem using two pointers.

#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate the total trapped water
int trap_rainwater(int arr[], int n) {
    int left = 0, right = n - 1;        // Two pointers
    int left_max = 0, right_max = 0;    // Max height to the left and right
    int water_trapped = 0;

    while (left <= right) {
        if (arr[left] <= arr[right]) {
            if (arr[left] >= left_max) {
                left_max = arr[left];   // Update left_max
            } else {
                water_trapped += left_max - arr[left]; // Water trapped at left pointer
            }
            left++;     // Move left pointer to the right
        } else {
            if (arr[right] >= right_max) {
                right_max = arr[right]; // Update right_max
            } else {
                water_trapped += right_max - arr[right]; // Water trapped at right pointer
            }
            right--;    // Move right pointer to the left
        }
    }

    return water_trapped;
}

int main() {
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = trap_rainwater(arr, n);
    cout << "Total water trapped: " << result << " units" << endl;
    return 0;
}
