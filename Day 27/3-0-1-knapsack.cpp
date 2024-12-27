// Solve the "0/1 knapsack problem" using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX_ITEMS 100       // Maximum number of items
#define MAX_CAPACITY 1000   // Maximum capacity of the knapsack

// Function to solve the 0/1 Knapsack problem
int knapsack(int weights[], int values[], int num_items, int capacity) {
    int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];    // 2D array to store the DP values

    // Initialize the dp array
    memset(dp, 0, sizeof(dp));

    // Build the dp table
    for (int i = 1; i <= num_items; i++) {
        for (int w = 0; w <= capacity; w++) {
            if (weights[i - 1] <= w) {
                // Include the current item
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + values[i - 1]);
            } else {
                // Exclude the current item
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // The maximum value is stored in dp[num_items][capacity]
    return dp[num_items][capacity];
}

int main() {
    int weights[] = {1, 2, 3, 2};  
    int values[] = {10, 15, 40, 20}; 
    int num_items = sizeof(weights) / sizeof(weights[0]); 
    int capacity = 5; 
    cout << "Maximum value in knapsack: " << knapsack(weights, values, num_items, capacity) << endl;
    return 0;
}
