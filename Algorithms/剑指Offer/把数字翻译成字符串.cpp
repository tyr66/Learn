#include <iostream>
#include <string>
#include <vector>
using namespace std;

int solve(string nums)
{

    vector<int> dp;
    dp.resize(nums.size() + 1, 0);
    dp[nums.size()] = 1;

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (i == nums.size() - 1)
        {
            dp[i] = nums[i] == '0'?0:1;
            continue;
        }

        int val = (nums[i] - '0') * 10 + (nums[i + 1] - '0');
        if (val > 26 || val < 10)
        {
            dp[i] = nums[i] == '0'? 0:dp[i + 1];
        }
        else
        {
            dp[i] = dp[i + 1] + dp[i + 2];
        }
    }

    return dp[0];
}

int main()
{

    return 0;
}