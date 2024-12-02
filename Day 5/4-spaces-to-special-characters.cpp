// Implement a program to replace spaces in a string with a special character (e.g., %20).

#include <iostream>
using namespace std;

// Function to replace spaces in the string with a specified character
void replace_space(string str, char ch) {
    int n = str.length();
    for (int i = 0; i < n; i++) {
        if (str[i] == ' ') {    // Check if the current character is a space
            str[i] = ch;        // Replace the space with the specified character
        }
    }
    cout << "The replaces string is: " << str;
}

int main() {
    string str;
    char ch;
    cout << "Enter a sentence: ";
    getline(cin, str);
    cout << "Enter special character to replace spaces with: ";
    cin >> ch;
    replace_space(str, ch);
    return 0;
}