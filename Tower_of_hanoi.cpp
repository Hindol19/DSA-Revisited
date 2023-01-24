// 8. Write a program to implement Tower of Hanoi Problem

#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 0)
        return;
    towerOfHanoi(n - 1, from, aux, to);
    cout << "Move disk " << n << " from rod " << from << " to rod " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main()
{
    int N = 3;

    // A, B and C are names of rods
    towerOfHanoi(N, 'A', 'C', 'B');
    return 0;
}
