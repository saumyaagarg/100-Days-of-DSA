// Solve the "minimum number of swaps required to sort an array" problem.

#include <iostream>
#include <algorithm>
using namespace std;

// Function to find the minimum number of swaps required to sort the array
int min_swaps(int arr[], int n) {
    // Create an array of pairs where each pair consists of (array element, original index)
    pair<int, int> arr_pos[n];
    for (int i = 0; i < n; ++i) {
        arr_pos[i].first = arr[i];
        arr_pos[i].second = i;
    }

    // Sort the array of pairs based on the element values
    sort(arr_pos, arr_pos + n);

    // To track visited elements
    bool visited[n] = {false};
    int swaps = 0;

    // Iterate through the elements
    for (int i = 0; i < n; ++i) {
        // If the element is already visited or is already in the correct position
        if (visited[i] || arr_pos[i].second == i) {
            continue;
        }

        // Calculate the size of the cycle
        int cycle_size = 0;
        int j = i;
        while (!visited[j]) {
            visited[j] = true;
            j = arr_pos[j].second; // Move to the index where the element should be
            cycle_size++;
        }

        // If there is a cycle of 'n' elements, it will take (n-1) swaps to arrange them
        if (cycle_size > 1) {
            swaps += (cycle_size - 1);
        }
    }

    return swaps;
}

int main() {
    int arr[] = {5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int result = min_swaps(arr, n);
    cout << "Minimum swaps required to sort the array: " << result << endl;
    return 0;
}
