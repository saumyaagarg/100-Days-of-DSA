// Solve the "find all anagrams of a string in another string" problem.

#include <iostream>
#include <string>
using namespace std;

// Function to find all anagrams of a string in another string
void anagrams(string str, string pat) {
    int str_len = str.length();
    int pat_len = pat.length();

    if (str_len < pat_len) {
        cout << "No anagrams found!" << endl;
        return;
    }

    // Frequency arrays for pattern and window
    int pat_count[256] = {0};
    int window_count[256] = {0};

    // Count frequency of characters in the pattern
    for (int i = 0; i < pat_len; i++) {
        pat_count[pat[i]]++;
    }

    // Initialize variables for the sliding window
    int start = 0;
    for (int end = 0; end < str_len; end++) {
        // Include the current character in the window
        window_count[str[end]]++;

        // If the window has reached the size of the pattern
        if (end - start + 1 == pat_len) {
            // Compare window with the pattern's frequency array
            bool is_anagram = true;
            for (int i = 0; i < 256; i++) {
                if (window_count[i] != pat_count[i]) {
                    is_anagram = false;
                    break;
                }
            }

            // If it is an anagram, print the starting index
            if (is_anagram) {
                cout << "Anagram found at index: " << start << endl;
            }

            // Slide the window by removing the character at the start
            window_count[str[start]]--;
            start++;
        }
    }
}

int main() {
    string str = "aaabaabaa";
    string pat = "abc";
    cout << "Anagrams of \"" << pat << "\" in \"" << str << "\":" << endl;
    anagrams(str, pat);
    return 0;
}
