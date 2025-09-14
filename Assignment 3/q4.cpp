#include <iostream>
#include <string>
using namespace std;

class Stack {
private:
    char arr[50];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }
    bool isFull() { return top == 49; }

    void push(char c) {
        if (!isFull()) arr[++top] = c;
    }

    char pop() {
        if (!isEmpty()) return arr[top--];
        return '\0';
    }
};

string infixToPostfix(string infix) {
    Stack s;
    string postfix = "";

    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];

        if (isalnum(c)) {
            // Operand ? directly add to postfix
            postfix += c;
        } else {
            // Operator ? push into stack
            s.push(c);
        }
    }
    while (!s.isEmpty()) {
        postfix += s.pop();
    }
    return postfix;
}
int main() {
    string infix;
    cout << "Enter Infix Expression (no brackets): ";
    cin >> infix;

    string postfix = infixToPostfix(infix);
    cout << "Postfix Expression: " << postfix << endl;

    return 0;
}
