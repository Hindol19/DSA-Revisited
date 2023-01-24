// 1. Write a menu driven program to perform the following operations on an array.
// (a) update an element x at position k in the array.
// (b) insert an element x at position k in the array.
// (c) search an element x from the array.
// (d) remove an element x from the array.
// (e) display an element x from the array.

#include <iostream>
#include <array>
using namespace std;

void update(int ar[], int x, int k, int len)
{
    if (k >= len || k < 0)
        cout << "Index not present!" << endl;
    else
        ar[k] = x;
}
// [1 , 3 , 5 , 4 , 7 , 6 , 8]
int insert(int ar[], int x, int k, int len)
{
    if (k > len || k < 0)
    {
        cout << "Index not present!" << endl;
        return len;
    }
    else
    {
        for (int i = len; i >= k; i--)
        {
            ar[i] = ar[i - 1];
        }
        ar[k] = x;
        return len + 1;
    }
}
int search(int ar[], int x, int len)
{
    // Lets Apply Linear Search
    for (int i = 0; i < len; i++)
    {
        if (ar[i] == x)
            return i;
    }
    return -999;
}
int remove(int ar[], int x, int len)
{
    if (search(ar, x, len) == -999)
    {
        cout << "Element not found!" << endl;
        return len;
    }
    int ind = search(ar, x, len);
    for (int i = ind; i < len - 1; i++)
    {
        ar[i] = ar[i + 1];
    }
    return len - 1;
}

void display(int ar[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int ar[50] = {2, 5, 4, 7, 3};
    int len = 5;
    display(ar, len);
    update(ar, 69, 3, len);
    display(ar, len);
    len = insert(ar, 290, 3, len);
    display(ar, len);
    len = remove(ar, 290, len);
    display(ar, len);

    return 0;
}
