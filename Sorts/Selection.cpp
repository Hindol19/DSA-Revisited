#include <iostream>
using namespace std;
void swap(int ar[], int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;
}
void Ssort(int ar[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (ar[j] < ar[min])
                min = j;
        }
        swap(ar, i, min);
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
    Ssort(ar, 5);
    Display(ar, 5);
    return 0;
}