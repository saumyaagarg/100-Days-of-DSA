// Implement a program to reverse a number (e.g., input: 123, output: 321).

#include <iostream> 
using namespace std;

// Function to reverse the digits of a number
void revn(int n) {
    int orig = n; // Store the original number for reference
    int rem = 0;  // Variable to hold the remainder (last digit of n)
    int rev = 0;  // Variable to store the reversed number

    // Process each digit of the number
    while (n != 0) {
        rem = n % 10;         // Extract the last digit of the number
        rev = rev * 10 + rem; // Append the digit to the reversed number
        n = n / 10;           // Remove the last digit from the original number
    }

    cout << "The reversed number is: " << rev;
}

int main() {
    int n; 
    cout << "Enter an integer: ";
    cin >> n; 
    revn(n);
    return 0; 
}
