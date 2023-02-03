#include <iostream>
#include <vector>
using namespace std;

int MoreThanHalfNum_Solution(vector<int> numbers)
{
    if (numbers.empty())
        return INT_MIN;

    int count = 1;
    int res = numbers[0];

    for (int i = 1; i < numbers.size(); i++)
    {
        if (res != numbers[i])
            count--;
        else
            count++;

        if (count == 0)
        {
            res = numbers[i];
            count = 1;
        }
    }

    return res;
}

int main()
{
}