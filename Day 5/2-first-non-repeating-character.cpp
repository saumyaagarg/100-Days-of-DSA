// Solve the problem of finding the first non-repeating character in a string.

#include <iostream>
using namespace std;

// Function to find first non-repeating character in a string
void non_repeating(string str) {
    int n = str.length();
    char ch = ' ';

    // Loop through each character in the string
    for (int i = 0; i < n; i++) {
        bool flag = false;      // Reset flag for each character

        // Check if the current character repeats in the rest of the string
        for (int j = 0; j < n; j++) {
            if (i != j && str[i] == str[j]) {
                flag = true;    // Mark as repeating
                break;
            }
        }

        // If not repeating, it's the first non-repeating character
        if (!flag) { 
            ch = str[i];
            break;
        }
    }

    if (ch != ' ') {
        cout << "The first non-repeating character in the string is: " << ch << endl;
    }
    else {
        cout << "There are no non-repeating characters in the string." << endl;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    non_repeating(str);
    return 0;
}