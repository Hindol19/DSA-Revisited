#include <iostream>
using namespace std;
void swap(int ar[], int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void Bsort(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (ar[j] > ar[j + 1])
                swap(ar, j, j + 1);
        }
    }
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
    Bsort(ar, 5);
    Display(ar, 5);
    return 0;
}