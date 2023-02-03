#include <iostream>
using namespace std;

int divide(int a, int b)
{
    long long res = 0;
    long long count = 1;
    long long divisor = llabs(b);
    long long dividend = llabs(a);

    while (true)
    {
        if (dividend < llabs(b))
            break;
        if (dividend == llabs(b))
        {
            res += count;
            break;
        }

        divisor = divisor << 1;

        if (divisor >= dividend)
        {
            res += count;
            dividend = dividend - (divisor >> 1);
            divisor = llabs(b);
            count = 1;
            continue;
        }

        count = count << 1;
    }

    if (a>0&&b<0||a<0&&b>0)
        res = -res;

    if (res > INT_MAX)
        res = INT_MAX;

    return res;
}

int main()
{
    cout << divide(17, 2);
    return 0;
}