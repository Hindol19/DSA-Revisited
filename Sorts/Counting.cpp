#include <iostream>
using namespace std;
int maxEle(int ar[], int n)
{
    int max = ar[0];
    for (int i = 1; i < n; i++)
    {
        if (ar[i] > max)
            max = ar[i];
    }
    return max;
}
void Display(int ar[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << ar[i] << " ";
    }
    cout << endl;
}
void Csort(int ar[], int n)
{
    int range = maxEle(ar, n) + 1;
    int freq[range] = {0};
    for (int i = 0; i < n; i++)
    {
        int ind = ar[i];
        freq[ind]++;
    }

    for (int i = 1; i < range; i++)
    {
        freq[i] = freq[i] + freq[i - 1];
    }

    for (int i = range; i >= 1; i--)
    {
        freq[i] = freq[i - 1];
    }

    int res[n];
    for (int i = 0; i < n; i++)
    {
        int ind = ar[i];
        res[freq[ind]] = ar[i];
        freq[ind]++;
    }
    for (int i = 0; i < n; i++)
    {
        ar[i] = res[i];
    }
}

int main()
{
    int ar[] = {2, 1, 8, 6, 5, 6, 2, 1, 9};
    Display(ar, 9);
    Csort(ar, 9);
    Display(ar, 9);
    return 0;
}