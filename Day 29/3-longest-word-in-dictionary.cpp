// Solve the "longest word in a dictionary" problem using a trie.

#include <iostream>
#include <cstring>
using namespace std;

#define MAX 26

class Trie_Node {
    public:
        Trie_Node* children[MAX];
        bool is_end_of_word;

        Trie_Node() {
            is_end_of_word = false;
            for (int i = 0; i < MAX; i++) {
                children[i] = nullptr;
            }
        }
};

class Trie {
    private:
        Trie_Node* root;

    public:
        Trie() {
            root = new Trie_Node();
        }

        // Insert a word into the Trie
        void insert(const char* word) {
            Trie_Node* current = root;
            for (int i = 0; word[i] != '\0'; i++) {
                int index = word[i] - 'a';
                if (!current->children[index]) {
                    current->children[index] = new Trie_Node();
                }
                current = current->children[index];
            }
            current->is_end_of_word = true;
        }

        // Helper function to find the longest word in the Trie
        void find_longest_word(Trie_Node* node, string current_word, string& longest_word) {
            if (!node) return;

            if (node->is_end_of_word) {
                if (current_word.length() > longest_word.length() || (current_word.length() == longest_word.length() && current_word < longest_word)) {
                    longest_word = current_word;
                }
            }

            for (int i = 0; i < MAX; i++) {
                if (node->children[i]) {
                    find_longest_word(node->children[i], current_word + char('a' + i), longest_word);
                }
            }
        }

        // Start the process to find the longest word
        string get_longest_word() {
            string longest_word = "";
            find_longest_word(root, "", longest_word);
            return longest_word;
        }
};

int main() {
    Trie trie;
    char words[][MAX] = {"w", "wo", "wor", "worl", "world"};
    int word_count = 5;
    for (int i = 0; i < word_count; i++) {
        trie.insert(words[i]);
    }
    cout << "Longest Word: " << trie.get_longest_word();
    return 0;
}
