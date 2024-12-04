// Write a recursive function to calculate the factorial of a number.

#include <iostream>
using namespace std;

// Recursive function to calculate factorial
int recur_factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0) {
        return 1;
    }
    else {
        // Recursive step: n * factorial of (n-1)
        return n * recur_factorial(n - 1);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;
    int factorial = recur_factorial(n);
    cout << "The factorial of given number, " << n << ", is " << factorial << ".";
    return 0;
}
