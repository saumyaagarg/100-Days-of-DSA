// Solve the "subarray sum equals k" problem using prefix sum.

#include <iostream>
#include <map>
using namespace std;

// Function to find the total number of subarrays with sum equal to k
int subarray_sum_k(int arr[], int n, int k) {
    map<int, int> prefix_sum_count; // Map to store the count of prefix sums
    int current_sum = 0;            // Variable to track the cumulative sum
    int count = 0;                  // Variable to store the total count of subarrays

    prefix_sum_count[0] = 1;        // Initialize with sum 0 to handle subarrays starting from index 0

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];      // Update the cumulative sum

        // Check if there exists a prefix sum such that current_sum - prefix_sum = k
        if (prefix_sum_count.find(current_sum - k) != prefix_sum_count.end()) {
            count += prefix_sum_count[current_sum - k];
        }

        // Add the current cumulative sum to the prefix_sum_count map
        prefix_sum_count[current_sum]++;
    }

    return count;
}

int main() {
    int arr[] = {1, 2, 3, -3, 1, 2, 1, -1, 2}; 
    int k = 3; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = subarray_sum_k(arr, n, k);
    cout << "Total number of subarrays with sum " << k << ": " << result << endl;
    return 0;
}
