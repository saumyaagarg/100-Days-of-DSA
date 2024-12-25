// Solve the "k closest points to the origin" problem using a priority queue.

#include <iostream>
#include <queue>
#include <cmath>
#include <unordered_map>
using namespace std;

#define MAX 100     // Maximum size of the points array

struct Point {
    int x, y;
    
    // Calculate distance squared (no need for square root to compare distances)
    int distance() const {
        return x * x + y * y;
    }

    bool operator<(const Point& other) const {
        return distance() > other.distance();   // Min Heap property (smallest distance at the top)
    }
};

void k_closest_points(int points[][2], int n, int k, int result[][2]) {
    priority_queue<Point> min_heap;

    // Step 1: Add points to the min heap based on their distance from the origin
    for (int i = 0; i < n; i++) {
        min_heap.push({points[i][0], points[i][1]});
        if (min_heap.size() > k) {
            min_heap.pop();  // Maintain only the k closest points
        }
    }

    // Step 2: Extract the k closest points from the heap and store them in the result
    int index = 0;
    while (!min_heap.empty()) {
        Point top = min_heap.top();
        min_heap.pop();
        result[index][0] = top.x;
        result[index][1] = top.y;
        index++;
    }
}

int main() {
    int points[MAX][2] = {{1, 3}, {-2, 2}, {5, 8}, {0, 1}};
    int n = 4;  // Number of points
    int k = 2;  // Number of closest points to find
    int result[MAX][2];
    k_closest_points(points, n, k, result);
    cout << "K closest points to the origin are:\n";
    for (int i = 0; i < k; i++) {
        cout << "(" << result[i][0] << ", " << result[i][1] << ")\n";
    }
    return 0;
}
