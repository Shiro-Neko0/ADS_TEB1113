#include <iostream>
#include <stack>
#include <string>

using namespace std;

/*
Aimar
Ahmad
Anajana
Jessy
*/

class Stack{
    public:
        string name;
        Stack* next = NULL;
};

Stack* push(Stack* head, string name)
{
    Stack* temp = new Stack();
    temp->name = name;
    temp->next = head;
    head = temp;
    return head;
}

Stack* pop(Stack* head)
{
    if(head == NULL)
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }

    Stack* temp = head;
    head = head->next;
    delete temp;
    return head;
}

string peek(Stack* head)
{
    if(head == NULL)
    {
        cout << "Stack is empty" << endl;
        return NULL;
    }

    return head->name;
}

int main() {
    // Stack* node1 = new Stack();
    // Stack* node2 = new Stack();
    // Stack* node3 = new Stack();
    // Stack* node4 = new Stack();
    //
    // node1->name = "Aimar";
    // node1->next = node2;
    //
    // node2->name = "Ahmad";
    // node2->next = node3;

    // node3->name = "Anajana";
    // node3->next = node4;
    //
    // node4->name = "Jessy";

    // Stack* display_node = node1;
    // for(int i = 0; i < 4; i++){
    //     cout << display_node->name << endl;
    //     display_node = display_node->next;
    // }

    Stack* head = NULL;
    head = push(head, "Aimar");
    head = push(head, "Ahmad");
    head = push(head, "Anajana");
    head = push(head, "Jessy");


    head = pop(head);
    Stack* display_node = head;
    while (display_node != NULL)
    {
        cout << display_node->name << endl;
        display_node = display_node->next;
    }


    return 0;
}