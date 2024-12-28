// Solve the "partition equal subset sum" problem using dynamic programming.

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum sum for the subset

// Function to check if it's possible to partition the array into two subsets with equal sum
bool can_partition(int arr[], int n) {
    int sum = 0;

    // Calculate the total sum of the elements in the array
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }

    // If the total sum is odd, partition is not possible
    if (sum % 2 != 0) {
        return false;
    }

    int target = sum / 2;   // The target sum for one subset

    // dp[i] will be true if a subset with sum i can be formed
    bool dp[target + 1];
    memset(dp, false, sizeof(dp));  // Initialize all dp values to false
    dp[0] = true;   // Base case: a sum of 0 is always possible (empty subset)

    // Fill the dp array
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= arr[i]; j--) {
            if (dp[j - arr[i]]) {
                dp[j] = true;
            }
        }
    }

    // The answer will be stored in dp[target], if it's true
    return dp[target];
}

int main() {
    int arr[] = {1, 5, 11, 5}; 
    int n = sizeof(arr) / sizeof(arr[0]);  
    if (can_partition(arr, n)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
    return 0;
}
