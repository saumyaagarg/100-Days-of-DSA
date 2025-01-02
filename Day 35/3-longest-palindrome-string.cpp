// Solve the "longest palindromic substring" problem.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000

// Function to find the longest palindromic substring
int longest_palindromic_substring(char str[], int n) {
    bool dp[MAX][MAX];              // 2D array to store the palindrome status for substrings
    int max_length = 1, start = 0;  // To store the length and start index of the longest palindrome found

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
    }

    // Check for substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (str[i] == str[i + 1]) {
            dp[i][i + 1] = true;
            max_length = 2;
            start = i;
        }
    }

    // Check for substrings of length 3 and greater
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;     // Ending index of the current substring

            // If the first and last characters match, check if the middle substring is a palindrome
            if (str[i] == str[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;

                // Update max length and start index if a longer palindrome is found
                if (length > max_length) {
                    max_length = length;
                    start = i;
                }
            }
        }
    }

    // Return the length of the longest palindromic substring
    return max_length;
}

int main() {
    char str[MAX];
    cout << "Enter the string: ";
    cin >> str;
    int n = strlen(str);
    int max_length = longest_palindromic_substring(str, n);
    cout << "Length of the Longest Palindromic Substring: " << max_length << endl;
    return 0;
}
