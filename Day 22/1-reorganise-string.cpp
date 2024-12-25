// Solve the "reorganize string" problem using a priority queue.

#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
using namespace std;

#define MAX 26      // Maximum number of unique lowercase English letters

struct CharFrequency {
    char character;
    int frequency;
    bool operator<(const CharFrequency &other) const {
        return frequency < other.frequency; // Max Heap property
    }
};

string reorganize_string(const string &s) {
    unordered_map<char, int> freq_map;
    for (char c : s) {
        freq_map[c]++;
    }

    // Priority Queue (Max Heap)
    priority_queue<CharFrequency> max_heap;

    for (auto &entry : freq_map) {
        max_heap.push({entry.first, entry.second});
    }

    string result = "";
    CharFrequency prev = {'#', 0};          // Dummy previous character

    while (!max_heap.empty()) {
        CharFrequency current = max_heap.top();
        max_heap.pop();

        result += current.character;

        if (prev.frequency > 0) {
            max_heap.push(prev);
        }

        current.frequency--;
        prev = current;
    }

    // Check if the reorganization was successful
    return result.size() == s.size() ? result : "";
}

int main() {
    string s = "aab";
    string result = reorganize_string(s);
    if (!result.empty()) {
        cout << "Reorganized string: " << result << endl;
    } else {
        cout << "Reorganization not possible." << endl;
    }
    return 0;
}
