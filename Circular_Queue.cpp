// 4. Write a menu driven program in C or C++ to implement a Circular Queue using
// array and perform the following operations.
// (a) isFull() function to check whether the Circular Queue is full or not.
// (b) isEmpty() function to check whether the Circular Queue is empty or not.
// (c) insert(item) function to insert an element item in the Circular Queue.
// (d) delete() function to read and remove an element from the Circular Queue.
// (e) display() function to display the entire Circular Queue.
#include <iostream>
using namespace std;
#define SIZE 10
class CQueue
{
    int front, rear;
    int ar[SIZE];

public:
    CQueue()
    {
        front = -1;
        rear = -1;
    }
    // [1 , 3 , 5 , 4 , 7 , 6 , 8]
    int isFull()
    {
        if (front == 0 && rear == SIZE - 1)
            return 1;
        else if (front == rear + 1)
            return 1;
        else
            return 0;
    }
    int isEmpty()
    {
        if (front == -1 || rear == -1)
            return 1;
        else
            return 0;
    }
    void insert(int item)
    {
        if (isFull())
        {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (isEmpty())
        {
            front = rear = 0;
            ar[rear] = item;
        }
        else
        {
            rear++;
            if (rear == SIZE)
            {
                rear = 0;
            }
            else
                ar[rear] = item;
        }
    }
    void deleteItem()
    {
        if (isEmpty())
        {
            cout << "Nothing to Delete!!" << endl;
            return;
        }
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        front++;
        if (front == SIZE)
            front = 0;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Nothing to display!" << endl;
            return;
        }

        if (rear < front)
        {
            for (int i = front; i < SIZE; i++)
            {
                cout << ar[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << ar[i] << " ";
            }
        }
        else
        {
            for (int i = front; i <= rear; i++)
            {
                cout << ar[i] << " ";
            }
        }
        cout << endl;
    }
};

int main()
{
    CQueue q;
    q.insert(1);
    q.insert(4);
    q.insert(6);
    q.insert(8);
    q.insert(9);
    q.display();
    q.deleteItem();
    q.display();
    q.deleteItem();
    q.display();
    q.insert(69);
    q.display();
    q.insert(420);
    q.display();
    q.deleteItem();
    q.display();
    return 0;
}