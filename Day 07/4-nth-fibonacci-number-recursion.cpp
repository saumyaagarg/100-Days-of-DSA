// Write a recursive function to find the nth Fibonacci number.

#include <iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
int recur_fibonacci(int n) {
    // Base cases: Fibonacci(0) = 0, Fibonacci(1) = 1
    if (n == 1 || n == 0) {
        return n;
    }
    else {
        // Recursive step: Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2)
        return recur_fibonacci(n - 1) + recur_fibonacci(n - 2);
    }
}

int main() {
    int n;
    cout << "Enter the position of the Fibonacci number: ";
    cin >> n;
    int result = recur_fibonacci(n);
    cout << "The " << n << "th Fibonacci number is: " << result << endl;
    return 0;
}
