#include <iostream>
#include <vector>
using namespace std;

int pivotIndex(vector<int> &nums)
{
    int sum = 0;
    int totalSum = 0;

    for(int i =0;i<nums.size();i++)
        totalSum+=nums[i];

    for(int i = 0;i<nums.size();i++)
    {
        if(sum == (totalSum - sum-nums[i]))
        {
            return i;
        }

        sum+=nums[i];
    }

    return -1;
}

int main()
{

    return 0;
}