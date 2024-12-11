// Solve the "median of two sorted arrays" problem using binary search.

#include <iostream>
#include <climits>
using namespace std;

// Function to find the median of two sorted arrays
double median_sorted(int arr1[], int m, int arr2[], int n) {
    // Ensure binary search is performed on the smaller array
    if (m > n) {
        return median_sorted(arr2, n, arr1, m);
    }

    int low = 0, high = m;
    int medianPos = (m + n + 1) / 2;

    while (low <= high) {
        int partition1 = low + (high - low) / 2;
        int partition2 = medianPos - partition1;

        int maxLeft1 = (partition1 == 0) ? INT_MIN : arr1[partition1 - 1];
        int minRight1 = (partition1 == m) ? INT_MAX : arr1[partition1];

        int maxLeft2 = (partition2 == 0) ? INT_MIN : arr2[partition2 - 1];
        int minRight2 = (partition2 == n) ? INT_MAX : arr2[partition2];

        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // Correct partition found
            if ((m + n) % 2 == 0) {
                return (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2.0;
            } else {
                return max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            // Move towards the left in arr1
            high = partition1 - 1;
        } else {
            // Move towards the right in arr1
            low = partition1 + 1;
        }
    }

    // If no solution is found (should not happen for valid inputs)
    return -1;
}

int main() {
    int arr1[] = {1, 3, 5};
    int m = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {2, 4};
    int n = sizeof(arr2) / sizeof(arr2[0]);
    cout << "Array 1: ";
    for (int i = 0; i < m; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    cout << "Array 2: ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    double median = median_sorted(arr1, m, arr2, n);
    cout << "The median of the two sorted arrays is: " << median << endl;
    return 0;
}
