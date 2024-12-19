// Solve the "check if two binary trees are identical" problem.

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

// Function to check if two binary trees are identical
bool are_identical(Node* root1, Node* root2) {
    // Base cases
    if (root1 == nullptr && root2 == nullptr) {
        return true;    // Both trees are empty
    }
    if (root1 == nullptr || root2 == nullptr) {
        return false;   // One tree is empty, and the other is not
    }

    // Check if the data of the current nodes match and recurse for left and right subtrees
    return (root1->data == root2->data) &&
           are_identical(root1->left, root2->left) &&
           are_identical(root1->right, root2->right);
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
    Node* root1 = nullptr;
    root1 = insert(root1, 10);
    insert(root1, 5);
    insert(root1, 15);
    insert(root1, 3);
    insert(root1, 7);

    Node* root2 = nullptr;
    root2 = insert(root2, 10);
    insert(root2, 5);
    insert(root2, 15);
    insert(root2, 3);
    insert(root2, 7);

    if (are_identical(root1, root2)) {
        cout << "The two binary trees are identical." << endl;
    } else {
        cout << "The two binary trees are not identical." << endl;
    }
    return 0;
}
