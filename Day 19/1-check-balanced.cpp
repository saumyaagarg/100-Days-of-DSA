// Solve the "check if a binary tree is balanced" problem.

#include <iostream>
#include <algorithm>
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

// Function to check the height of the tree and check if it's balanced
int check_balance(Node* root, bool& isBalanced) {
    if (root == nullptr) {
        return 0; // Base case: height of an empty tree is 0
    }

    // Recursively get the height of left and right subtrees
    int leftHeight = check_balance(root->left, isBalanced);
    int rightHeight = check_balance(root->right, isBalanced);

    // If the left or right subtree is unbalanced, propagate false
    if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
        isBalanced = false;
        return -1; // Return -1 to indicate an unbalanced tree
    }

    // Return the height of the current tree
    return 1 + max(leftHeight, rightHeight);
}

// Function to check if the tree is balanced
bool is_balanced_tree(Node* root) {
    bool isBalanced = true;
    check_balance(root, isBalanced);
    return isBalanced;
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
    if (is_balanced_tree(root)) {
        cout << "The binary tree is balanced." << endl;
    } else {
        cout << "The binary tree is not balanced." << endl;
    }
    return 0;
}
