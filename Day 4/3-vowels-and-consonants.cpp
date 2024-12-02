// Write a function to count vowels and consonants in a string.

#include <iostream>
#include <cctype>
using namespace std;

void vowels_consonants(string str) {
    int vowel_count = 0;
    int consonant_count = 0;

    // Convert the string to lowercase manually character by character
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    }

    // Loop through the string and count vowels and consonants
    for (int i = 0; i < str.length(); i++) {
        if (isalpha(str[i])) {      // Only check alphabetic characters
            if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
                vowel_count++;
            }
            else {
                consonant_count++;
            }
        }
    }

    cout << "Number of vowels: " << vowel_count << endl;
    cout << "Number of consonants: " << consonant_count << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;
    vowels_consonants(str);
    return 0;
}