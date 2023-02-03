#include <iostream>
#include <vector>

using namespace std;
// 动态规划，能过但是空间利用率不高
// leetcode 官方题解有效率更高的解决方案
// https://leetcode.cn/problems/YaVDxD/solution/jia-jian-de-mu-biao-zhi-by-leetcode-solu-be5t/
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        vector<vector<int>> dp;
        int max_value = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            max_value += nums[i];
        }
        
        if (target > max_value || target < -max_value)
        return 0;
        
        int mid = max_value;
        dp.resize(nums.size() + 1, vector<int>(2*(max_value + 1) - 1, 0));
        dp[0][0] = 1;
        max_value = 0;
        
        for (int i = 1; i <= nums.size(); i++)
        {
            for (int j = -max_value; j <= max_value; j++)
            {
                dp[i][j + nums[i - 1] + mid] += dp[i - 1][j + mid];
                dp[i][j - nums[i - 1] + mid] += dp[i - 1][j + mid];
            }

            max_value += nums[i - 1];
        }
        
        return dp[nums.size()][target + mid];
    }
};