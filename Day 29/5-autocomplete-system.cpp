// Solve the "implement autocomplete system" problem using a trie.

#include <iostream>
#include <string>
using namespace std;

#define ALPHABET_SIZE 26

struct TrieNode {
    TrieNode* children[ALPHABET_SIZE];
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    private:
        TrieNode* root;

        // Helper function to recursively find suggestions
        void find_suggestions(TrieNode* node, string prefix) {
            if (node->is_end_of_word) {
                cout << prefix << endl;
            }

            for (int i = 0; i < ALPHABET_SIZE; i++) {
                if (node->children[i]) {
                    find_suggestions(node->children[i], prefix + char(i + 'a'));
                }
            }
        }

    public:
        Trie() {
            root = new TrieNode();
        }

        // Insert a word into the trie
        void insert(string word) {
            TrieNode* current = root;
            for (char c : word) {
                int index = c - 'a';
                if (!current->children[index]) {
                    current->children[index] = new TrieNode();
                }
                current = current->children[index];
            }
            current->is_end_of_word = true;
        }

        // Search for a word in the trie
        bool search(string word) {
            TrieNode* current = root;
            for (char c : word) {
                int index = c - 'a';
                if (!current->children[index]) {
                    return false;
                }
                current = current->children[index];
            }
            return current->is_end_of_word;
        }

        // Display autocomplete suggestions for a given prefix
        void autocomplete(string prefix) {
            TrieNode* current = root;
            for (char c : prefix) {
                int index = c - 'a';
                if (!current->children[index]) {
                    cout << "No suggestions found." << endl;
                    return;
                }
                current = current->children[index];
            }
            find_suggestions(current, prefix);
        }
};

int main() {
    Trie trie;
    trie.insert("cat");
    trie.insert("cap");
    trie.insert("car");
    trie.insert("dog");
    trie.insert("bat");
    string prefix;
    cout << "Enter a prefix to autocomplete: ";
    cin >> prefix;
    cout << "Autocomplete suggestions: " << endl;
    trie.autocomplete(prefix);
    return 0;
}
