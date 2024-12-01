// Write a program to check if a given number is prime.

#include <iostream> 
using namespace std;

// Function to check if a number is prime
void checkprime(int n) {
    int flag = 0; // Flag to indicate if the number is composite

    // Special cases: 0 and 1 are neither prime nor composite
    if (n == 0 || n == 1) {
        cout << "Entered number, " << n << ", is neither prime, nor composite.";
        return; 
    }

    // Check divisibility from 2 to n/2
    for (int i = 2; i <= n / 2; i++) {
        if (n % i == 0) {   // If divisible, it's not a prime number
            flag = 1;       // Set flag to indicate a composite number
            break;          // Exit the loop as we found a divisor
        }
    }

    // Determine and display the result based on the flag
    if (flag == 0) {
        cout << "Entered number, " << n << ", is prime." << endl;
    }
    else {
        cout << "Entered number, " << n << ", is composite (not prime)." << endl;
    }
}

int main() {
    int n; 
    cout << "Enter an integer: ";
    cin >> n; 
    checkprime(n);
    return 0; 
}