// Solve the "replace words in a sentence" problem using a trie.

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define ALPHABET_SIZE 26

// Trie Node structure
class TrieNode {
    public:
        TrieNode* children[ALPHABET_SIZE];
        bool is_end_of_word;

        TrieNode() {
            is_end_of_word = false;
            for (int i = 0; i < ALPHABET_SIZE; i++) {
                children[i] = nullptr;
            }
        }
};

// Trie class for managing the prefix dictionary
class Trie {
    private:
        TrieNode* root;

    public:
        Trie() {
            root = new TrieNode();
        }

        // Function to insert a word into the trie
        void insert_word(const string& word) {
            TrieNode* node = root;
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) {
                    node->children[index] = new TrieNode();
                }
                node = node->children[index];
            }
            node->is_end_of_word = true;
        }

        // Function to search for the shortest prefix in the trie
        string get_shortest_prefix(const string& word) {
            TrieNode* node = root;
            string prefix = "";
            for (char c : word) {
                int index = c - 'a';
                if (!node->children[index]) break;
                prefix += c;
                node = node->children[index];
                if (node->is_end_of_word) return prefix;
            }
            return word; // Return the original word if no prefix is found
        }
};

// Function to replace words in a sentence using the trie
string replace_words(Trie& trie, const string& sentence) {
    string result = "", word = "";
    for (char c : sentence) {
        if (c == ' ') {
            result += trie.get_shortest_prefix(word) + " ";
            word = "";
        } else {
            word += c;
        }
    }
    result += trie.get_shortest_prefix(word); // Process the last word
    return result;
}

int main() {
    Trie trie;
    int dictionary_size;
    cout << "Enter the number of dictionary words: ";
    cin >> dictionary_size;

    cout << "Enter the dictionary words:" << endl;
    for (int i = 0; i < dictionary_size; i++) {
        string word;
        cin >> word;
        trie.insert_word(word);
    }

    cin.ignore(); // Clear input buffer
    string sentence;
    cout << "Enter the sentence: ";
    getline(cin, sentence);

    cout << "Modified Sentence: " << replace_words(trie, sentence) << endl;
    return 0;
}
