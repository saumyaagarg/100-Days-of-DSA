// Write a program to check if two strings are anagrams.

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

//Function to check if two strings are anagrams
bool is_anagram(string str1, string str2) {
    // If lengths are different, they cannot be anagrams
    if (str1.length() != str2.length()) {
        return false;
    }

    // Convert both strings to lowercase to make the comparison case-insensitive
    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    // Sort both strings to compare their characters
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    // After sorting, if the strings are identical, they are anagrams
    return str1 == str2;
}

int main() {
    string str1, str2;
    cout << "Enter first string: ";
    getline(cin, str1);
    cout << "Enter second string: ";
    getline(cin, str2);

    if (is_anagram(str1, str2)) {
        cout << "Strings " << str1 << " and " << str2 << " are Anagrams." << endl;
    }
    else {
        cout << "Strings " << str1 << " and " << str2 << " are not Anagrams." << endl;
    }
    return 0;
}
