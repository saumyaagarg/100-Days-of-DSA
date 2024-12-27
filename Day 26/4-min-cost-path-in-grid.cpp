// Solve the "minimum cost path in a grid" problem using dynamic programming.

#include <iostream>
#include <climits>
using namespace std;

#define MAX 100     // Maximum grid size

// Function to find the minimum cost path in a grid using dynamic programming
int min_cost_path(int grid[MAX][MAX], int rows, int cols) {
    int dp[MAX][MAX];   // Array to store the minimum cost to each cell

    // Initialize the base case for the top-left corner
    dp[0][0] = grid[0][0];

    // Fill the first row
    for (int j = 1; j < cols; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // Fill the first column
    for (int i = 1; i < rows; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Fill the rest of the grid
    for (int i = 1; i < rows; i++) {
        for (int j = 1; j < cols; j++) {
            dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Return the minimum cost to reach the bottom-right corner
    return dp[rows - 1][cols - 1];
}

int main() {
    int grid[MAX][MAX] = {
        {1, 3, 1},
        {1, 5, 1},
        {4, 2, 1}
    };
    int rows = 3, cols = 3; 
    cout << "The minimum cost to reach the bottom-right corner is: " << min_cost_path(grid, rows, cols);
    return 0;
}
