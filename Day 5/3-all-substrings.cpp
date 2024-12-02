// Write a function to find all substrings of a string.

#include <iostream>
#include <string>
using namespace std;

// Function to find all substrings of a string
void all_substrings(string str) {
    int n = str.length();
    cout << "All substrings of the given string are:" << endl;

    // Loop to select the starting point
    for (int i = 0; i < n; i++){
        // Loop to select the ending point
        for (int j = i; j < n; j++) {
            // Extract and print the substring from i to j
            cout << str.substr(i, j - i + 1) << endl;
        }
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    all_substrings(str);
    return 0;
}
