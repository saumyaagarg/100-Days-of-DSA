// Solve the "sort characters by frequency" problem.

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Helper function to build the frequency table
void build_freq_table(const string &s, int freq[], char chars[]) {
    for (int i = 0; i < s.length(); ++i) {
        int index = s[i];
        if (freq[index] == 0) {
            chars[index] = s[i];
        }
        freq[index]++;
    }
}

// Custom comparator to sort by frequency and character order
void sort_by_freq(char chars[], int freq[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (freq[chars[j]] > freq[chars[i]] ||
                (freq[chars[j]] == freq[chars[i]] && chars[j] < chars[i])) {
                swap(chars[i], chars[j]);
            }
        }
    }
}

// Function to generate the sorted string by frequency
string freq_sort(const string &s) {
    const int CHAR_COUNT = 256; // Support for all ASCII characters
    int freq[CHAR_COUNT] = {0};
    char chars[CHAR_COUNT] = {0};

    // Build frequency table
    build_freq_table(s, freq, chars);

    // Sort characters by frequency
    sort_by_freq(chars, freq, CHAR_COUNT);

    // Build result string
    string result;
    for (int i = 0; i < CHAR_COUNT; ++i) {
        if (freq[chars[i]] > 0) {
            result.append(freq[chars[i]], chars[i]);
        }
    }

    return result;
}

int main() {
    string s = "seventeen";
    cout << "Original string: " << s << endl;
    string sortedString = freq_sort(s);
    cout << "String sorted by frequency: " << sortedString << endl;
    return 0;
}
