// Solve the "regular expression matching" problem using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to check if the string matches the given regular expression
bool isMatch(const char str[], const char pattern[], int str_len, int pat_len) {
    bool dp[MAX][MAX];  // DP table to store results of subproblems

    // Initialize DP table
    dp[0][0] = true;

    // Fill the first row (matching empty string with pattern)
    for (int j = 1; j <= pat_len; j++) {
        if (pattern[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2];  // '*' can match zero characters
        }
    }

    // Fill the DP table
    for (int i = 1; i <= str_len; i++) {
        for (int j = 1; j <= pat_len; j++) {
            if (pattern[j - 1] == str[i - 1] || pattern[j - 1] == '.') {
                dp[i][j] = dp[i - 1][j - 1];    // Characters match or '.' matches any character
            } else if (pattern[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2];        // '*' can match zero characters
                if (pattern[j - 2] == str[i - 1] || pattern[j - 2] == '.') {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];  // '*' can match more than one character
                }
            } else {
                dp[i][j] = false;  // No match if current characters do not match
            }
        }
    }

    return dp[str_len][pat_len];  // Return the result of matching full string with full pattern
}

int main() {
    char str[MAX], pattern[MAX];
    cout << "Enter the string: ";
    cin >> str;
    cout << "Enter the pattern: ";
    cin >> pattern;
    int str_len = strlen(str);
    int pat_len = strlen(pattern);
    if (isMatch(str, pattern, str_len, pat_len)) {
        cout << "The string matches the pattern." << endl;
    } else {
        cout << "The string does not match the pattern." << endl;
    }
    return 0;
}
