// Solve the "longest increasing subsequence" problem.

#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

#define MAX 1000    // Maximum size of the array

// Function to find the length of the longest increasing subsequence
int longest_increasing_subsequence(int arr[], int n) {
    int dp[MAX];    // Array to store the length of LIS ending at each index
    memset(dp, 0, sizeof(dp));  // Initialize dp array with 0

    // Initialize the dp array where each element is at least an LIS of length 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Fill the dp array using the LIS property
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    // Find the maximum value in dp, which represents the length of the longest increasing subsequence
    int lis_length = 0;
    for (int i = 0; i < n; i++) {
        lis_length = max(lis_length, dp[i]);
    }
    
    return lis_length;
}

int main() {
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Length of Longest Increasing Subsequence: " << longest_increasing_subsequence(arr, n) << endl;
    return 0;
}
