// Solve the "maximum sum of non-adjacent elements in an array" problem.

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum array size

// Function to find the maximum sum of non-adjacent elements using dynamic programming
int max_sum_non_adjacent(int arr[], int n) {
    if (n == 0) return 0;       // No elements, no sum
    if (n == 1) return arr[0];  // Only one element, return it

    int dp[MAX]; // Array to store the maximum sum up to each index
    memset(dp, 0, sizeof(dp));  // Initialize with 0

    dp[0] = max(0, arr[0]);     // Base case: Maximum sum at the first element
    dp[1] = max(dp[0], arr[1]); // Base case: Maximum sum at the second element

    // Fill the dp array
    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i]); // Include or exclude the current element
    }

    return dp[n - 1];   // Maximum sum up to the last element
}

int main() {
    int arr[] = {3, 2, 7, 10}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum sum of non-adjacent elements: " << max_sum_non_adjacent(arr, n) << endl;
    return 0;
}
