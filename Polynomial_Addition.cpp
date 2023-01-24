#include <iostream>
using namespace std;
class Node
{
public:
    int coef;
    int exp;
    Node *next;
    Node()
    {
        coef = 0;
        next = NULL;
    }
    Node(int c, int e)
    {
        coef = c;
        exp = e;
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
    void insertBeg(int c, int e)
    {
        Node *curr = new Node(c, e);
        if (head == NULL)
        {
            head = curr;
            return;
        }
        curr->next = head;
        head = curr;
    }
    void disp()
    {
        if (head == NULL)
        {
            cout << 0 << endl;
            return;
        }
        if (head->exp == 0)
            cout << head->coef;
        else
        {
            cout << head->coef << "x^" << head->exp;
        }
        if (head->next == NULL)
            return;
        Node *temp = head->next;
        while (temp != NULL)
        {
            if (temp->exp == 0)
            {
                if (temp->coef > 0)
                    cout << " + " << temp->coef;
                else
                    cout << " - " << (-1) * temp->coef;
            }

            else
            {
                if (temp->coef > 0)
                    cout << " + " << temp->coef << "x^" << temp->exp;
                else
                    cout << " - " << (-1) * temp->coef << "x^" << temp->exp;
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
LL addPoly(LL p1, LL p2)
{
    LL p3;
    Node *p1head = p1.head;
    Node *p2head = p2.head;
    while (p1head != NULL && p2head != NULL)
    {
        if (p1head->exp > p2head->exp)
        {
            p3.insertBeg(p1head->coef, p1head->exp);
            p1head = p1head->next;
        }
        else if (p2head->exp > p1head->exp)
        {
            p3.insertBeg(p2head->coef, p2head->exp);
            p2head = p2head->next;
        }
        else
        {
            p3.insertBeg(p1head->coef + p2head->coef, p1head->exp);
            p1head = p1head->next;
            p2head = p2head->next;
        }
    }
    return p3;
}

int main()
{
    LL p1;
    p1.insertBeg(3, 4);
    p1.insertBeg(6, 3);
    p1.insertBeg(8, 2);
    p1.insertBeg(1, 1);
    p1.insertBeg(69, 0);
    p1.disp();

    LL p2;
    p2.insertBeg(5, 5);
    p2.insertBeg(2, 4);
    p2.insertBeg(-7, 3);
    p2.insertBeg(3, 2);
    p2.insertBeg(9, 1);
    p2.insertBeg(45, 0);
    p2.disp();

    LL p3 = addPoly(p1, p2);
    p3.disp();
    return 0;
}