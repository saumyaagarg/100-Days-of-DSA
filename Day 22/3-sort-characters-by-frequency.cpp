// Solve the "sort characters by frequency" problem using a priority queue.

#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

#define MAX 256 // Maximum number of unique characters in ASCII

struct CharFrequency {
    char character;
    int frequency;
    bool operator<(const CharFrequency &other) const {
        return frequency < other.frequency; // Max Heap property
    }
};

string sort_by_frequency(const string &s) {
    unordered_map<char, int> freq_map;

    // Step 1: Count frequency of each character
    for (char c : s) {
        freq_map[c]++;
    }

    // Step 2: Use a max heap to sort characters by frequency
    priority_queue<CharFrequency> max_heap;

    for (auto &entry : freq_map) {
        max_heap.push({entry.first, entry.second});
    }

    // Step 3: Build the sorted string
    string result = "";
    while (!max_heap.empty()) {
        CharFrequency top = max_heap.top();
        max_heap.pop();

        for (int i = 0; i < top.frequency; i++) {
            result += top.character;
        }
    }

    return result;
}

int main() {
    string s = "seventeen";
    string result = sort_by_frequency(s);
    cout << "String sorted by frequency: " << result << endl;
    return 0;
}
