// Solve the "longest substring without repeating characters" problem.

#include <iostream>
#include <string>
using namespace std;

int long_substr_wo_repeating(string str) {
    int n = str.length();
    int max_length = 0;                     // Maximum length of substring
    int start = 0;                          // Starting index of the current substring
    int last_seen[256];                     // Array to store last seen positions of characters
    fill(last_seen, last_seen + 256, -1);   // Initialize all positions to -1

    for (int end = 0; end < n; end++) {
        char current_char = str[end];

        // If the character has been seen and is within the current window
        if (last_seen[current_char] >= start) {
            start = last_seen[current_char] + 1;
        }

        // Update the last seen index of the current character
        last_seen[current_char] = end;

        // Update the maximum length of the substring
        max_length = max(max_length, end - start + 1);
    }

    return max_length;
}

int main() {
    string str = "abcadabacd";
    cout << "String: " << str << endl;
    cout << "The length of the longest substring without repeating characters is: " << long_substr_wo_repeating(str) << endl;
    return 0;
}
