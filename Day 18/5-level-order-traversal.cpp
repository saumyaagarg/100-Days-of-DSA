// Solve the "level-order traversal of a binary tree" problem.

#include <iostream>
#include <queue>
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

// Function to perform level-order traversal
void level_order_traversal(Node* root) {
    if (root == nullptr) {
        return;
    }

    // Create a queue to hold nodes at each level
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        // Get the current node
        Node* current = q.front();
        q.pop();

        // Print the current node's data
        cout << current->data << " ";

        // Enqueue the left child if it exists
        if (current->left != nullptr) {
            q.push(current->left);
        }

        // Enqueue the right child if it exists
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    cout << endl;
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
    cout << "Level-order traversal of the binary tree: ";
    level_order_traversal(root);
    return 0;
}
