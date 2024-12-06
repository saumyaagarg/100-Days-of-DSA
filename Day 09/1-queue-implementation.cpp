// Implement a queue using arrays.

#include <iostream>
using namespace std;

class Queue {
    private:
        int front, rear, size;
        int *arr;

    public:
        // Constructor to initialize the queue
        Queue(int capacity) {
            size = capacity;
            front = -1;
            rear = -1;
            arr = new int[size];
        }

        // Destructor to deallocate memory
        ~Queue() {
            delete[] arr;
        }

        // Check if the queue is full
        bool isFull() {
            return (rear + 1) % size == front;
        }

        // Check if the queue is empty
        bool isEmpty() {
            return front == -1;
        }

        // Add an element to the queue
        void enqueue(int x) {
            if (isFull()) {
                cout << "Queue Overflow! Cannot insert " << x << endl;
                return;
            }
            if (isEmpty()) {
                front = 0; // Initialize front if the queue is empty
            }
            rear = (rear + 1) % size;
            arr[rear] = x;
            cout << x << " enqueued to the queue." << endl;
        }

        // Remove an element from the queue
        int dequeue() {
            if (isEmpty()) {
                cout << "Queue Underflow! Cannot dequeue." << endl;
                return -1;
            }
            int data = arr[front];
            if (front == rear) {
                // Reset the queue if it becomes empty after dequeue
                front = -1;
                rear = -1;
            }
            else
                front = (front + 1) % size; // Update front in a circular manner
            return data;
        }

        // Get the front element of the queue
        int peek() {
            if (isEmpty()) {
                cout << "Queue is Empty!" << endl;
                return -1;
            }
            return arr[front];
        }

        // Display the queue elements
        void display() {
            if (isEmpty()) {
                cout << "Queue is Empty!" << endl;
                return;
            }
            cout << "Queue elements are: ";
            int i = front;
            while (true) {
                cout << arr[i] << " ";
                if (i == rear)
                    break;
                i = (i + 1) % size;
            }
            cout << endl;
        }
};

int main() {
    int n, choice, value;
    cout << "Enter the size of the queue: ";
    cin >> n;
    Queue q(n);

    do {
        cout << "\nQueue Operations Menu:\n"
             << "1. Enqueue\n"
             << "2. Dequeue\n"
             << "3. Peek\n"
             << "4. Display\n"
             << "5. Exit\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                value = q.dequeue();
                if (value != -1)
                    cout << "Dequeued value: " << value << endl;
                break;
            case 3:
                value = q.peek();
                if (value != -1)
                    cout << "Front of the queue: " << value << endl;
                break;
            case 4:
                q.display();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
