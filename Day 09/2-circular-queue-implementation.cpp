// Write a program to implement a circular queue.

#include <iostream>
using namespace std;

class CircularQueue {
    private:
        int front, rear, size;
        int *queue;

    public:
        CircularQueue(int n) {
            size = n;
            queue = new int[size];
            front = -1;
            rear = -1;
        }

        ~CircularQueue() {
            delete[] queue;
        }

        bool isFull() {
            return (front == (rear + 1) % size);
        }

        bool isEmpty() {
            return (front == -1);
        }

        void enqueue(int value) {
            if (isFull()) {
                cout << "Queue is Full! Cannot enqueue " << value << "." << endl;
                return;
            }
            if (isEmpty()) {
                front = 0;
            }
            rear = (rear + 1) % size;
            queue[rear] = value;
            cout << value << " enqueued to the queue." << endl;
        }

        void dequeue() {
            if (isEmpty()) {
                cout << "Queue is Empty! Cannot dequeue." << endl;
                return;
            }
            cout << "Dequeued " << queue[front] << " from the queue." << endl;
            if (front == rear) {
                // Queue becomes empty
                front = rear = -1;
            }
            else
                front = (front + 1) % size;
        }

        void peek() {
            if (isEmpty())
                cout << "Queue is Empty! Nothing at the front." << endl;
            else
                cout << "Front element is: " << queue[front] << endl;
        }

        void display() {
            if (isEmpty()) {
                cout << "Queue is Empty!" << endl;
                return;
            }
            cout << "Queue elements are: ";
            int i = front;
            while (true) {
                cout << queue[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
};

int main() {
    int n, choice, value;
    cout << "Enter the size of the Circular Queue: ";
    cin >> n;
    CircularQueue cq(n);

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cq.display();
                break;
            case 5:
                cout << "Exiting the program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}
