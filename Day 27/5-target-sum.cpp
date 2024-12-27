// Solve the "target sum" problem using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_N 100       // Maximum number of elements in the array
#define MAX_SUM 2000    // Maximum possible absolute sum (positive + negative)

// Function to calculate the number of ways to assign signs to reach target sum
int target_sum(int arr[], int n, int target) {
    int dp[MAX_N][MAX_SUM * 2 + 1]; // DP table with offset for negative indices
    int offset = MAX_SUM;           // Offset to handle negative indices

    memset(dp, 0, sizeof(dp));      // Initialize dp table to 0
    dp[0][offset] = 1;              // Base case: one way to make sum 0 with no elements

    // Fill the dp table
    for (int i = 1; i <= n; i++) {
        for (int sum = -MAX_SUM; sum <= MAX_SUM; sum++) {
            if (dp[i - 1][sum + offset] > 0) {
                dp[i][sum + arr[i - 1] + offset] += dp[i - 1][sum + offset];
                dp[i][sum - arr[i - 1] + offset] += dp[i - 1][sum + offset];
            }
        }
    }

    // Return the number of ways to reach the target sum
    return dp[n][target + offset];
}

int main() {
    int arr[] = {1, 1, 1, 1, 1};  
    int n = sizeof(arr) / sizeof(arr[0]); 
    int target = 3;      
    int result = target_sum(arr, n, target);
    cout << "Number of ways to reach the target sum: " << result << endl;
    return 0;
}
