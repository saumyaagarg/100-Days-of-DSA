// Solve the "generate all permutations of a string/array" problem.

#include <iostream>
using namespace std;

// Function to swap two characters
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

// Recursive function to generate permutations
void permutations(char arr[], int n, int index) {
    if (index == n) {
        // Base case: print the permutation
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    // Generate permutations by swapping and recursing
    for (int i = index; i < n; i++) {
        swap(arr[index], arr[i]);               // Swap current element with the index
        permutations(arr, n, index + 1);        // Recur for the next index
        swap(arr[index], arr[i]);               // Backtrack to restore the array
    }
}

int main() {
    char arr[] = {'A', 'B', 'C'}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "All permutations are:" << endl;
    permutations(arr, n, 0);
    return 0;
}
