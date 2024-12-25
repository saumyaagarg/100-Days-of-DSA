// Solve the "number of islands" problem using BFS/DFS.

#include <iostream>
using namespace std;

#define ROWS 5  // Number of rows in the grid
#define COLS 5  // Number of columns in the grid

// Directions for moving in 4 adjacent directions (left, right, up, down)
int row_dirs[] = {-1, 1, 0, 0};
int col_dirs[] = {0, 0, -1, 1};

// Function to perform DFS and mark the connected land
void DFS(char grid[ROWS][COLS], int visited[ROWS][COLS], int row, int col) {
    // Stack-based DFS approach to avoid recursion limit issues
    visited[row][col] = 1;
    
    // Explore all adjacent cells (up, down, left, right)
    for (int i = 0; i < 4; i++) {
        int new_row = row + row_dirs[i];
        int new_col = col + col_dirs[i];
        
        // Check if the new position is within bounds and is land ('1') and not visited
        if (new_row >= 0 && new_row < ROWS && new_col >= 0 && new_col < COLS
            && grid[new_row][new_col] == '1' && visited[new_row][new_col] == 0) {
            DFS(grid, visited, new_row, new_col);
        }
    }
}

// Function to count the number of islands in the grid
int no_islands(char grid[ROWS][COLS]) {
    int visited[ROWS][COLS] = {0};          // Array to keep track of visited cells
    int count = 0;

    // Traverse the grid
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // If we find an unvisited land cell, it's the start of a new island
            if (grid[i][j] == '1' && visited[i][j] == 0) {
                DFS(grid, visited, i, j);   // Mark all connected land cells
                count++;                    // Increment island count
            }
        }
    }

    return count;
}

int main() {
    // 5x5 grid with some land ('1') and water ('0')
    char grid[ROWS][COLS] = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'},
        {'0', '0', '0', '0', '1'}
    };
    int result = no_islands(grid);
    cout << "Number of islands: " << result << endl;
    return 0;
}
