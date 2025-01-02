// Solve the "interleaving strings" problem using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to check if two strings can be interleaved to form a third string
bool is_interleave(char str1[], char str2[], char str3[], int len1, int len2, int len3) {
    if (len1 + len2 != len3) {
        return false;  // If lengths don't match, return false
    }

    bool dp[MAX][MAX];  // 2D DP array

    // Initialize the DP table
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            dp[i][j] = false;
        }
    }

    // Base case: both strings are empty
    dp[0][0] = true;

    // Fill the dp table
    for (int i = 0; i <= len1; i++) {
        for (int j = 0; j <= len2; j++) {
            if (i > 0 && str1[i - 1] == str3[i + j - 1]) {
                dp[i][j] = dp[i][j] || dp[i - 1][j];  // If char from str1 matches
            }
            if (j > 0 && str2[j - 1] == str3[i + j - 1]) {
                dp[i][j] = dp[i][j] || dp[i][j - 1];  // If char from str2 matches
            }
        }
    }

    // The answer is in the bottom-right corner of the table
    return dp[len1][len2];
}

int main() {
    char str1[MAX], str2[MAX], str3[MAX];
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    cout << "Enter the third string: ";
    cin >> str3;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    if (is_interleave(str1, str2, str3, len1, len2, len3)) {
        cout << "The third string is an interleaving of the first and second strings." << endl;
    } else {
        cout << "The third string is NOT an interleaving of the first and second strings." << endl;
    }
    return 0;
}
