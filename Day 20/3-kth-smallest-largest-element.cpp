// Solve the "find the kth smallest/largest element in a BST" problem.

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

// Function to find the kth smallest element in BST
void kth_smallest(Node* root, int& k, int& result) {
    if (root == nullptr || k <= 0) {
        return;
    }

    // Traverse the left subtree first (inorder traversal)
    kth_smallest(root->left, k, result);

    // Decrease k for the current node
    k--;

    // If k becomes 0, we've found the kth smallest element
    if (k == 0) {
        result = root->data;
        return;
    }

    // Traverse the right subtree
    kth_smallest(root->right, k, result);
}

// Function to find the kth largest element in BST
void kth_largest(Node* root, int& k, int& result) {
    if (root == nullptr || k <= 0) {
        return;
    }

    // Traverse the right subtree first (reverse inorder traversal)
    kth_largest(root->right, k, result);

    // Decrease k for the current node
    k--;

    // If k becomes 0, we've found the kth largest element
    if (k == 0) {
        result = root->data;
        return;
    }

    // Traverse the left subtree
    kth_largest(root->left, k, result);
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    int k = 3;
    int result = -1;
    kth_smallest(root, k, result);
    cout << "The 3rd smallest element is: " << result << endl;
    k = 3; 
    result = -1;
    kth_largest(root, k, result);
    cout << "The 3rd largest element is: " << result << endl;
    return 0;
}
