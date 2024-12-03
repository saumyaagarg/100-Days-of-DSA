// Solve the "longest word in a string" problem.

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

// Function to find the longest word in a string
void find_longest_word(string str) {
    stringstream stream(str);       // Create a stringstream to split the string into words
    string word;
    string longest = ""; 
    int max_len = 0; 

    // Loop through all words in the string
    while (stream >> word) {
        // Check if the current word is longer than the previously found longest word
        if (word.length() > max_len) {
            max_len = word.length();
            longest = word;
        }
    }

    cout << "Longest word: " << longest << endl;
    cout << "Length of Longest Word: " << max_len << endl;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);        // Read the entire line of input
    find_longest_word(str);
    return 0;
}
