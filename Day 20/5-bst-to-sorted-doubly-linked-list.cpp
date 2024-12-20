// Solve the "convert a BST to a sorted doubly linked list" problem.

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

// Helper function to convert BST to a sorted doubly linked list
void bst_to_doubly_ll(Node* root, Node*& head, Node*& prev) {
    if (root == nullptr) {
        return;             // Base case: empty subtree
    }

    // Recursively convert the left subtree
    bst_to_doubly_ll(root->left, head, prev);

    // Process the current node
    if (prev == nullptr) {
        head = root;        // This is the leftmost (smallest) node
    } else {
        prev->right = root; // Link the previous node to the current node
        root->left = prev;  // Link the current node back to the previous node
    }
    prev = root;            // Update the previous node to the current node

    // Recursively convert the right subtree
    bst_to_doubly_ll(root->right, head, prev);
}

// Function to convert BST to sorted doubly linked list
Node* convert_to_doubly_ll(Node* root) {
    Node* head = nullptr;   // Pointer to the head of the doubly linked list
    Node* prev = nullptr;   // Pointer to keep track of the previous node
    bst_to_doubly_ll(root, head, prev);
    return head;
}

// Function to print the doubly linked list
void print_doubly_ll(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main() {
    Node* root = new Node(50);
    root->left = new Node(30);
    root->right = new Node(70);
    root->left->left = new Node(20);
    root->left->right = new Node(40);
    root->right->left = new Node(60);
    root->right->right = new Node(80);
    Node* head = convert_to_doubly_ll(root);
    cout << "The sorted doubly linked list is: ";
    print_doubly_ll(head);
    return 0;
}
