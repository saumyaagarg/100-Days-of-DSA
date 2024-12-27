// Solve the "longest common subsequence" problem.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum size for the strings

// Function to find the length of the longest common subsequence
int longest_common_subsequence(char str1[], char str2[], int m, int n) {
    int dp[MAX][MAX];   // 2D array to store the lengths of LCS

    // Initialize the dp array with 0
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Fill the dp array
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                // If characters match, increment the length of LCS by 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // Otherwise, take the maximum of the previous values
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The length of the longest common subsequence is stored in dp[m][n]
    return dp[m][n];
}

int main() {
    char str1[] = "ABCBDAB"; 
    char str2[] = "BDCABB"; 
    int m = strlen(str1);
    int n = strlen(str2); 
    cout << "Length of Longest Common Subsequence: " << longest_common_subsequence(str1, str2, m, n);
    return 0;
}
