#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

struct Stack {
    string arr[MAX_SIZE];
    int top;
};

void initStack(Stack& s) {
    s.top = -1;
}

void push(Stack& s, string name) {
    if (s.top >= MAX_SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << name << endl;
        return;
    }
    s.top++;
    s.arr[s.top] = name;
    cout << "Pushed: " << name << endl;
}

string pop(Stack& s) {
    if (s.top == -1) {
        cout << "Stack Underflow! Stack is empty" << endl;
        return "";
    }
    string name = s.arr[s.top];
    s.top--;
    return name;
}

string peek(Stack& s) {
    if (s.top == -1) {
        cout << "Stack is empty" << endl;
        return "";
    }
    return s.arr[s.top];
}

bool isEmpty(Stack& s) {
    return s.top == -1;
}

void display(Stack& s) {
    if (isEmpty(s)) {
        cout << "Stack is empty" << endl;
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = s.top; i >= 0; i--) {
        cout << s.arr[i];
        if (i > 0) cout << " -> ";
    }
    cout << endl;
}

int main() {
    Stack s;
    initStack(s);

    cout << "Pushing elements:" << endl;
    push(s, "Aimar");
    push(s, "Ahmad");
    push(s, "Anajana");
    push(s, "Jessy");
    cout << endl;

    display(s);
    cout << "Top element: " << peek(s) << endl;
    cout << endl;

    cout << "Popping element:" << endl;
    string popped = pop(s);
    cout << "Popped: " << popped << endl;
    cout << endl;

    display(s);
    cout << "Top element: " << peek(s) << endl;
    cout << endl;

    cout << "Pushing more elements:" << endl;
    push(s, "Ali");
    push(s, "Sara");
    cout << endl;

    display(s);

    return 0;
}