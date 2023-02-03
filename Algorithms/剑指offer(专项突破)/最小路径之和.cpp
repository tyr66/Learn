#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {

        if (grid.empty())
            return 0;

        int m = grid.size();
        int n = grid[0].size();
        vector<int> dp;
        dp.resize(grid[0].size() + 1, 0);
        for (int j = 1; j <= n; j++)
        {
            dp[j] = grid[0][j - 1] + dp[j - 1];
        }

        dp[0] = INT_MAX;

        for (int i = 2; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[j] = grid[i - 1][j - 1] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n];
    }
};