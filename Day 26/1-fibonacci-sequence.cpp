//  Solve the "fibonacci sequence" problem using recursion, memoization, and tabulation.

#include <iostream>
#include <cstring> 
using namespace std;

#define MAX 1000    // Maximum number for Fibonacci sequence

// Recursive approach
int fibonacci_recursive(int n) {
    if (n <= 1) {
        return n;   // Base cases: Fib(0) = 0, Fib(1) = 1
    }
    return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
}

// Memoization approach
int memo[MAX];      // Array for memoization

int fibonacci_memoization(int n) {
    if (n <= 1) {
        return n;   // Base cases: Fib(0) = 0, Fib(1) = 1
    }
    if (memo[n] != -1) {
        return memo[n]; // Return already computed value
    }
    memo[n] = fibonacci_memoization(n - 1) + fibonacci_memoization(n - 2);
    return memo[n];
}

// Tabulation approach
int fibonacci_tabulation(int n) {
    int dp[MAX] = {0}; // Array for storing Fibonacci numbers
    dp[0] = 0;         // Base case: Fib(0) = 0
    dp[1] = 1;         // Base case: Fib(1) = 1

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];  // Fill the table iteratively
    }
    return dp[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    // Recursive solution
    cout << "Fibonacci using recursion: " << fibonacci_recursive(n) << endl;
    // Memoization solution
    memset(memo, -1, sizeof(memo)); // Initialize memoization array
    cout << "Fibonacci using memoization: " << fibonacci_memoization(n) << endl;
    // Tabulation solution
    cout << "Fibonacci using tabulation: " << fibonacci_tabulation(n) << endl;
    return 0;
}
