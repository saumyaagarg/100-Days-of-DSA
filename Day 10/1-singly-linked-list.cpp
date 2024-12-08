// Implement a singly linked list with operations for insertion, deletion, and traversal.

#include <iostream>
using namespace std;

// Define a Node structure
struct Node {
    int data;
    Node *next;

    // Constructor to initialize a node
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Singly Linked List class
class singly_linked_list {
    private:
        Node *start; 

    public:
        // Constructor to initialize an empty list
        singly_linked_list() {
            start = nullptr;
        }

        // Function to insert a node at the beginning
        void insert_at_beginning(int data) {
            Node *newNode = new Node(data);
            newNode->next = start;
            start = newNode;
            display();
        }

        // Function to insert at the end
        void insert_at_end(int data) {
            Node *newNode = new Node(data);
            if (start == nullptr)
                start = newNode;
            else {
                Node *temp = start;
                while (temp->next != nullptr)
                    temp = temp->next;
                temp->next = newNode;
            }
            display();
        }

        // Function to insert after a particular element
        void insert_after_element(int data1, int data2) {
            Node *temp = start;
            while (temp != nullptr && temp->data != data2)
                temp = temp->next;
            if (temp != nullptr) {
                Node *newNode = new Node(data1);
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
                cout << "Element " << data2 << " not found!" << endl;
            display();
        }

        // Function to insert before a particular element
        void insert_before_element(int data1, int data2) {
            if (start == nullptr) {
                cout << "List is empty!" << endl;
                return;
            }
            if (start->data == data2) {
                insert_at_beginning(data1);
                return;
            }

            Node *temp = start;
            while (temp->next != nullptr && temp->next->data != data2) 
                temp = temp->next;
            if (temp->next != nullptr) {
                Node *newNode = new Node(data1);
                newNode->next = temp->next;
                temp->next = newNode;
            }
            else
                cout << "Element " << data2 << " not found!" << endl;
            display();
        }

        // Function to delete at the beginning
        void delete_at_beginning() {
            if (start == nullptr) {
                cout << "LinkedList is already empty!" << endl;
                return;
            }
            Node *temp = start;
            start = start->next;
            delete temp;
            display();
        }

        // Function to delete at the end
        void delete_at_end() {
            if (start == nullptr) {
                cout << "LinkedList is already empty!" << endl;
                return;
            }
            if (start->next == nullptr) {
                delete start;
                start = nullptr;
                return;
            }

            Node *temp = start;
            while (temp->next != nullptr && temp->next->next != nullptr)
                temp = temp->next;
            delete temp->next;
            temp->next = nullptr;
            display();
        }

        // Function to delete after a particular element
        void delete_after_element(int data) {
            Node *temp = start;
            while (temp != nullptr && temp->data != data)
                temp = temp->next;
            if (temp != nullptr && temp->next != nullptr) {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
                cout << "Element " << data << " not found or no node after it!" << endl;
            display();
        }

        // Function to delete before a particular element
        void delete_before_element(int data) {
            if (start == nullptr || start->next == nullptr) {
                cout << "LinkedList is too short to delete before the element!" << endl;
                return;
            }
            if (start->data == data) {
                cout << "No element before " << data << " to delete!" << endl;
                return;
            }

            Node *temp = start;
            while (temp->next != nullptr && temp->next->data != data)
                temp = temp->next;
            if (temp->next != nullptr && temp->next->next != nullptr) {
                Node *nodeToDelete = temp;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
                cout << "Element " << data << " not found!" << endl;
            display();
        }

        // Function to delete a particular element
        void delete_element(int data) {
            if (start == nullptr) {
                cout << "LinkedList is empty!" << endl;
                return;
            }
            if (start->data == data) {
                Node *temp = start;
                start = start->next;
                delete temp;
                display();
                return;
            }

            Node *temp = start;
            while (temp->next != nullptr && temp->next->data != data)
                temp = temp->next;
            if (temp->next != nullptr) {
                Node *nodeToDelete = temp->next;
                temp->next = temp->next->next;
                delete nodeToDelete;
            }
            else
                cout << "Element " << data << " not found!" << endl;
            display();
        }

        // Function to display the linked list
        void display() {
            if (start == nullptr) {
                cout << "LinkedList is empty!" << endl;
                return;
            }
            Node *temp = start;
            while (temp != nullptr) {
                cout << " --> " << temp->data;
                temp = temp->next;
            }
            cout << endl;
        }

        // Destructor to free memory
        ~singly_linked_list() {
            while (start) {
                Node *temp = start;
                start = start->next;
                delete temp;
            }
        }
};

int main() {
    singly_linked_list list;
    int choice, data, data1, data2;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Display the list\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Where would you like to insert:\n";
                cout << "1. At the beginning\n";
                cout << "2. At the end\n";
                cout << "3. After an element\n";
                cout << "4. Before an element\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        cout << "Enter the data: ";
                        cin >> data;
                        list.insert_at_beginning(data);
                        break;
                    case 2:
                        cout << "Enter the data: ";
                        cin >> data;
                        list.insert_at_end(data);
                        break;
                    case 3:
                        cout << "Enter the data of the node after which you want to insert your node: ";
                        cin >> data2;
                        cout << "Enter the data: ";
                        cin >> data1;
                    list.insert_after_element(data1, data2);
                        break;
                    case 4:
                        cout << "Enter the data of the node before which you want to insert your node: ";
                        cin >> data2;
                        cout << "Enter the data: ";
                        cin >> data1;
                        list.insert_before_element(data1, data2);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                break;

            case 2:
                cout << "Which element would you like to delete:\n";
                cout << "1. First\n";
                cout << "2. Last\n";
                cout << "3. After an element\n";
                cout << "4. Before an element\n";
                cout << "5. By data\n";
                cout << "Enter your choice: ";
                cin >> choice;
                switch (choice) {
                    case 1:
                        list.delete_at_beginning();
                        break;
                    case 2:
                        list.delete_at_end();
                        break;
                    case 3:
                        cout << "Enter the element whose next element you want to delete: ";
                        cin >> data;
                        list.delete_after_element(data);
                        break;
                    case 4:
                        cout << "Enter the element whose previous element you want to delete: ";
                        cin >> data;
                        list.delete_before_element(data);
                        break;
                    case 5:
                        cout << "Enter the data of the node you want to delete: ";
                        cin >> data;
                        list.delete_element(data);
                        break;
                    default:
                        cout << "Invalid choice!" << endl;
                        break;
                    }
                break;

            case 3:
                cout << "Linked List: ";
                list.display();
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice! Please try again." << endl;
                break;
        }
    }
    return 0;
}
