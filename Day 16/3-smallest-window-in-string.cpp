// Solve the "smallest window in a string containing all characters of another string" problem.

#include <iostream>
#include <string>
#include <climits>
using namespace std;

string smallest_window(string str, string pat) {
    int str_len = str.length();
    int pat_len = pat.length();

    if (str_len < pat_len) {
        return ""; // If the pattern is longer than the string, no solution exists.
    }

    // Frequency arrays for pattern and sliding window
    int pat_count[256] = {0};
    int window_count[256] = {0};

    // Count the frequency of characters in the pattern
    for (int i = 0; i < pat_len; i++) {
        pat_count[pat[i]]++;
    }

    int start = 0, min_length = INT_MAX, start_index = -1;
    int count = 0; // Number of characters matched

    for (int end = 0; end < str_len; end++) {
        // Include current character in the window
        char current_char = str[end];
        window_count[current_char]++;

        // Check if the current character matches the frequency in the pattern
        if (pat_count[current_char] != 0 && window_count[current_char] <= pat_count[current_char]) {
            count++;
        }

        // If all characters are matched, try to shrink the window
        while (count == pat_len) {
            char start_char = str[start];

            // Update the minimum window size
            int window_size = end - start + 1;
            if (window_size < min_length) {
                min_length = window_size;
                start_index = start;
            }

            // Shrink the window from the left
            window_count[start_char]--;
            if (pat_count[start_char] != 0 && window_count[start_char] < pat_count[start_char]) {
                count--;
            }
            start++;
        }
    }

    // Return the smallest window or an empty string if no such window exists
    if (start_index == -1) {
        return "";
    }
    return str.substr(start_index, min_length);
}

int main() {
    string str = "aabcbcdbca";
    string pat = "abcd";

    string result = smallest_window(str, pat);
    if (result.empty()) {
        cout << "No such window exists" << endl;
    } else {
        cout << "Smallest window containing all characters is: " << result << endl;
    }
    return 0;
}
