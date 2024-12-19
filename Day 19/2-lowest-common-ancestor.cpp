// Solve the "find the lowest common ancestor of two nodes in a binary tree" problem.

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

// Function to find the lowest common ancestor of two nodes
Node* find_lca(Node* root, int n1, int n2) {
    // Base case: if the tree is empty or if we reach a leaf node
    if (root == nullptr) {
        return nullptr;
    }

    // If either n1 or n2 matches the root's data, return root
    if (root->data == n1 || root->data == n2) {
        return root;
    }

    // Recur for left and right subtrees
    Node* left_lca = find_lca(root->left, n1, n2);
    Node* right_lca = find_lca(root->right, n1, n2);

    // If both left and right calls return non-null, the current node is the LCA
    if (left_lca && right_lca) {
        return root;
    }

    // Otherwise, return the non-null child (either left or right)
    return (left_lca != nullptr) ? left_lca : right_lca;
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

// Function to print the result
void print_lca(Node* lca) {
    if (lca != nullptr) {
        cout << "Lowest Common Ancestor: " << lca->data << endl;
    } else {
        cout << "Lowest Common Ancestor not found." << endl;
    }
}

int main() {
    // Create a binary tree
    Node* root = nullptr;
    root = insert(root, 20);
    insert(root, 10);
    insert(root, 30);
    insert(root, 5);
    insert(root, 15);
    insert(root, 25);
    insert(root, 35);
    int n1 = 5, n2 = 15; // Nodes to find the LCA for
    Node* lca = find_lca(root, n1, n2);
    print_lca(lca);
    return 0;
}
