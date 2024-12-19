// Solve the "zigzag level order traversal of a binary tree" problem.

#include <iostream>
#include <queue>
#include <stack>
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

// Function to perform zigzag level order traversal
void zigzag_level_order(Node* root) {
    if (!root) return;

    queue<Node*> q;                 // Queue for level order traversal
    stack<int> levelStack;          // Stack to reverse the order on alternate levels
    bool leftToRight = true;        // Flag to check the direction of traversal

    q.push(root);                   // Start with the root node

    while (!q.empty()) {
        int levelSize = q.size();   // Number of nodes at current level

        for (int i = 0; i < levelSize; ++i) {
            Node* currentNode = q.front();
            q.pop();

            // If leftToRight is false, push the node data to stack to reverse order
            if (leftToRight) {
                cout << currentNode->data << " ";
            } else {
                levelStack.push(currentNode->data);
            }

            // Add left and right children to the queue for next level
            if (currentNode->left) q.push(currentNode->left);
            if (currentNode->right) q.push(currentNode->right);
        }

        // If leftToRight is false, print the elements from the stack
        if (!leftToRight) {
            while (!levelStack.empty()) {
                cout << levelStack.top() << " ";
                levelStack.pop();
            }
        }

        // Alternate the direction for the next level
        leftToRight = !leftToRight;
        cout << endl;
    }
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
    insert(root, 7);
    cout << "Zigzag level order traversal: " << endl;
    zigzag_level_order(root);
    return 0;
}
