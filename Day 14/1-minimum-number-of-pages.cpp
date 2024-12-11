// Solve the "allocate minimum number of pages" problem using binary search.

#include <iostream>
#include <climits>
using namespace std;

// Function to check if a distribution is possible with the given max pages
bool is_possible(int books[], int n, int students, int max_pages) {
    int allocated_students = 1;
    int current_pages = 0;

    for (int i = 0; i < n; i++) {
        if (books[i] > max_pages) {
            return false; // A single book has more pages than maxPages
        }

        if (current_pages + books[i] > max_pages) {
            allocated_students++;
            current_pages = books[i]; // Allocate to the next student
            if (allocated_students > students) {
                return false;
            }
        } else {
            current_pages += books[i];
        }
    }

    return true;
}

// Function to find the minimum pages
int min_pages(int books[], int n, int students) {
    if (students > n) {
        return -1; // Not enough books for each student
    }

    int low = 0, high = 0;
    for (int i = 0; i < n; i++) {
        high += books[i];
    }

    int result = INT_MAX;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (is_possible(books, n, students, mid)) {
            result = mid;  // Update result and try for a smaller maximum
            high = mid - 1;
        } else {
            low = mid + 1; // Try for a larger maximum
        }
    }

    return result;
}

int main() {
    int books[] = {15, 24, 47, 70}; // Number of pages in each book
    int n = sizeof(books) / sizeof(books[0]);
    int students = 3; 

    cout << "Books array: ";
    for (int i = 0; i < n; i++) {
        cout << books[i] << " ";
    }
    cout << endl;

    int result = min_pages(books, n, students);

    if (result != -1) {
        cout << "Minimum pages that can be allocated: " << result << endl;
    } else {
        cout << "Not enough books for all students." << endl;
    }

    return 0;
}
