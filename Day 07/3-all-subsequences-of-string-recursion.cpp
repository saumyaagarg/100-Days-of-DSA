// Implement a recursive program to print all subsequences of a string.

#include <iostream>
using namespace std;

// Recursive function to print all subsequences of the string
void print_subsequences(string input, string output) {
    // Base case: If the input is empty, print the output
    if (input.empty()) {
        cout << output << endl;
        return;
    }

    // Include the first character of the input in the output
    print_subsequences(input.substr(1), output + input[0]);

    // Exclude the first character of the input from the output
    print_subsequences(input.substr(1), output);
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    cout << "All subsequences of the string are: " << endl;
    print_subsequences(str, "");
    return 0;
}
