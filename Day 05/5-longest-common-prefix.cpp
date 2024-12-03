// Solve the "longest common prefix" problem for an array of strings.

#include <iostream>
#include <string>
using namespace std;

// Function to find the longest common prefix
string longest_common_prefix(string strs[], int n) {
    if (n == 0) {
        return "";                    // Return an empty string if no input
    }

    string prefix = strs[0];          // Assume the first string is the prefix initially

    // Compare prefix with each string in the array
    for (int i = 1; i < n; i++) {
        string current = strs[i];
        string temp = "";             // Temporary variable to store the new prefix

        // Compare characters of the prefix and current string
        for (int j = 0; j < prefix.length() && j < current.length(); j++) {
            if (prefix[j] == current[j]) {
                temp += prefix[j];    // Add matching characters to temp
            }
            else {
                break;                // Stop when a mismatch is found
            }
        }

        prefix = temp;               // Update prefix with the new common prefix
        if (prefix.empty()) {        // If prefix becomes empty, no common prefix exists
            break;
        }
    }

    return prefix; 
}

int main() {
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;     
    cin.ignore();     // Clear the buffer for getline

    string strs[n]; 

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        getline(cin, strs[i]); 
    }

    // Find and display the longest common prefix
    string result = longest_common_prefix(strs, n);
    if (result.empty()) {
        cout << "There is no common prefix among the given strings." << endl;
    }
    else {
        cout << "The longest common prefix is: " << result << endl;
    }
    return 0;
}
