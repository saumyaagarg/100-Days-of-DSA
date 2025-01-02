// Solve the "word break" problem using dynamic programming.

#include <iostream>
#include <cstring>
#include <unordered_set>
using namespace std;

#define MAX 1000

// Function to check if a word can be broken down into valid words from the dictionary
bool word_break(char str[], unordered_set<string>& dict, int n) {
    bool dp[MAX] = {false};     // dp[i] will be true if str[0...i-1] can be segmented

    dp[0] = true;   // Empty string is always considered as segmented

    // Traverse the string and check each substring
    for (int i = 1; i <= n; i++) {
        // Check all substrings ending at i
        for (int j = 0; j < i; j++) {
            if (dp[j] && dict.find(string(str + j, str + i)) != dict.end()) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[n];   // The result for the entire string
}

int main() {
    char str[MAX];
    int n;
    cout << "Enter the string: ";
    cin >> str;
    unordered_set<string> dict = {"apple", "pie", "applepie"};
    n = strlen(str);
    if (word_break(str, dict, n)) {
        cout << "The string can be segmented into words from the dictionary." << endl;
    } else {
        cout << "The string cannot be segmented into words from the dictionary." << endl;
    }
    return 0;
}
