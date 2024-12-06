// Write a program to check for balanced parentheses using a stack.

#include <iostream>
#include <stack>
using namespace std;

// Function to check if the given parentheses are balanced
bool is_balanced(string expr) {
    stack<char> st;

    // Traverse the given expression
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            // Push opening brackets onto the stack
            st.push(ch);
        }
        else if (ch == ')' || ch == '}' || ch == ']') {
            // Check for matching closing brackets
            if (st.empty()) {
                return false; // Unmatched closing bracket
            }

            char top = st.top();
            st.pop();

            if ((ch == ')' && top != '(') ||
                (ch == '}' && top != '{') ||
                (ch == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    // If the stack is empty, all brackets are balanced
    return st.empty();
}

int main() {
    string expr;
    cout << "Enter an expression to check for balanced parentheses: ";
    cin >> expr;
    if (is_balanced(expr)) 
        cout << "The parentheses are balanced." << endl;
    else
        cout << "The parentheses are not balanced." << endl;
    return 0;
}
