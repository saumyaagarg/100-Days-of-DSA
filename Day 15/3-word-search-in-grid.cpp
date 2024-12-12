// Solve the "word search in a grid" problem using recursion and backtracking.

#include <iostream>
using namespace std;

// Directions for moving in the grid (right, left, down, up)
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// Recursive function to perform word search
bool search_word(char grid[][4], int rows, int cols, string word, int x, int y, int index) {
    if (index == word.length()) {
        // If all characters are found, return true
        return true;
    }

    // Check boundaries and if the current cell matches the character
    if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] != word[index]) {
        return false;
    }

    // Temporarily mark the cell as visited
    char temp = grid[x][y];
    grid[x][y] = '#';

    // Explore all 4 directions
    for (int d = 0; d < 4; d++) {
        int newX = x + dx[d];
        int newY = y + dy[d];
        if (search_word(grid, rows, cols, word, newX, newY, index + 1)) {
            return true;
        }
    }
    // Backtrack by restoring the cell
    grid[x][y] = temp;
    return false;
}

// Function to find the word in the grid
bool find_word(char grid[][4], int rows, int cols, string word) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (grid[i][j] == word[0]) { // Start search if first character matches
                if (search_word(grid, rows, cols, word, i, j, 0)) {
                    return true;
                }
            }
        }
    }
    return false;
}

int main() {
    char grid[3][4] = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C', 'S'},
        {'A', 'D', 'E', 'E'}
    };
    string word = "BCE"; // Word to search
    if (find_word(grid, 3, 4, word)) {
        cout << "Word found in the grid!" << endl;
    } else {
        cout << "Word not found in the grid!" << endl;
    }
    return 0;
}
