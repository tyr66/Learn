#include <iostream>
#include <vector>

using namespace std;

//思路：动态规划或者是组合数学
// 组合数学的思想：从左上角到右下角的过程中，我们需要移动 m+n-2m+n−2 次，其中有 m-1m−1 次向下移动，n-1n−1 次向右移动。因此路径的总数，就等于从 m+n-2m+n−2 次移动中选择 m-1m−1 次向下移动的方案数
class Solution {
public:
    int uniquePaths(int m, int n) {
        
        if (m <= 0 || n <= 0)       
            return 0;

        vector<int> dp;
        dp.resize(n + 1, 1);
        dp[0] = 0;
        
        for (int i = 2; i<=m; i++)
        {
            for (int j = 1; j<=n;j ++)
            {
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        
        return dp[n];
        
    }
};