// Solve the "validate if a tree is a binary search tree" problem.

#include <iostream>
#include <climits>
using namespace std;

// Define the structure for a node in the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a node
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

// Function to validate if a binary tree is a BST
bool is_valid_bst(Node* node, long long minValue, long long maxValue) {
    if (node == nullptr) {
        return true;    // An empty tree is a valid BST
    }

    // Check the current node's value is within the valid range
    if (node->data <= minValue || node->data >= maxValue) {
        return false;
    }

    // Recursively check the left and right subtrees with updated constraints
    return is_valid_bst(node->left, minValue, node->data) && is_valid_bst(node->right, node->data, maxValue);
}

// Wrapper function to validate if the binary tree is a BST
bool is_bst(Node* root) {
    return is_valid_bst(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(1);
    root->left->right = new Node(8);
    root->right->left = new Node(15);
    root->right->right = new Node(25);
    if (is_bst(root)) {
        cout << "The tree is a valid Binary Search Tree." << endl;
    } else {
        cout << "The tree is NOT a valid Binary Search Tree." << endl;
    }
    return 0;
}
