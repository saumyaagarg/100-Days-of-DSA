    // Solve the "unique paths" problem in a grid using dynamic programming.

    #include <iostream>
    using namespace std;

    #define MAX 100

    // Function to calculate the number of unique paths in a grid
    int unique_paths(int m, int n) {
        int dp[MAX][MAX]; // 2D array to store the number of paths to each cell

        // Initialize the first row and first column to 1 (only one way to reach these cells)
        for (int i = 0; i < m; i++) {
            dp[i][0] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[0][j] = 1;
        }

        // Fill the dp array
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; // Sum of paths from top and left
            }
        }

        return dp[m - 1][n - 1]; // Return the total number of paths to the bottom-right corner
    }

    int main() {
        int m, n;
        cout << "Enter the number of rows: ";
        cin >> m;
        cout << "Enter the number of columns: ";
        cin >> n;

        cout << "Number of unique paths: " << unique_paths(m, n) << endl;
        return 0;
    }
