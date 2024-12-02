// Implement a program to remove duplicate characters from a string.

#include <iostream>
using namespace std;

bool is_present(char ch, string str) {
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == ch) {
            return true;
        }
    }
    return false;
}

void remove_duplicates(string str) {
    int n = str.size();
    int newLength = 0;

    // Iterate through the string
    for (int i = 0; i < n; i++) {
        // If the character is not already in the result, move it to the 'new' part of the string
        if (!is_present(str[i], str.substr(0, newLength))) {
            str[newLength] = str[i];
            newLength++;
        }
    }

    // Cut off any extra characters after the new length
    str = str.substr(0, newLength);

    cout << "String after removing duplicate characters is: " << str;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    remove_duplicates(str);
}
