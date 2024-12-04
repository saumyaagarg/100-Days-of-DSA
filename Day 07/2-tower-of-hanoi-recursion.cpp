// Solve the Tower of Hanoi problem for 3 disks.

#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void tower_of_hanoi(int n, char src, char dest, char aux) {
    // Base case: If there's only one disk, move it directly
    if (n == 1) {
        cout << "Move disk number 1 from " << src << " to " << dest << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary using destination as auxiliary
    tower_of_hanoi(n - 1, src, aux, dest);

    // Step 2: Move the nth disk from source to destination
    cout << "Move disk number " << n << " from " << src << " to " << dest << endl;

    // Step 3: Move the n-1 disks from auxiliary to destination using source as auxiliary
    tower_of_hanoi(n - 1, aux, dest, src);
}

int main() {
    int n = 3; 
    cout << "Steps to solve the Tower of Hanoi for " << n << " disks are as follows:" << endl;
    tower_of_hanoi(n, 'A', 'C', 'B');    // A = source, C = destination, B = auxiliary
    return 0;
}