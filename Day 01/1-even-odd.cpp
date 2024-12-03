// Write a program to check if a number is even or odd.

#include <iostream>
using namespace std;
int main() {
    int n;
    cout << "Enter an integer: ";
    cin >> n;

    // Check if the number is divisible by 2
    if (n % 2 == 0) {
        // If the remainder is 0, the number is even
        cout << "The number entered, " << n << ", is even.";
    }
    else {
        // Otherwise, the number is odd
        cout << "The number entered, " << n << ", is odd.";
    }
    return 0;
}