//Solve the "detect a cycle in a linked list" problem using Floyd’s Cycle Detection algorithm.

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* create_node(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Function to detect a cycle in the linked list using Floyd’s Cycle Detection Algorithm
bool detect_cycle(Node* head) {
    Node* slow = head; // Slow pointer
    Node* fast = head; // Fast pointer

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps

        if (slow == fast) {        // If both pointers meet, a cycle is detected
            return true;
        }
    }
    return false;                  // If no cycle is detected
}

// Function to print the linked list
void display_list(Node* head) {
    Node* slow = head;
    Node* fast = head;
    bool cycleDetected = false;

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            cycleDetected = true;
            break;
        }
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;

        // Break if the node is revisited
        if (cycleDetected && temp == slow) {
            cout << "(cycle detected)";
            break;
        }
    }
    
    if (!cycleDetected) {
        cout << "NULL";
    }
    cout << endl;
}

int main() {
    Node* head = create_node(1);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(4);
    head->next->next->next->next = create_node(5);

    // Creating a cycle in the linked list
    head->next->next->next->next->next = head->next->next;

    cout << "Linked List: ";
    display_list(head);

    if (detect_cycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
