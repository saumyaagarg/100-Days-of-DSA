// Write a program to reverse a string using a stack.

#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to reverse a string using a stack
string reverse_string(string str) {
    stack<char> s;

    // Push all characters of the string onto the stack
    for (char ch : str)
        s.push(ch);

    // Pop characters from the stack to form the reversed string
    string reversed = "";
    while (!s.empty()) {
        reversed += s.top();
        s.pop();
    }

    return reversed;
}

int main() {
    string input;
    cout << "Enter a string to reverse: ";
    getline(cin, input);
    string reversed = reverse_string(input);
    cout << "Reversed string is: " << reversed << endl;
    return 0;
}
