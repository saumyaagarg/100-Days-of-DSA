// Solve the "flatten a binary tree to a linked list" problem.

#include <iostream>
using namespace std;

// Definition for a binary tree node.
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

// Function to flatten the binary tree
void flatten(Node* root) {
    if (!root) return;

    // Recursively flatten the left and right subtrees
    if (root->left) {
        flatten(root->left);

        // Save the right child before overwriting
        Node* temp = root->right;
        
        // Move the left child to the right
        root->right = root->left;
        root->left = nullptr;

        // Move to the last node in the new right subtree (which was the left subtree)
        Node* current = root->right;
        while (current->right) {
            current = current->right;
        }

        // Connect the original right subtree to the last node of the new right subtree
        current->right = temp;
    }

    // Flatten the right subtree
    flatten(root->right);
}

// Function to print the flattened binary tree (linked list)
void print_flattened(Node* root) {
    Node* current = root;
    while (current) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

// Function to insert nodes in the binary tree (for testing purposes)
Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else {
        root->right = insert(root->right, value);
    }

    return root;
}

int main() {
    Node* root = nullptr;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);
    insert(root, 6);
    flatten(root);
    cout << "Flattened binary tree to linked list: ";
    print_flattened(root);
    return 0;
}
