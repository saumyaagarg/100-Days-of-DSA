//  Write a program to implement a deque using arrays.

#include <iostream>
using namespace std;

#define MAX 1000

class Deque {
    int arr[MAX];
    int front, rear;

    public:
        Deque() {
            front = -1;
            rear = -1;
        }

        // Check if the deque is empty
        bool isEmpty() {
            return (front == -1);
        }

        // Check if the deque is full
        bool isFull() {
            return (front == 0 && rear == MAX - 1) || (front == rear + 1);
        }

        // Insert an element at the front
        void insertFront(int x) {
            if (isFull()) {
                cout << "Deque is full!" << endl;
                return;
            }
            if (front == -1)
                front = rear = 0;
            else if (front == 0)
                front = MAX - 1;
            else
                front--;
            arr[front] = x;
            cout << x << " inserted at the front" << endl;
        }

        // Insert an element at the rear
        void insertRear(int x) {
            if (isFull()) {
                cout << "Deque is full!" << endl;
                return;
            }
            if (front == -1)
                front = rear = 0;
            else if (rear == MAX - 1)
                rear = 0;
            else
                rear++;
            arr[rear] = x;
            cout << x << " inserted at the rear" << endl;
        }

        // Delete an element from the front
        void deleteFront() {
            if (isEmpty()) {
                cout << "Deque is empty!" << endl;
                return;
            }
            cout << arr[front] << " deleted from the front" << endl;
            if (front == rear)
                front = rear = -1;
            else if (front == MAX - 1)
                front = 0;
            else
                front++;
        }

        // Delete an element from the rear
        void deleteRear() {
            if (isEmpty()) {
                cout << "Deque is empty!" << endl;
                return;
            }
            cout << arr[rear] << " deleted from the rear" << endl;
            if (front == rear)
                front = rear = -1;
            else if (rear == 0)
                rear = MAX - 1;
            else
                rear--;
        }

        // Get the front element
        int getFront() {
            if (isEmpty()) {
                cout << "Deque is empty!" << endl;
                return -1;
            }
            return arr[front];
        }

        // Get the rear element
        int getRear() {
            if (isEmpty()) {
                cout << "Deque is empty!" << endl;
                return -1;
            }
            return arr[rear];
        }
};

int main() {
    Deque dq;
    int choice, value;

    while (true) {
        cout << "\nDeque Operations Menu: ";
        cout << "\n1. Insert at Front";
        cout << "\n2. Insert at Rear";
        cout << "\n3. Delete from Front";
        cout << "\n4. Delete from Rear";
        cout << "\n5. Get Front";
        cout << "\n6. Get Rear";
        cout << "\n7. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert at front: ";
                cin >> value;
                dq.insertFront(value);
                break;
            case 2:
                cout << "Enter value to insert at rear: ";
                cin >> value;
                dq.insertRear(value);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << "Front element: " << dq.getFront() << endl;
                break;
            case 6:
                cout << "Rear element: " << dq.getRear() << endl;
                break;
            case 7:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
