#include <iostream>
#include <vector>
using namespace std;

int Fibonacci(int n)
{
    if (n <= 2)
        return 1;

    int prev = 1, pprev = 1;
    int res = 0;
    for (int i = 3; i <= n; i++)
    {
        res = prev + pprev;
        pprev = prev;
        prev = res;
    }

    return res;
}

int main()
{

    return 0;
}