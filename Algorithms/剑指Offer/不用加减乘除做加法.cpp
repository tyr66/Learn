#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
    int sum = 0;
    int carry;

    do
    {
        sum = num1^num2;
        carry = (num1&num2)<<1;
        num1 = sum;
        num2 = carry;

    } while (carry!=0);
    
    return sum;
}
