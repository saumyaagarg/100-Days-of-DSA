// Solve the "generate all subsets of a set" problem using recursion.

#include <iostream>
#include <cmath>
using namespace std;

// Function to generate subsets recursively
void subsets(int set[], int n, string current, int index) {
    if (index == n) {
        // Base case: print the current subset
        cout << "{ " << current << "}" << endl;
        return;
    }

    // Include the current element
    subsets(set, n, current + to_string(set[index]) + " ", index + 1);

    // Exclude the current element
    subsets(set, n, current, index + 1);
}

int main() {
    int set[] = {1, 2, 3, 4}; 
    int n = sizeof(set) / sizeof(set[0]);
    cout << "The subsets are:" << endl;
    subsets(set, n, "", 0);
    return 0;
}
