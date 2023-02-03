#include <iostream>
#include <vector>
using namespace std;

int LastRemaining_Solution(int n, int m)
{
    if (n == 1)
        return 0;

    int idx = 0;

    if (n > m)
        idx = m - 1;
    else
    {
        idx = m % n == 0 ? n - 1 : m % n - 1;
    }

    int res = LastRemaining_Solution(n - 1, m);

    return res >= idx ? res + 1 : res;
}

int main()
{

    return 0;
}