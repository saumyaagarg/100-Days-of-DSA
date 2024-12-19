// Solve the "find the height of a binary tree" problem.

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

        binary_tree() {
            root = nullptr;
        }

        // Function to insert a node into the binary tree
        Node* insert(Node* node, int value) {
            if (node == nullptr) {
                return new Node(value);
            }

            if (value < node->data) {
                node->left = insert(node->left, value);
            } else {
                node->right = insert(node->right, value);
            }

            return node;
        }

        // Function to find the height of the binary tree
        int find_height(Node* node) {
            if (node == nullptr) {
                return 0;   // Base case: height of an empty tree is 0
            }

            // Recursively find the height of left and right subtrees
            int left_height = find_height(node->left);
            int right_height = find_height(node->right);

            // Height is 1 + the maximum of leftHeight and rightHeight
            return 1 + max(left_height, right_height);
        }
};

int main() {
    binary_tree tree;
    tree.root = tree.insert(tree.root, 10);
    tree.insert(tree.root, 5);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 3);
    tree.insert(tree.root, 7);
    tree.insert(tree.root, 18);
    int height = tree.find_height(tree.root);
    cout << "Height of the binary tree: " << height << endl;
    return 0;
}