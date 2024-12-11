// Solve the "minimum capacity required to ship packages within d days" problem.

#include <iostream>
#include <climits>
using namespace std;

// Function to check if it is possible to ship all packages within `days` using `capacity`
bool is_possible(int weights[], int n, int days, int capacity) {
    int current_load = 0;
    int required_days = 1;

    for (int i = 0; i < n; i++) {
        if (weights[i] > capacity) {
            return false; // A single package exceeds the capacity
        }

        if (current_load + weights[i] > capacity) {
            required_days++;
            current_load = weights[i]; // Start a new day with this package
            if (required_days > days) {
                return false;
            }
        } else {
            current_load += weights[i];
        }
    }
    return true;
}

// Function to find the minimum capacity required to ship packages within `days`
int min_capacity(int weights[], int n, int days) {
    if (days > n) {
        return -1; // Not enough packages to distribute over all days
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        high += weights[i]; // Sum of all weights
        if (weights[i] > low) {
            low = weights[i]; // Maximum single package weight
        }
    }

    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (is_possible(weights, n, days, mid)) {
            result = mid;  // Update result and try for a smaller capacity
            high = mid - 1;
        } else {
            low = mid + 1; // Try for a larger capacity
        }
    }

    return result;
}

int main() {
    int weights[] = {10, 20, 30, 40, 50, 60}; // Weights of the packages
    int n = sizeof(weights) / sizeof(weights[0]);
    int days = 4; // Number of days
    cout << "Weights array: ";
    for (int i = 0; i < n; i++) {
        cout << weights[i] << " ";
    }
    cout << endl;
    int result = min_capacity(weights, n, days);
    if (result != -1) {
        cout << "Minimum capacity required to ship packages within " << days << " days: " << result << endl;
    } else {
        cout << "It is not possible to ship packages within the given days." << endl;
    }
    return 0;
}
