// Solve the "next greater element" problem using a stack.

#include <iostream>
#include <stack>
using namespace std;

// Function to find the next greater element for each element in the array
void next_greater_element(int arr[], int n) {
    stack<int> s; // Stack to keep track of elements

    // Array to store the
    int *result = new int[n];

    for (int i = n - 1; i >= 0; i--) {
        // Remove elements from the stack that are smaller than or equal to arr[i]
        while (!s.empty() && s.top() <= arr[i]) {
            s.pop();
        }

        // If stack is not empty, the top element is the next greater element
        if (!s.empty())
            result[i] = s.top();
        else
            // If the stack is empty, there is no greater element
            result[i] = -1;

        // Push the current element onto the stack
        s.push(arr[i]);
    }

    // Print the results in the specified format
    for (int i = 0; i < n; i++) {
        cout << "Next greater element of " << arr[i] << " is " << (result[i] == -1 ? "none" : to_string(result[i])) << endl;
    }
    delete[] result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    next_greater_element(arr, n);
    delete[] arr;
    return 0;
}
