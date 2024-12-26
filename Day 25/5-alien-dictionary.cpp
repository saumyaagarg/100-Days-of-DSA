// Solve the "alien dictionary" problem using topological sorting.

#include <iostream>
#include <climits>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 26  // As there are only 26 lowercase English letters

class AlienDictionary {
    private:
        int in_degree[MAX];      // In-degree of each node
        char graph[MAX][MAX];    // Adjacency matrix for the graph
        int num_chars;           // Number of characters in the alphabet

    public:
        // Constructor to initialize graph and in-degree
        AlienDictionary(int n) {
            num_chars = n;
            memset(in_degree, 0, sizeof(in_degree));  // Initialize in-degree to 0
            memset(graph, 0, sizeof(graph));          // Initialize graph with no edges
        }

        // Function to add an edge from 'u' to 'v'
        void add_edge(char u, char v) {
            int u_idx = u - 'a';
            int v_idx = v - 'a';
            if (graph[u_idx][v_idx] == 0) {
                graph[u_idx][v_idx] = 1;    // There is a directed edge from u to v
                in_degree[v_idx]++;         // Increase the in-degree of 'v'
            }
        }

        // Function to perform topological sort and return the result
        string topological_sort() {
            queue<int> q;
            string result = "";

            // Add nodes with 0 in-degree to the queue
            for (int i = 0; i < num_chars; i++) {
                if (in_degree[i] == 0) {
                    q.push(i);
                }
            }

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                result += (char)(u + 'a');

                // Decrease in-degree of neighbors and add them to the queue if in-degree becomes 0
                for (int v = 0; v < num_chars; v++) {
                    if (graph[u][v] == 1) {
                        in_degree[v]--;
                        if (in_degree[v] == 0) {
                            q.push(v);
                        }
                    }
                }
            }

            // If all characters are included in the result, return the result
            if (result.length() == num_chars) {
                return result;
            } else {
                return "";  // Return an empty string if there is a cycle
            }
        }

        // Function to build the graph from the list of words
        void build_graph(string words[], int word_count) {
            for (int i = 0; i < word_count - 1; i++) {
                string word1 = words[i];
                string word2 = words[i + 1];

                // Find the first different character between word1 and word2
                int len = min(word1.length(), word2.length());
                for (int j = 0; j < len; j++) {
                    if (word1[j] != word2[j]) {
                        add_edge(word1[j], word2[j]);
                        break;
                    }
                }
            }
        }
};

int main() {
    string words[] = {"z", "x", "z", "z", "x"};
    int word_count = 5;
    // There are 26 possible lowercase characters
    AlienDictionary alienDict(26);
    // Build the graph from the list of words
    alienDict.build_graph(words, word_count);
    // Get the topological order of characters
    string order = alienDict.topological_sort();
    if (order == "") {
        cout << "There is a cycle in the graph, no valid order possible." << endl;
    } else {
        cout << "The order of characters in the alien language is: " << order << endl;
    }
    return 0;
}
