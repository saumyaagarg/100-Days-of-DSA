// Solve the "wildcard matching" problem using dynamic programming. 

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to perform wildcard matching using dynamic programming
bool wildcard_matching(char s[], char p[], int m, int n) {
    bool dp[MAX][MAX];  // 2D array to store whether substrings match

    // Initialize dp array
    dp[0][0] = true;    // Empty pattern and empty string match

    // Fill first row (pattern with only '*' characters can match empty string)
    for (int j = 1; j <= n; j++) {
        dp[0][j] = (p[j - 1] == '*') && dp[0][j - 1];
    }

    // Fill the dp array for the rest of the strings and pattern
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (p[j - 1] == s[i - 1] || p[j - 1] == '?') {
                dp[i][j] = dp[i - 1][j - 1];    // Characters match or '?' matches any character
            }
            else if (p[j - 1] == '*') {
                dp[i][j] = dp[i - 1][j] || dp[i][j - 1];    // '*' matches zero or more characters
            }
            else {
                dp[i][j] = false;   // If characters don't match and no wildcard
            }
        }
    }

    return dp[m][n];    // Final result for matching full strings
}

int main() {
    char s[MAX], p[MAX];
    cout << "Enter the string: ";
    cin >> s;
    cout << "Enter the pattern: ";
    cin >> p;
    int m = strlen(s);
    int n = strlen(p);
    if (wildcard_matching(s, p, m, n)) {
        cout << "The pattern matches the string." << endl;
    } else {
        cout << "The pattern does not match the string." << endl;
    }
    return 0;
}
