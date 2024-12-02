// Write a program to reverse a string.

#include <iostream>
#include <string>
using namespace std;

void reverse_str(string str) {
    int n = str.length();
    string rev_str = str;     // Initialize rev_str with the same size as str

    // Reverse the string
    for (int j = n - 1, i = 0; j >= 0; j--, i++) {
        rev_str[i] = str[j];
    }

    cout << "The reversed string is: " << rev_str << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);       // Use getline to read the full line including spaces
    reverse_str(str);
    return 0;
}