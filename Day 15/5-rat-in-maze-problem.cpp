// Solve the "rat in a maze" problem using recursion.

#include <iostream>
using namespace std;

#define N 4  // Define the size of the maze (N x N)

// Function to print the solution path
void print_solution(int sol[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << sol[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if it's safe to move to grid[x][y]
bool is_safe(int maze[N][N], int x, int y) {
    // Check if (x, y) is within the grid and is a valid path (1)
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

// Recursive function to solve the Maze problem
bool solve_maze(int maze[N][N], int x, int y, int sol[N][N]) {
    // If the rat reaches the bottom-right corner, the solution is found
    if (x == N - 1 && y == N - 1) {
        sol[x][y] = 1;
        return true;
    }

    // Check if the current position is safe
    if (is_safe(maze, x, y)) {
        // Mark the current cell as part of the solution path
        sol[x][y] = 1;

        // Move to the right (x, y + 1)
        if (solve_maze(maze, x, y + 1, sol)) {
            return true;
        }

        // Move down (x + 1, y)
        if (solve_maze(maze, x + 1, y, sol)) {
            return true;
        }

        // If none of the above moves work, backtrack
        sol[x][y] = 0;
        return false;
    }

    return false; // If the position is not safe, return false
}

int main() {
    // Define a sample maze where 1 represents a valid path and 0 is blocked
    int maze[N][N] = {
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
    };
    int sol[N][N] = {0};
    if (solve_maze(maze, 0, 0, sol)) {
        cout << "Solution Path:" << endl;
        print_solution(sol);
    } else {
        cout << "No solution exists." << endl;
    }
    return 0;
}
