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
void Csort(int ar[], int n, int pow10)
{
    int range = 10;
    int freq[range] = {0};
    for (int i = 0; i < n; i++)
    {
        int ind = (ar[i] / pow10) % 10;
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
    freq[0] = 0;
    int res[n];
    for (int i = 0; i < n; i++)
    {
        int ind = (ar[i] / pow10) % 10;
        res[freq[ind]] = ar[i];
        freq[ind]++;
    }
    for (int i = 0; i < n; i++)
    {
        ar[i] = res[i];
    }
}

void Rsort(int ar[], int n)
{
    int range = maxEle(ar, n);
    int pow10 = 1;
    while (range != 0)
    {
        Csort(ar, n, pow10);
        pow10 = pow10 * 10;
        range = range / 10;
    }
}
int main()
{
    int ar[] = {53, 89, 150, 36, 633, 233};
    Display(ar, 6);
    Rsort(ar, 6);
    Display(ar, 6);
    return 0;
}