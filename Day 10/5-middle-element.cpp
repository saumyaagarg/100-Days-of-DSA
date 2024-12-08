// Solve the "find the middle element of a linked list" problem.

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

// Function to find the middle element of the linked list
int find_middle(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
        return -1;
    }

    Node* slow = head; // Slow pointer moves one step
    Node* fast = head; // Fast pointer moves two steps

    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;         // Move slow pointer by 1 step
        fast = fast->next->next;   // Move fast pointer by 2 steps
    }

    return slow->data; // Slow pointer will be at the middle
}

// Function to display the linked list
void display_list(Node* head) {
    if (head == nullptr) {
        cout << "The list is empty." << endl;
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
    int n, data;
    Node* head = nullptr;
    Node* tail = nullptr;

    cout << "Enter the number of nodes: ";
    cin >> n;

    cout << "Enter the elements of the linked list: " << endl;
    for (int i = 0; i < n; ++i) {
        cin >> data;
        Node* newNode = create_node(data);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    cout << "The linked list is: ";
    display_list(head);

    int middle = find_middle(head);
    if (middle != -1) {
        cout << "The middle element of the linked list is: " << middle << endl;
    }

    return 0;
}
