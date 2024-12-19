// Solve the "convert a binary tree to its mirror" problem.

#include <iostream>
using namespace std;

// Structure for a node in the binary tree
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

// Function to convert a binary tree to its mirror
void mirror(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Swap the left and right child
    swap(root->left, root->right);

    // Recursively mirror the left and right subtrees
    mirror(root->left);
    mirror(root->right);
}

// Function to print inorder traversal of the tree
void inorder(Node* root) {
    if (root == nullptr) {
        return;
    }
    
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Function to insert a node in the binary tree (basic BST insertion for simplicity)
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
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    cout << "Inorder traversal of original tree: ";
    inorder(root);
    cout << endl;
    mirror(root);
    cout << "Inorder traversal of mirrored tree: ";
    inorder(root);
    cout << endl;
    return 0;
}
