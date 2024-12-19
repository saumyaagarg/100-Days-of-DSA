// Solve the "diameter of a binary tree" problem.

#include <iostream>
using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

// Function to calculate the height of the tree and update the diameter
int calculate_diameter(Node* root, int& diameter) {
    if (root == nullptr) {
        return 0; // Base case: height of an empty tree is 0
    }

    // Calculate the height of the left and right subtrees
    int leftHeight = calculate_diameter(root->left, diameter);
    int rightHeight = calculate_diameter(root->right, diameter);

    // Update the diameter
    diameter = max(diameter, leftHeight + rightHeight);

    // Return the height of the current tree
    return 1 + max(leftHeight, rightHeight);
}

// Function to find the diameter of the binary tree
int find_diameter(Node* root) {
    int diameter = 0;
    calculate_diameter(root, diameter);
    return diameter;
}

// Function to insert a node into the binary tree
Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new Node(value);
    }

    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 3);
    insert(root, 7);
    insert(root, 12);
    insert(root, 17);
    int diameter = find_diameter(root);
    cout << "The diameter of the binary tree is: " << diameter << endl;
    return 0;
}
