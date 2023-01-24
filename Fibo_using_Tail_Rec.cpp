#include <iostream>
using namespace std;

int fibo(int n, int a, int b)
{
    if (n == 0)
        return a;
    if (n == 1)
        return b;
    return fibo(n - 1, b, a + b);
}

int main()
{
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        cout << fibo(i, 0, 1) << " ";
    }
    return 0;
}