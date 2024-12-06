// Implement a stack that supports push, pop, and finding the minimum element in O(1) time.

#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    private:
        stack<int> s;        // Main stack to store elements
        stack<int> minStack; // Auxiliary stack to store minimum elements

    public:
        // Push an element onto the stack
        void push(int x) {
            s.push(x);
            // If the minStack is empty or the current element is smaller than the current minimum, push it onto the minStack
            if (minStack.empty() || x <= minStack.top())
            minStack.push(x);
        }

        // Pop the top element from the stack
        void pop() {
            if (!s.empty()) {
                // If the element to be popped is the same as the current minimum, pop from the minStack as well
                if (s.top() == minStack.top())
                    minStack.pop();
                s.pop();
            }
            else
                cout << "Stack is empty!" << endl;
        }

        // Get the minimum element in the stack
        int getMin() {
            if (!minStack.empty())
                return minStack.top();
            return -1; // Return -1 if the stack is empty
        }
};

int main() {
    MinStack stack;
    int choice, num;

    while (true) {
        cout << "\nChoose an operation:\n";
        cout << "1. Push an element\n";
        cout << "2. Pop an element\n";
        cout << "3. Get the minimum element\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter the element to push: ";
                cin >> num;
                stack.push(num);
                cout << num << " pushed onto stack." << endl;
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                num = stack.getMin();
                if (num == -1)
                    cout << "Stack is empty!" << endl;
                else
                    cout << "Minimum element is: " << num << endl;
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
            }
        }
    return 0;
}
