// Create a program to print the first n Fibonacci numbers.

#include <iostream> 
using namespace std;

// Function to print the first n Fibonacci numbers
void fib(int n) {
    int a = 0; // First Fibonacci number
    int b = 1; // Second Fibonacci number
    int c;     // Variable to store the next Fibonacci number

    // Print the first two Fibonacci numbers
    cout << a << " " << b << " ";

    // Generate and print the next Fibonacci numbers using a loop
    for (int i = 2; i < n; i++) {
        c = a + b;        // Calculate the next number in the sequence
        cout << c << " "; // Print the current Fibonacci number
        a = b;            // Update 'a' to the previous 'b'
        b = c;            // Update 'b' to the current number
    }
}

int main() {
    int n; 
    cout << "Enter an integer: ";
    cin >> n; 
    fib(n);
    return 0;
}
