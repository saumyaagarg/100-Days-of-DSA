// Solve the "maximum number of vowels in a substring of length k" problem.

#include <iostream>
#include <string>
using namespace std;

// Function to check if a character is a vowel
bool is_vowel(char c) {
    char lower_c = tolower(c);  // Convert to lowercase to handle both cases
    return lower_c == 'a' || lower_c == 'e' || lower_c == 'i' || lower_c == 'o' || lower_c == 'u';
}

// Function to find the maximum number of vowels in a substring of length k
int max_vowels(string str, int k) {
    int n = str.length();
    int maxVowels = 0;
    int currentVowels = 0;

    // First, count the vowels in the first window of size k
    for (int i = 0; i < k && i < n; i++) {
        if (is_vowel(str[i])) {
            currentVowels++;
        }
    }

    // Set the initial maxVowels to the count from the first window
    maxVowels = currentVowels;

    // Now slide the window through the rest of the string
    for (int i = k; i < n; i++) {
        // Remove the vowel count of the leftmost character of the window
        if (is_vowel(str[i - k])) {
            currentVowels--;
        }
        // Add the vowel count of the new character entering the window
        if (is_vowel(str[i])) {
            currentVowels++;
        }

        // Update maxVowels if currentVowels is greater
        maxVowels = max(maxVowels, currentVowels);
    }

    return maxVowels;
}

int main() {
    string str = "abcdeiouwaec";
    int k;
    cout << "String: " << str << endl;
    cout << "Enter value of k: ";
    cin >> k;
    int result = max_vowels(str, k);
    cout << "Maximum number of vowels in a substring of length " << k << ": " << result << endl;
    return 0;
}
