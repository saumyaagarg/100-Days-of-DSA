// Solve the "find the square root of a number" problem using binary search.

#include <iostream>
using namespace std;

// Function to calculate the square root using binary search
int sq_root(int num) {
    if (num < 0) {
        return -1;  // Square root is not defined for negative numbers
    }
    if (num == 0 || num == 1) {
        return num; // Square root of 0 and 1 is the number itself
    }

    int low = 0, high = num;
    int result = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        // Check if mid * mid is equal to the number
        if (mid * mid == num) {
            return mid;
        }

        // If mid * mid is less than the number, move to the right half
        if (mid * mid < num) {
            result = mid; // Update result to track the floor value
            low = mid + 1;
        } else {
            // If mid * mid is greater, move to the left half
            high = mid - 1;
        }
    }

    return result; // Return the floor of the square root
}

int main() {
    int num = 25;
    cout << "Finding the square root of: " << num << endl;
    int sqrtResult = sq_root(num);
    if (sqrtResult != -1) {
        cout << "The floor of the square root of " << num << " is: " << sqrtResult << endl;
    } else {
        cout << "Square root is not defined for negative numbers." << endl;
    }
    return 0;
}
