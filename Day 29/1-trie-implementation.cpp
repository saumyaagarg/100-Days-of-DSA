// Implement a trie and its basic operations (insert, search, delete).

#include <iostream>
#include <cstring>
using namespace std;

// Trie Node structure
struct trie_node {
    trie_node* children[26];
    bool is_end_of_word;

    trie_node() {
        is_end_of_word = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};

class Trie {
    private:
        trie_node* root;

        // Helper function to check if a node has any children
        bool is_empty(trie_node* node) {
            for (int i = 0; i < 26; i++) {
                if (node->children[i]) return false;
            }
            return true;
        }

    public:
        Trie() {
            root = new trie_node();
        }

        // Function to insert a word into the trie
        void insert(const char* word) {
            trie_node* current = root;
            for (int i = 0; word[i] != '\0'; i++) {
                int index = word[i] - 'a';
                if (!current->children[index]) {
                    current->children[index] = new trie_node();
                }
                current = current->children[index];
            }
            current->is_end_of_word = true;
        }

        // Function to search for a prefix in the trie
        bool search_prefix(const char* prefix) {
            trie_node* current = root;
            for (int i = 0; prefix[i] != '\0'; i++) {
                int index = prefix[i] - 'a';
                if (!current->children[index]) {
                    return false;
                }
                current = current->children[index];
            }
            return true;
        }

        // Function to check if a word exists in the trie
        bool search_word(const char* word) {
            trie_node* current = root;
            for (int i = 0; word[i] != '\0'; i++) {
                int index = word[i] - 'a';
                if (!current->children[index]) {
                    return false;
                }
                current = current->children[index];
            }
            return current && current->is_end_of_word;
        }
};

int main() {
    Trie trie;
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");
    cout << "Search prefix 'ap': " << (trie.search_prefix("ap") ? "Found" : "Not Found") << endl;
    cout << "Search word 'apple': " << (trie.search_word("apple") ? "Found" : "Not Found") << endl;
    cout << "Search prefix 'bat': " << (trie.search_prefix("bat") ? "Found" : "Not Found") << endl;
    cout << "Search word 'cat': " << (trie.search_word("cat") ? "Found" : "Not Found") << endl;
    return 0;
}
