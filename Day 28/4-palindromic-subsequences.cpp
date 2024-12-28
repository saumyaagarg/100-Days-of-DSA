// Solve the "palindromic subsequences" problem.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to calculate the length of the longest palindromic subsequence
int longest_palindromic_subsequence(char str[], int n) {
    int dp[MAX][MAX];   // 2D array to store lengths of palindromic subsequences

    // Base case: A single character is always a palindrome of length 1
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
    }

    // Fill the dp array for substrings of length 2 and more
    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;     // Ending index of substring

            if (str[i] == str[j]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;    // Characters match
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);     // Max of excluding either character
            }
        }
    }

    return dp[0][n - 1];    // Length of longest palindromic subsequence for the full string
}

int main() {
    char str[MAX];
    cout << "Enter the string: ";
    cin >> str;
    int n = strlen(str);
    cout << "Length of Longest Palindromic Subsequence: " << longest_palindromic_subsequence(str, n) << endl;
    return 0;
}
