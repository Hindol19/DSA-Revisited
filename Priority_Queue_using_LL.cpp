// Write a menu driven program in C or C++ to implement a priority queue using
// single linked list and perform the following operations.
// (a) isEmpty() is to check whether the queue is empty or not.
// (b) insert() is to insert an item in the queue.
// (c) del() is to delete an item from the queue.
// (d) display() is to show the entire queue.

#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    int priority;
    Node *next;
    Node()
    {
        data = 0;
        priority = 0;
        next = NULL;
    }
    Node(int x, int p)
    {
        data = x;
        priority = p;
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
    void Push(int item, int p)
    {
        Node *curr = new Node(item, p);
        cout << curr->data << " " << curr->priority << endl;
        if (head == NULL)
        {
            head = curr;
            return;
        }

        if (p < head->priority)
        {
            curr->next = head;
            head = curr;
            return;
        }
        else
        {
            Node *temp = head;
            while (temp->next != NULL && temp->next->priority < p)
            {
                temp = temp->next;
            }
            curr->next = temp->next;
            temp->next = curr;
        }
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
        Node *temp = head, *temp2;
        while (temp->next != NULL)
        {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
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
    // cout << l.isEmpty() << endl;
    l.Push(4, 4);
    l.Push(1, 1);
    l.Push(2, 2);
    l.Push(10, 10);
    l.Push(3, 3);
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