// Write a program to find the factorial of a number using a loop.

#include <iostream> 
using namespace std;

// Function to calculate factorial using a loop
int fact(int n) {
    int f = 1; // Initialize factorial result to 1
    for (int i = 1; i <= n; i++) {
        f = f * i; // Multiply f with the current value of i
    }
    return f; 
}

int main() {
    int f; 
    cout << "Enter an integer: ";
    cin >> f; 
    int factorial = fact(f);
    cout << "The factorial of given number, " << f << ", is " << factorial << ".";
    return 0;
}
