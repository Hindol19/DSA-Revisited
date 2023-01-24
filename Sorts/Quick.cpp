#include <iostream>
using namespace std;
void swap(int ar[], int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void Qsort(int ar[], int low, int high)
{
    if (low >= high)
    {
        return;
    }
    int start = low;
    int end = high;
    int piv = start + (end - start) / 2;
    while (start <= end)
    {
        while (ar[start] < ar[piv])
        {
            start++;
        }
        while (ar[end] > ar[piv])
        {
            end--;
        }
        if (start <= end)
        {
            // Violation:
            // Swap start and low
            swap(ar, start, end);
            start++;
            end--;
        }
    }
    Qsort(ar, low, end);
    Qsort(ar, start, high);
}
void Display(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
int main()
{
    int ar[] = {2, 1, 8, 6, 5};
    Qsort(ar, 0, 4);
    Display(ar, 5);
    return 0;
}