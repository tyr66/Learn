#include <iostream>
#include <vector>

using namespace std;
// 思路：动态规划，从顶部开始转移，也可从底部开始转移更优
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        if (triangle.empty())
            return 0;
        
        int m = triangle.size();     
        vector<int> dp;
        dp.resize(triangle[m - 1].size() + 1, INT_MAX);
        dp[1] = triangle[0][0];
        
        for (int i = 2; i<=m; i++)
        {
            int memory = INT_MAX;
            int tmp = INT_MAX;
            for (int j = 1; j <= i; j++)
            {
                tmp = dp[j];
                dp[j] = triangle[i - 1][j - 1] + min(dp[j], memory);
                memory = tmp;
            }
        }
        
        int res = INT_MAX;

        for (int j = 1; j <= m; j++)
        {
            res = min(res, dp[j]);
        }
        
        return res;
    }
};