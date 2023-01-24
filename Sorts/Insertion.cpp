#include <iostream>
using namespace std;
void swap(int ar[], int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void Isort(int ar[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        while (ar[j] > ar[j + 1] && j >= 0)
        {
            swap(ar, j + 1, j);
            j--;
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
    Isort(ar, 5);
    Display(ar, 5);
    return 0;
}