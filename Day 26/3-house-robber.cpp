// Solve the "house robber" problem using dynamic programming.

#include <iostream>
#include <cstring> 
using namespace std;

#define MAX 1000    // Maximum number of houses

// Function to solve the House Robber problem using tabulation
int house_robber_tabulation(int houses[], int n) {
    if (n == 0) {
        return 0;   // No houses to rob
    }
    if (n == 1) {
        return houses[0];   // Only one house to rob
    }

    int dp[MAX] = {0};  // Array to store the maximum profit up to each house
    dp[0] = houses[0];  // Base case: Rob the first house
    dp[1] = max(houses[0], houses[1]);  // Base case: Max of robbing first or second house

    for (int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + houses[i]);  // Choose to rob or skip the current house
    }

    return dp[n - 1];
}

// Function to solve the House Robber problem using memoization
int memo[MAX];  // Array for memoization

int house_robber_memoization(int houses[], int n) {
    if (n == 0) {
        return 0;   // No houses to rob
    }
    if (n == 1) {
        return houses[0];   // Only one house to rob
    }
    if (memo[n] != -1) {
        return memo[n];     // Return the precomputed result
    }

    memo[n] = max(house_robber_memoization(houses, n - 1), house_robber_memoization(houses, n - 2) + houses[n - 1]);
    return memo[n];
}

int main() {
    int houses[] = {2, 7, 9, 3, 1}; // Amount of money in each house
    int n = sizeof(houses) / sizeof(houses[0]);
    // Tabulation solution
    cout << "Maximum profit using tabulation: " << house_robber_tabulation(houses, n) << endl;
    // Memoization solution
    memset(memo, -1, sizeof(memo)); // Initialize memoization array
    cout << "Maximum profit using memoization: " << house_robber_memoization(houses, n) << endl;
    return 0;
}
