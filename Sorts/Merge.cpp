#include <iostream>
using namespace std;
void Merge(int ar[], int start, int mid, int end)
{
    int M[end - start + 1];
    int i1 = start;
    int i2 = mid + 1;
    int i, j, t = 0;
    while (i1 <= mid && i2 <= end)
    {
        if (ar[i1] <= ar[i2])
        {
            M[t] = ar[i1];
            t++;
            i1++;
        }
        else
        {
            M[t] = ar[i2];
            t++;
            i2++;
        }
    }
    while (i1 <= mid)
    {
        M[t] = ar[i1];
        t++;
        i1++;
    }
    while (i2 <= end)
    {
        M[t] = ar[i2];
        t++;
        i2++;
    }
    for (i = 0, j = start; i < end - start + 1; i++, j++)
    {
        ar[j] = M[i];
    }
}
void Msort(int ar[], int start, int end)
{
    if (start >= end)
        return;
    int mid = start + (end - start) / 2;
    Msort(ar, start, mid);
    Msort(ar, mid + 1, end);
    Merge(ar, start, mid, end);
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
    Msort(ar, 0, 4);
    Display(ar, 5);
    return 0;
}