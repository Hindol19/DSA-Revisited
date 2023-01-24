#include <iostream>
using namespace std;

int fac(int n, int a)
{
    if (n == 0)
        return a;
    return fac(n - 1, a * n);
}

int main()
{
    int n = 4;
    cout << fac(n, 1) << endl;
    return 0;
}