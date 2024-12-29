// Solve the "prefix search in a list of words" problem using a trie.

#include <iostream>
#include <cstring>
using namespace std;

#define ALPHABET_SIZE 26

// Class representing a Trie node
class trie_node {
public:
    trie_node* children[ALPHABET_SIZE]; // Array for child nodes
    bool is_end_of_word;                // Marks the end of a word

    trie_node() {
        is_end_of_word = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            children[i] = nullptr;
        }
    }
};

// Class representing the Trie structure
class trie {
private:
    trie_node* root;

public:
    trie() {
        root = new trie_node();
    }

    // Function to insert a word into the trie
    void insert_word(const char word[]) {
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

    // Function to search for a word prefix in the trie
    bool search_prefix(const char prefix[]) {
        trie_node* current = root;
        for (int i = 0; prefix[i] != '\0'; i++) {
            int index = prefix[i] - 'a';
            if (!current->children[index]) {
                return false;
            }
            current = current->children[index];
        }
        return true;    // Prefix exists
    }
};

int main() {
    trie my_trie;
    int num_words;
    char word[100], prefix[100];

    cout << "Enter the number of words: ";
    cin >> num_words;
    cout << "Enter the words:\n";
    for (int i = 0; i < num_words; i++) {
        cin >> word;
        my_trie.insert_word(word);
    }

    cout << "Enter the prefix to search: ";
    cin >> prefix;

    if (my_trie.search_prefix(prefix)) {
        cout << "Prefix found in the list of words." << endl;
    } else {
        cout << "Prefix not found in the list of words." << endl;
    }

    return 0;
}
