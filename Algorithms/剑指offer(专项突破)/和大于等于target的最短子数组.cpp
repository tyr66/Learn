#include <iostream>
#include <vector>
using namespace std;

int minSubArrayLen(int target, vector<int> &nums)
{
    int left = 0, right = 0;
    int res = INT_MAX;
    int sum = 0;

    while (right < nums.size())
    {
        sum += nums[right];

        if (sum >= target)
        {
            while (left <= right && sum >= target)
            {
                res = min(res, right - left + 1);
                sum -= nums[left++];
            }
        }

        right++;
    }
    return res == INT_MAX ? 0 : res;
}