// Solve the "sum of digits in a number" problem using recursion.

#include <iostream>
using namespace std;

// Recursive function to find the sum of digits of a number
int sum_of_digits(int n) {
    // Base case: If the number is 0, the sum is 0
    if (n == 0) {
        return 0;
    }
    else {
        // Recursive step: Add the last digit to the sum of the remaining digits
        return n % 10 + sum_of_digits(n / 10);
    }
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Handle negative numbers by converting to positive
    if (n < 0) {
        n = -n;
    }

    int result = sum_of_digits(n);
    cout << "The sum of the digits of the number is: " << result;
    return 0;
}
