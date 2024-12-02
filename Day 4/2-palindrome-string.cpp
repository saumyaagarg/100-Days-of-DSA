// Check if a given string is a palindrome.

#include <iostream>
#include <cctype>
using namespace std;

// Function to check if a given string is a palindrome
void palindrome_check(string str) {
    int n = str.length();
    bool is_palindrome = true;

    // Loop to compare characters from the start and end of the string
    for (int i = 0, j = n - 1; i < j; i++, j--) {
        // Convert both characters to lowercase for case-insensitive comparison
        if (tolower(str[i]) != tolower(str[j])) {
            is_palindrome = false;
            break; // No need to continue if a mismatch is found
        }
    }

    // Check the result and print the appropriate message
    if (is_palindrome) {
        cout << "String is Palindrome." << endl;
    }
    else {
        cout << "String is not Palindrome." << endl;
    }
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    palindrome_check(str);
    return 0;
}
