// Write a menu driven program in C or C++ to perform the following operations on
// circular linked list.
// Page 2
// (a) insert a node at the beginning of the list.
// (b) insert a node at the end of the list.
// (c) delete a node from the beginning of the list.
// (d) delete a node at the end of the list.
// (e) display the whole list.
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

class CLL
{
    Node *last;

public:
    CLL()
    {
        last = NULL;
    }
    void insertBeg(int x)
    {
        Node *curr = new Node(x);
        if (last == NULL)
        {
            last = curr;
            curr->next = last;
            return;
        }
        curr->next = last->next;
        last->next = curr;
    }
    void insertEnd(int x)
    {
        Node *curr = new Node(x);
        if (last == NULL)
        {
            last = curr;
            curr->next = last;
            return;
        }
        curr->next = last->next;
        last->next = curr;
        last = last->next;
    }
    void deleteBeg()
    {
        if (last == NULL)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (last->next == last)
        {
            last = NULL;
            return;
        }
        Node *temp = last->next;
        last->next = temp->next;
        free(temp);
    }
    void deleteEnd()
    {
        if (last == NULL)
        {
            cout << "Nothing to delete" << endl;
            return;
        }
        if (last->next == last)
        {
            last = NULL;
            return;
        }
        Node *temp = last->next;
        Node *prev = last;
        while (temp->next != last)
        {
            prev = temp;
            temp = temp->next;
        }

        // Update the next pointer of the second last node
        prev->next = last;

        // Delete the last node
        delete temp;
    }
    void disp()
    {
        if (last == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = last->next;
        while (temp != last)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << temp->data << " ";
        cout << endl;
    }
    
};

int main()
{
    CLL list;
    list.insertBeg(2);
    list.disp();
    list.insertBeg(4);
    list.disp();
    list.insertBeg(5);
    list.disp();
    list.insertBeg(6);
    list.disp();
    list.insertEnd(69);
    list.disp();
    list.insertEnd(420);
    list.disp();
    list.deleteEnd();
    list.disp();
    list.deleteEnd();
    list.disp();
    list.deleteEnd();
    list.disp();
    list.deleteEnd();
    list.disp();
    list.deleteEnd();
    list.disp();
    list.deleteEnd();
    list.disp();
    return 0;
}