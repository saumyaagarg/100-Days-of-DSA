// Solve the "climbing stairs" problem using dynamic programming.

#include <iostream>
#include <cstring> 
using namespace std;

#define MAX 1000    // Maximum number of steps

// Function to calculate the number of ways to climb stairs using tabulation
int climbing_stairs_tabulation(int n) {
    if (n <= 1) {
        return 1;   // Base cases: 1 way to climb 0 or 1 step
    }

    int dp[MAX] = {0};  // Array to store the number of ways to climb each step
    dp[0] = 1;          // Base case: 1 way to climb 0 steps
    dp[1] = 1;          // Base case: 1 way to climb 1 step

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Transition relation
    }

    return dp[n];
}

// Function to calculate the number of ways to climb stairs using memoization
int memo[MAX];  // Array for memoization

int climbing_stairs_memoization(int n) {
    if (n <= 1) {
        return 1;   // Base cases: 1 way to climb 0 or 1 step
    }

    if (memo[n] != -1) {
        return memo[n];     // Return already computed value
    }

    memo[n] = climbing_stairs_memoization(n - 1) + climbing_stairs_memoization(n - 2);
    return memo[n];
}

int main() {
    int n;
    cout << "Enter the number of steps: ";
    cin >> n;
    // Tabulation solution
    cout << "Number of ways using tabulation: " << climbing_stairs_tabulation(n) << endl;
    // Memoization solution
    memset(memo, -1, sizeof(memo));     // Initialize memoization array
    cout << "Number of ways using memoization: " << climbing_stairs_memoization(n) << endl;
    return 0;
}
