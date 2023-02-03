#include <iostream>
#include <vector>
using namespace std;

int FindGreatestSumOfSubArray(vector<int> array)
{
    int sum = 0;
    int max_sum = INT_MIN;

    for (int i = 0; i < array.size(); i++)
    {
        sum = sum + array[i] < array[i] ? array[i] : sum + array[i];

        if (sum > max_sum)
            max_sum = sum;
    }

    return max_sum;
}

int main()
{

    return 0;
}