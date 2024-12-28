// Solve the "rod cutting" problem using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to find the maximum profit from cutting the rod
int rod_cutting(int length[], int price[], int n, int rod_length) {
    int dp[MAX][MAX]; // 2D array to store maximum profit

    // Initialize the dp array
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= rod_length; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;   // Base case: No rod or no length to cut
            } else if (length[i - 1] <= j) {
                // Max profit by including or excluding the current length
                dp[i][j] = max(price[i - 1] + dp[i][j - length[i - 1]], dp[i - 1][j]);
            } else {
                // Exclude the current length
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][rod_length];   // Maximum profit
}

int main() {
    int length[] = {1, 2, 3, 4, 5};     // Possible lengths
    int price[] = {2, 5, 7, 8, 10};     // Corresponding prices
    int rod_length = 5;                 // Length of the rod
    int n = sizeof(length) / sizeof(length[0]);
    cout << "Maximum Profit: " << rod_cutting(length, price, n, rod_length) << endl;
    return 0;
}
