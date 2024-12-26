// Solve the "flood fill" problem using DFS.

#include <iostream>
using namespace std;

#define MAX_ROWS 10
#define MAX_COLS 10

// Function to perform DFS for flood fill
void flood_fill_dfs(int image[MAX_ROWS][MAX_COLS], int x, int y, int originalColor, int newColor, int rows, int cols) {
    // Boundary checks and color match check
    if (x < 0 || x >= rows || y < 0 || y >= cols || image[x][y] != originalColor || image[x][y] == newColor) 
        return;

    // Change the color of the current pixel
    image[x][y] = newColor;

    // Recursive calls for 4-directional neighbors
    flood_fill_dfs(image, x + 1, y, originalColor, newColor, rows, cols);   // Down
    flood_fill_dfs(image, x - 1, y, originalColor, newColor, rows, cols);   // Up
    flood_fill_dfs(image, x, y + 1, originalColor, newColor, rows, cols);   // Right
    flood_fill_dfs(image, x, y - 1, originalColor, newColor, rows, cols);   // Left
}

// Wrapper function to start flood fill
void flood_fill(int image[MAX_ROWS][MAX_COLS], int startX, int startY, int newColor, int rows, int cols) {
    int originalColor = image[startX][startY];

    // If the color to change is the same as the new color, no need to do anything
    if (originalColor == newColor) 
        return;

    // Call the DFS function
    flood_fill_dfs(image, startX, startY, originalColor, newColor, rows, cols);
}

// Function to display the grid
void display_image(int image[MAX_ROWS][MAX_COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int image[MAX_ROWS][MAX_COLS] = {
        {1, 1, 1, 0, 0},
        {1, 1, 0, 0, 0},
        {1, 0, 1, 1, 1},
        {0, 0, 1, 1, 0}
    };
    int rows = 4, cols = 5;     // Size of the image
    cout << "Original Image:" << endl;
    display_image(image, rows, cols);
    int startX = 1, startY = 1; // Starting point
    int newColor = 2;           // New color to fill
    flood_fill(image, startX, startY, newColor, rows, cols);
    cout << "Image after Flood Fill:" << endl;
    display_image(image, rows, cols);
    return 0;
}
