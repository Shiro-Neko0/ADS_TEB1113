#include <iostream>
#include <string>
using namespace std;

struct Node {
    string name;
    Node* next;
};

Node* front = NULL;
Node* rear = NULL;

void enqueue(string name) {
    Node* temp = new Node();
    temp->name = name;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}

string dequeue() {
    if (front == NULL) {
        return "Empty";
    }

    Node* temp = front;
    string name = temp->name;
    front = front->next;

    if (front == NULL) {
        rear = NULL;
    }

    delete temp;
    return name;
}

string peek() {
    if (front == NULL) {
        return "Empty";
    }
    return front->name;
}

void display() {
    if (front == NULL) {
        cout << "Empty";
        return;
    }

    Node* current = front;
    while (current != NULL) {
        cout << current->name << " ";
        current = current->next;
    }
}

int main() {
    enqueue("Aimar");
    enqueue("Ahmad");
    enqueue("Anajana");
    enqueue("Jessy");
    
    cout << "Queue: ";
    display();
    cout << "\nFront: " << peek() << endl;

    cout << "\nRemoved: " << dequeue() << endl;
    cout << "Queue: ";
    display();
    cout << "\nFront: " << peek() << endl;

    enqueue("Ali");
    enqueue("Sara");
    
    cout << "\nQueue: ";
    display();
    cout << "\nFront: " << peek() << endl;

    cout << "\nRemoving all: ";
    while (front != NULL) {
        cout << dequeue() << " ";
    }
    cout << endl;

    return 0;
}