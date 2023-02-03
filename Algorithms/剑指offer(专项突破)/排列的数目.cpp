#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp;
        dp.resize(target + 1, 0);
        dp[0] = 1;
        
        for (int i = 1; i <= target; i++)
        {
            unsigned long long count = 0;
            for (int j = 0; j < nums.size(); j++)
            {
                if (i - nums[j] >= 0)
                {
                    count += dp[i - nums[j]];
                }
            }
            
            dp[i] = count;
        }
        
        return dp[target];
    }
};