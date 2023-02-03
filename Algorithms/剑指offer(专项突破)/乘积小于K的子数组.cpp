#include <iostream>
#include <vector>
using namespace std;
/*
解法1：O(n^2)
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int lo = 0;
    int mul = 1;
    int hi = 0;
    int count = 0;

    while (lo < nums.size())
    {
        mul = 1;
        hi = lo;
        while (hi < nums.size())
        {
            mul *= nums[hi];

            if (mul >= k)
                break;

            hi++;
        }

        count += hi - lo;
        cout << hi - lo << endl;

        lo++;
    }

    return count;
}
 */

//时间复杂度O(n)
int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    int lo = 0;
    int mul = 1;
    int hi = 0;
    int count = 0;

    while (hi < nums.size())
    {
        mul *= nums[hi];

        while (lo <= hi && mul >= k)
        {
            mul /= nums[lo];
            lo++;
        }

        count += hi - lo + 1;
        hi++;
    }

    return count;
}

int main()
{
    return 0;
}