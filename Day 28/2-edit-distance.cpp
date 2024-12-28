//  Solve the "edit distance" problem using dynamic programming.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum size for the strings

// Function to find the minimum number of operations required to convert str1 to str2
int edit_distance(char str1[], char str2[], int m, int n) {
    int dp[MAX][MAX];   // 2D array to store the edit distance

    // Fill the dp array
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                dp[i][j] = j;   // If str1 is empty, all characters of str2 need to be inserted
            } else if (j == 0) {
                dp[i][j] = i;   // If str2 is empty, all characters of str1 need to be deleted
            } else if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];    // No operation needed if characters match
            } else {
                dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                // Min operation among replace, delete, and insert
            }
        }
    }

    // The result is the edit distance to convert str1 to str2
    return dp[m][n];
}

int main() {
    char str1[MAX], str2[MAX];
    cout << "Enter the first string: ";
    cin >> str1;
    cout << "Enter the second string: ";
    cin >> str2;
    int m = strlen(str1); 
    int n = strlen(str2);  
    cout << "Edit Distance: " << edit_distance(str1, str2, m, n) << endl;
    return 0;
}
