#include <iostream>
#include <vector>

using namespace std;

// 使用动态规划的背包思想：dp[i][j] 表示 nums 数组从0~i-1,的数组种是否存在和为j的子数列
// 状态转移方程为：
// dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]] , 当 j >= nums[i - 1]
// dp[i][j] = dp[i - 1][j]                               , 当 j < nums[i - 1]
// dp的初始状态为： dp[0][0] = true
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {

        int maxNum = INT_MIN;
        int target = 0;
        vector<vector<bool>> dp;
        for (int i = 0; i < nums.size(); i++)
        {
            target += nums[i];
            maxNum = max(maxNum, nums[i]);
        }

        if (target & 1)
        {
            return false;
        }
        target = target >> 1;

        if (maxNum > target)
        {
            return false;
        }

        dp.resize(nums.size() + 1, vector<bool>(target + 1, false));
        dp[0][0] = true;

        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = 0; j <= target; j++)
            {
                if (nums[i - 1] <= j)
                {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        return dp[nums.size()][target];
    }
};