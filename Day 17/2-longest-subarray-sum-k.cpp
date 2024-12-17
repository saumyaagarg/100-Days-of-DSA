// Solve the "longest subarray with sum k" problem using prefix sum.

#include <iostream>
#include <map>
using namespace std;

// Function to find the length of the longest subarray with sum k
int longest_subarray_sum_k(int arr[], int n, int k) {
    map<int, int> prefix_sum_map; // To store the first occurrence of prefix sums
    int current_sum = 0;          // Variable to keep track of cumulative sum
    int max_length = 0;           // To store the length of the longest subarray

    for (int i = 0; i < n; i++) {
        current_sum += arr[i];    // Update the cumulative sum

        // If current_sum equals k, the subarray [0..i] has sum k
        if (current_sum == k) {
            max_length = i + 1;
        }

        // Check if there is a prefix sum such that current_sum - k exists
        if (prefix_sum_map.find(current_sum - k) != prefix_sum_map.end()) {
            // Calculate the length of the subarray
            int subarray_length = i - prefix_sum_map[current_sum - k];
            max_length = max(max_length, subarray_length);
        }

        // Store the first occurrence of current_sum
        if (prefix_sum_map.find(current_sum) == prefix_sum_map.end()) {
            prefix_sum_map[current_sum] = i;
        }
    }

    return max_length;
}

int main() {
    int arr[] = {1, 2, 3, 1, 1, 1, 4, 2, -1}; 
    int k = 5;  
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = longest_subarray_sum_k(arr, n, k);
    cout << "Length of the longest subarray with sum " << k << ": " << result << endl;
    return 0;
}
