// Write a menu driven program in C or C++ to implement a stack using single
// linked list and perform the following operations.
// (a) isEmpty() is to check whether the stack is empty or not.
// (b) push() is to insert an item in the stack.
// (c) pop() is to delete an item from the stack.
// (d) display() is to show the entire stack.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

class LL
{
public:
    Node *head;
    LL()
    {
        head = NULL;
    }
    int isEmpty()
    {
        if (head == NULL)
            return 1;
        return 0;
    }
    void Push(int item)
    {
        Node *curr = new Node(item);
        if (head == NULL)
        {
            head = curr;
            return;
        }
        curr->next = head;
        head = curr;
    }
    void Pop()
    {
        if (head == NULL)
        {
            return;
        }
        if (head->next == NULL)
        {
            head = NULL;
            return;
        }
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        free(temp);
    }

    void display()
    {
        if (head == NULL)
        {
            cout << "Nothing to show!" << endl;
            return;
        }
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    LL l;
    cout << l.isEmpty() << endl;
    l.Push(2);
    l.Push(5);
    l.Push(6);
    l.Push(7);
    l.display();
    l.Pop();
    l.display();
    l.Pop();
    l.display();
    l.Pop();
    l.display();
    l.Pop();
    l.display();
    l.Pop();
    l.display();
    // cout << l.isEmpty() << endl;
    return 0;
}