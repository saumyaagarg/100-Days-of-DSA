// Solve the "word ladder" problem using BFS.

#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 50  // Maximum number of words in the dictionary

// Graph class for Word Ladder problem
class WordLadder {
private:
    char dictionary[MAX][50];   // Dictionary of words
    int word_count;             // Total number of words in the dictionary

public:
    // Constructor to initialize the dictionary
    WordLadder() {
        word_count = 0;
    }

    // Add word to the dictionary
    void add_word(const char* word) {
        strcpy(dictionary[word_count++], word);
    }

    // Function to check if two words differ by exactly one character
    bool one_letter_diff(const char* word1, const char* word2) {
        int diff_count = 0;
        int len1 = strlen(word1);
        int len2 = strlen(word2);
        if (len1 != len2) return false; // Words must have the same length

        for (int i = 0; i < len1; i++) {
            if (word1[i] != word2[i]) {
                diff_count++;
            }
        }
        return (diff_count == 1); // They should differ by exactly one letter
    }

    // BFS to find the shortest transformation sequence
    int find_word_ladder(const char* start, const char* end) {
        if (strcmp(start, end) == 0) return 0; // If the start and end words are the same

        bool visited[MAX] = {false}; // Keep track of visited words
        queue<pair<const char*, int>> q; // Queue for BFS, storing word and level (steps)

        q.push({start, 1});
        visited[0] = true;

        while (!q.empty()) {
            const char* current_word = q.front().first;
            int level = q.front().second;
            q.pop();

            // Check all words in the dictionary for possible transformation
            for (int i = 0; i < word_count; i++) {
                if (!visited[i] && one_letter_diff(current_word, dictionary[i])) {
                    // If end word is found, return the current level + 1
                    if (strcmp(dictionary[i], end) == 0) {
                        return level + 1;
                    }
                    visited[i] = true;
                    q.push({dictionary[i], level + 1});
                }
            }
        }
        return 0; // If no transformation is found
    }
};

int main() {
    WordLadder word_ladder;
    word_ladder.add_word("hit");
    word_ladder.add_word("hot");
    word_ladder.add_word("dot");
    word_ladder.add_word("dog");
    word_ladder.add_word("cog");
    const char* start_word = "hit";
    const char* end_word = "cog";
    int result = word_ladder.find_word_ladder(start_word, end_word);
    if (result == 0) {
        cout << "No transformation sequence found." << endl;
    } else {
        cout << "The shortest transformation sequence length is: " << result << endl;
    }
    return 0;
}
