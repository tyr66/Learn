#include <iostream>
#include <vector>

using namespace std;

double power(double base ,int exponent)
{
    if (exponent == 0)
        return 1;
    if (exponent == 1)
        return base;

    double value = Power(base, exponent / 2);
    value = exponent % 2 == 0 ? value * value : value * value * base;
    return value;
}

double Power(double base, int exponent)
{
    double value = power(base,abs(exponent));

    return exponent<0?1.0/value:value;
}

int main()
{

    return 0;
}