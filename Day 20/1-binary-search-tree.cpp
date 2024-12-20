// Implement a binary search tree with insertion, deletion, and search operations.

#include <iostream>
using namespace std;

// Define the structure for the node of the BST
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

// Class to represent the Binary Search Tree
class binary_search_tree {
    private:
        Node* root;

        // Helper function for insert operation
        Node* insert(Node* node, int data) {
            if (node == nullptr) {
                return new Node(data);  // If the node is empty, create a new node
            }

            if (data < node->data) {
                node->left = insert(node->left, data);  // Insert in the left subtree
            } else if (data > node->data) {
                node->right = insert(node->right, data);  // Insert in the right subtree
            }

            return node;
        }

        // Helper function for search operation
        bool search(Node* node, int key) {
            if (node == nullptr) {
                return false;  // If node is null, the element is not found
            }

            if (node->data == key) {
                return true;  // Element found
            }

            if (key < node->data) {
                return search(node->left, key);  // Search in the left subtree
            } else {
                return search(node->right, key);  // Search in the right subtree
            }
        }

        // Helper function to find the minimum value node in the BST
        Node* find_min(Node* node) {
            while (node && node->left != nullptr) {
                node = node->left;
            }
            return node;
        }

        // Helper function for deletion operation
        Node* delete_node(Node* node, int key) {
            if (node == nullptr) {
                return node;  // If the node is null, return null
            }

            if (key < node->data) {
                node->left = delete_node(node->left, key);  // Recursively delete in left subtree
            } else if (key > node->data) {
                node->right = delete_node(node->right, key);  // Recursively delete in right subtree
            } else {
                // Node to be deleted is found
                if (node->left == nullptr) {
                    Node* temp = node->right;
                    delete node;  // Delete the node and return its right subtree
                    return temp;
                } else if (node->right == nullptr) {
                    Node* temp = node->left;
                    delete node;  // Delete the node and return its left subtree
                    return temp;
                }

                // Node has two children, find the inorder successor
                Node* temp = find_min(node->right);
                node->data = temp->data;  // Copy the inorder successor's value to this node
                node->right = delete_node(node->right, temp->data);  // Delete the inorder successor
            }
            return node;
        }

        // Helper function to perform inorder traversal
        void inorder(Node* node) {
            if (node == nullptr) {
                return;
            }
            inorder(node->left);  // Visit left subtree
            cout << node->data << " ";  // Visit node
            inorder(node->right);  // Visit right subtree
        }

    public:
        // Constructor to initialize an empty BST
        binary_search_tree() {
            root = nullptr;
        }

        // Public insert function
        void insert(int data) {
            root = insert(root, data);
        }

        // Public search function
        bool search(int key) {
            return search(root, key);
        }

        // Public delete function
        void delete_node(int key) {
            root = delete_node(root, key);
        }

        // Public inorder traversal function
        void inorder() {
            inorder(root);
            cout << endl;
        }
};

int main() {
    binary_search_tree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    cout << "Inorder traversal: ";
    bst.inorder(); 
    cout << "Search for 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    cout << "Search for 100: " << (bst.search(100) ? "Found" : "Not Found") << endl;
    bst.delete_node(20);  // Delete a leaf node
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder();
    bst.delete_node(30);  // Delete a node with one child
    cout << "Inorder traversal after deleting 30: ";
    bst.inorder();
    bst.delete_node(50);  // Delete a node with two children
    cout << "Inorder traversal after deleting 50: ";
    bst.inorder();
    return 0;
}
