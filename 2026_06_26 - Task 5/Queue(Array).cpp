#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;
string queue[MAX_SIZE];
int front = 0;
int rear = -1;
int count = 0;

void enqueue(string name) {
    if (count == MAX_SIZE) {
        cout << "Queue is full!" << endl;
        return;
    }
    rear = (rear + 1) % MAX_SIZE;
    queue[rear] = name;
    count++;
}

string dequeue() {
    if (count == 0) {
        return "Empty";
    }
    string name = queue[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return name;
}

string peek() {
    if (count == 0) {
        return "Empty";
    }
    return queue[front];
}

bool isEmpty() {
    return count == 0;
}

void display() {
    if (count == 0) {
        cout << "Empty";
        return;
    }

    int index = front;
    for (int i = 0; i < count; i++) {
        cout << queue[index] << " ";
        index = (index + 1) % MAX_SIZE;
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
    while (!isEmpty()) {
        cout << dequeue() << " ";
    }
    cout << endl;

    return 0;
}