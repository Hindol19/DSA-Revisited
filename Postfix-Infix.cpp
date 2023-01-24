// 5. Assume that there are only five operators (∗, /, +, −,^) in an expression and operand
// is single digit only. Write a C/C++ Program
// (a) To Convert Infix to Postfix Expression using Stack.
// (b) To evaluate a given postfix expression.

#include <iostream>
#include <math.h>
#include <string>
using namespace std;
#define SIZE 100
class Stack
{
    char ar[SIZE];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if (top == SIZE - 1)
            return 1;
        return 0;
    }
    void push(char x)
    {
        if (isFull())
        {
            return;
        }
        top++;
        ar[top] = x;
    }
    void pop()
    {
        if (isEmpty())
            return;
        top--;
    }
    char peek()
    {
        if (isEmpty())
            return '\0';
        return ar[top];
    }
    void display()
    {
        if (isEmpty())
            return;
        for (int i = 0; i <= top; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

class StackInt
{
    int ar[SIZE];
    int top;

public:
    StackInt()
    {
        top = -1;
    }
    int isEmpty()
    {
        if (top == -1)
            return 1;
        return 0;
    }
    int isFull()
    {
        if (top == SIZE - 1)
            return 1;
        return 0;
    }
    void push(int x)
    {
        if (isFull())
        {
            return;
        }
        top++;
        ar[top] = x;
    }
    void pop()
    {
        if (isEmpty())
            return;
        top--;
    }
    int peek()
    {
        if (isEmpty())
            return '\0';
        return ar[top];
    }
    void display()
    {
        if (isEmpty())
            return;
        for (int i = 0; i <= top; i++)
        {
            cout << ar[i] << " ";
        }
        cout << endl;
    }
};

class infixToPostfix
{
public:
    int priority(char c)
    {
        if (c == '+' || c == '-')
            return 1;
        if (c == '*' || c == '/')
            return 2;
        if (c == '^')
            return 3;
        return 0;
    }
    string Convert(string s)
    {
        Stack op;
        string alp = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (isalpha(s[i]))
            {
                alp = alp + s[i];
            }
            else
            {
                if (op.isEmpty() == 1 || op.peek() == '(' || s[i] == '(')
                {
                    op.push(s[i]);
                }
                else if (s[i] == ')')
                {
                    while (op.peek() != '(')
                    {
                        alp = alp + op.peek();
                        op.pop();
                    }
                    op.pop();
                }
                else if (priority(s[i]) <= priority(op.peek()))
                {
                    while (priority(s[i]) <= priority(op.peek()))
                    {
                        alp = alp + op.peek();
                        op.pop();
                    }
                    op.push(s[i]);
                }
                else
                    op.push(s[i]);
            }
        }
        while (!op.isEmpty())
        {
            alp = alp + op.peek();
            op.pop();
        }
        return alp;
    }
};

class evaluatePostfix
{
public:
    int Evaluate(string s)
    {
        StackInt st;
        float res = 0.0;
        for (int i = 0; i < s.length(); i++)
        {
            if (isdigit(s[i]))
            {
                st.push(int(s[i] - '0'));
            }
            else
            {
                int a = st.peek();
                st.pop();
                int b = st.peek();
                st.pop();
                int res;
                if (s[i] == '+')
                    res = b + a;
                else if (s[i] == '-')
                    res = b - a;
                else if (s[i] == '/')
                    res = b / a;
                else if (s[i] == '*')
                    res = b * a;
                else if (s[i] == '^')
                    res = pow(b, a);
                st.push(res);
            }
        }
        return (st.peek());
    }
};

int main()
{
    string s = "(a+b)*c+(d-e)/f+g";
    string s1 = "92+63/-";
    infixToPostfix in;
    evaluatePostfix e;
    cout << in.Convert(s) << endl;
    cout << e.Evaluate(s1) << endl;

    return 0;
}