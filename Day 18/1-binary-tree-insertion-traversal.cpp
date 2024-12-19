// Implement a binary tree with insertion and traversal (inorder, preorder, postorder).

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

// Class for the binary tree
class binary_tree {
    public:
        Node* root;

        binary_tree () {
            root = nullptr;
        }

        // Function to insert a node into the binary tree
        Node* insert(Node* node, int value) {
            if (node == nullptr) {
                return new Node(value);                     // Create a new node if the current node is null
            }

            if (value < node->data) {
                node->left = insert(node->left, value);     // Recursively insert into the left subtree
            } else {
                node->right = insert(node->right, value);   // Recursively insert into the right subtree
            }

            return node;                                    // Return the current node
        }

        // Inorder traversal: Left -> Root -> Right
        void inorder(Node* node) {
            if (node == nullptr) return;
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }

        // Preorder traversal: Root -> Left -> Right
        void preorder(Node* node) {
            if (node == nullptr) return;
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }

        // Postorder traversal: Left -> Right -> Root
        void postorder(Node* node) {
            if (node == nullptr) return;
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
};

int main() {
    binary_tree tree;
    tree.root = tree.insert(tree.root, 50);
    tree.insert(tree.root, 30);
    tree.insert(tree.root, 70);
    tree.insert(tree.root, 20);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 60);
    tree.insert(tree.root, 80);
    cout << "Inorder Traversal: ";
    tree.inorder(tree.root);
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.preorder(tree.root);
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.postorder(tree.root);
    cout << endl;
    return 0;
}
