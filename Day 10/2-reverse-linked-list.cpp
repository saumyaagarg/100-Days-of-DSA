// Write a program to reverse a linked list.

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a new node at the end of the list
void insert_at_end(Node*& head, int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != nullptr) 
        temp = temp->next;
    temp->next = newNode;
}

// Function to reverse the linked list
void reverse_list(Node*& head) {
    Node* prev = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr) {
        next = current->next;  // Store the next node
        current->next = prev;  // Reverse the current node's link
        prev = current;        // Move prev to the current node
        current = next;        // Move current to the next node
    }
    head = prev; // Update head to the new first node
}

// Function to display the linked list
void display_list(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    int choice, data;

    while (true) {
        cout << "\nMenu:\n1. Insert at End\n2. Reverse List\n3. Display List\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to insert: ";
                cin >> data;
                insert_at_end(head, data);
                break;
            case 2:
                reverse_list(head);
                cout << "The list has been reversed." << endl;
                break;
            case 3:
                cout << "The linked list is: ";
                display_list(head);
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
