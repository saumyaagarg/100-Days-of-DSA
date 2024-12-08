//  Write a program to merge two sorted linked lists.

#include <iostream>
using namespace std;

// Node structure for the linked list
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

// Function to insert a node at the end of the linked list
void insert_at_end(Node*& head, int data) {
    Node* newNode = create_node(data);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to merge two sorted linked lists
Node* merge_sorted_lists(Node* list1, Node* list2) {
    // Base cases
    if (!list1) return list2;
    if (!list2) return list1;

    Node* mergedHead = nullptr;

    if (list1->data < list2->data) {
        mergedHead = list1;
        mergedHead->next = merge_sorted_lists(list1->next, list2);
    } else {
        mergedHead = list2;
        mergedHead->next = merge_sorted_lists(list1, list2->next);
    }

    return mergedHead;
}

// Function to display a linked list
void display_list(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* list1 = nullptr;
    Node* list2 = nullptr;

    int n1, n2, data;

    // Input for the first linked list
    cout << "Enter the number of elements in the first sorted linked list: ";
    cin >> n1;
    cout << "Enter elements of the first sorted linked list: ";
    for (int i = 0; i < n1; ++i) {
        cin >> data;
        insert_at_end(list1, data);
    }

    // Input for the second linked list
    cout << "Enter the number of elements in the second sorted linked list: ";
    cin >> n2;
    cout << "Enter elements of the second sorted linked list: ";
    for (int i = 0; i < n2; ++i) {
        cin >> data;
        insert_at_end(list2, data);
    }

    // Display the input linked lists
    cout << "First Sorted Linked List: ";
    display_list(list1);
    cout << "Second Sorted Linked List: ";
    display_list(list2);

    // Merge the two sorted linked lists
    Node* mergedList = merge_sorted_lists(list1, list2);

    // Display the merged linked list
    cout << "Merged Sorted Linked List: ";
    display_list(mergedList);

    return 0;
}
