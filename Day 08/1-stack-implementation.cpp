// Implement a stack using arrays.

#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int top;
    int a[MAX]; // Array to store stack elements

    public:
        Stack() { top = -1; }

        // Function to push an element onto the stack
        bool push(int x) {
            if (top >= (MAX - 1)) {
                cout << "Stack Overflow" << endl;
                return false;
            }
            else {
                a[++top] = x;
                cout << x << " pushed into stack" << endl;
                return true;
            }
        }

        // Function to pop an element from the stack
        int pop() {
            if (top < 0) {
                cout << "Stack Underflow" << endl;
                return 0;
            }
            else {
                int x = a[top--];
                return x;
            }
        }

        // Function to get the top element of the stack
        int peek() {
            if (top < 0) {
                cout << "Stack is Empty" << endl;
                return 0;
            }
            else {
                return a[top];
            }
        }

        // Function to check if the stack is empty
        bool isEmpty() {
            return (top < 0);
        }
};

int main() {
    Stack s;
    int choice, num;

    while (true) {
        cout << "Select an operation to perform:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Top (Peek)\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the number you want to push: ";
                cin >> num;
                s.push(num);
                break;

            case 2:
                if (s.isEmpty()) 
                    cout << "Stack is already empty!" << endl;
                else 
                    cout << s.pop() << " popped from stack" << endl;
                break;

            case 3:
                if (s.isEmpty())
                    cout << "Stack is empty!" << endl;
                else
                    cout << "Element at the top is: " << s.peek() << endl;
                break;

            case 4:
                if (s.isEmpty()) 
                    cout << "Stack is empty!" << endl;
                else
                    cout << "Stack is not empty." << endl;
                break;

            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid input! Please try again." << endl;
            }
    }
}