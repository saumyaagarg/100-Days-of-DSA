// Solve the "coin change problem" (minimum coins required).

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAX_COINS 100       // Maximum number of coin denominations
#define MAX_AMOUNT 1000     // Maximum amount

// Function to find the minimum number of coins required to make a given amount
int coin_change(int coins[], int num_coins, int amount) {
    int dp[MAX_AMOUNT + 1]; // Array to store the minimum coins for each amount

    // Initialize the dp array
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;    // Initialize all values as infinite
    }
    dp[0] = 0;  // Base case: 0 coins are needed to make amount 0

    // Fill the dp array
    for (int i = 1; i <= amount; i++) {
        for (int j = 0; j < num_coins; j++) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    // If no combination can produce the amount, return -1
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5}; 
    int num_coins = sizeof(coins) / sizeof(coins[0]);  
    int amount = 11; 
    int result = coin_change(coins, num_coins, amount);
    if (result == -1) {
        cout << "It is not possible to make the amount with the given coins." << endl;
    } else {
        cout << "Minimum coins required to make the amount: " << result << endl;
    }
    return 0;
}
