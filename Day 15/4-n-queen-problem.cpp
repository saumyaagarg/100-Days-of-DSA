// Implement a recursive solution for the N-Queens problem.

#include <iostream>
using namespace std;

#define N 4 // Define the size of the chessboard

// Function to print the board
void print_board(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if it's safe to place a queen at board[row][col]
bool is_safe(int board[N][N], int row, int col) {
    // Check this column on upper rows
    for (int i = 0; i < row; i++) {
        if (board[i][col]) {
            return false;
        }
    }

    // Check the upper left diagonal
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) {
            return false;
        }
    }

    // Check the upper right diagonal
    for (int i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j]) {
            return false;
        }
    }

    return true;
}

// Recursive function to solve the N-Queens problem
bool n_queens(int board[N][N], int row) {
    if (row >= N) {
        // All queens placed successfully
        print_board(board);
        return true;
    }

    bool result = false;
    for (int col = 0; col < N; col++) {
        if (is_safe(board, row, col)) {
            // Place the queen
            board[row][col] = 1;

            // Recur for the next row
            result = n_queens(board, row + 1) || result;

            // Backtrack and remove the queen
            board[row][col] = 0;
        }
    }
    return result;
}

int main() {
    int board[N][N] = {0}; // Initialize the board with all zeros

    if (!n_queens(board, 0)) {
        cout << "No solution exists for " << N << " queens." << endl;
    }

    return 0;
}
