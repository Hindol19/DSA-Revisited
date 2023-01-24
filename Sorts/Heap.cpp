#include <iostream>
using namespace std;
void swap(int ar[], int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void heapify(int ar[], int i, int n)
{
    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    if (left <= n && ar[left] > ar[largest])
        largest = left;
    if (right <= n && ar[right] > ar[largest])
        largest = right;

    if (largest != i)
    {
        swap(ar, i, largest);
        heapify(ar, largest, n);
    }
}
void buildHeap(int ar[], int n)
{
    for (int i = n / 2; i >= 1; i--)
    {
        heapify(ar, i, n);
    }
}
void Hsort(int ar[], int n)
{
    buildHeap(ar, n);
    for (int i = n; i >= 2; i--)
    {
        swap(ar, i, 1);
        heapify(ar, 1, i - 1);
    }
}
void Display(int ar[], int n)
{
    for (int i = 1; i <= n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int ar[] = {0, 2, 1, 8, 6, 5};
    Hsort(ar, 6);
    Display(ar, 5);
    return 0;
}