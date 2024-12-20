// Solve the "find the floor and ceil of a given key in a BST" problem.

#include <iostream>
using namespace std;

// Define the structure for a node in the BST
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor for initializing a node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to find the floor of a key in the BST
int find_floor(Node* root, int key) {
    int floor = -1;                 // Initialize floor as -1 (indicating no floor found)
    while (root != nullptr) {
        if (root->data == key) {
            return root->data;      // If key matches, it is its own floor
        } else if (key > root->data) {
            floor = root->data;     // Update floor to current node value
            root = root->right;     // Move to the right subtree
        } else {
            root = root->left;      // Move to the left subtree
        }
    }
    return floor;
}

// Function to find the ceil of a key in the BST
int find_ceil(Node* root, int key) {
    int ceil = -1;                  // Initialize ceil as -1 (indicating no ceil found)
    while (root != nullptr) {
        if (root->data == key) {
            return root->data;      // If key matches, it is its own ceil
        } else if (key < root->data) {
            ceil = root->data;      // Update ceil to current node value
            root = root->left;      // Move to the left subtree
        } else {
            root = root->right;     // Move to the right subtree
        }
    }
    return ceil;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int key = 65;
    int floor = find_floor(root, key);
    int ceil = find_ceil(root, key);
    cout << "The floor of " << key << " is: " << (floor == -1 ? "None" : to_string(floor)) << endl;
    cout << "The ceil of " << key << " is: " << (ceil == -1 ? "None" : to_string(ceil)) << endl;
    return 0;
}
