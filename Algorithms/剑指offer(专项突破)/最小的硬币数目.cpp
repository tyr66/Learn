#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// 使用动态规划，贪心在这里是行不通的例如 [1,5,8] , 10 。按照贪心来的话结果为3 ，但实际答案为2
// 该问题实际上是一个背包问题，并且是一个完全背包问题
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        if (amount == 0 || coins.empty())
            return 0;
        vector<vector<int>> dp;
        dp.resize(coins.size(), vector<int>(amount + 1, -1));
        
        for (int k = 0; k*coins[0] <= amount; k++)
        {
            dp[0][k * coins[0]] = k;
        }

        for (int i = 1; i < coins.size(); i++)
        {
            for(int j = 0; j <= amount; j++)
            {
                if (dp[i - 1][j] >= 0)
                    dp[i][j] = min(dp[i][j], dp[i - 1][j]);

                if (j - coins[i] >= 0&&dp[i][j - coins[i]] >= 0)
                    dp[i][j] = min(dp[i][j], dp[i][j - coins[i]] + 1);
            }
        }
        
        return dp[coins.size() - 1][amount];
    }
};