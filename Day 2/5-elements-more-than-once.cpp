// Solve the "find all elements that appear more than once in an array" problem.

#include <iostream>
using namespace std;

// Function to find and print elements with duplicates in the array
void findDuplicateElements(int arr[], int n) {
    bool *visited = new bool[n](); // Create a visited array to mark processed elements
    cout << "Elements with duplicates are: ";

    bool found = false;
    for (int i = 0; i < n; i++) {
        // Skip the element if it's already marked as visited
        if (visited[i])
            continue;

        bool isDuplicate = false;
        // Check for duplicates of arr[i] from the next position
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                visited[j] = true;   // Mark the duplicate element
            }
        }

        // If a duplicate was found, print the element
        if (isDuplicate) {
            cout << arr[i] << " ";
            visited[i] = true;      // Mark the current element as visited as well
            found = true;
        }
    }

    if (!found) {
        cout << "None";
    }
    cout << endl;
    delete[] visited;
}

int main() {
    cout << "Enter number of elements: ";
    int count;
    cin >> count;
    int *arr = new int[count];
    cout << "Enter elements of the array: ";
    for (int i = 0; i < count; i++) {
        cin >> arr[i];
    }
    findDuplicateElements(arr, count);
    delete[] arr;
    return 0;
}
