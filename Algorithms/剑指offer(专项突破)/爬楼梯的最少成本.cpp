#include <iostream>
#include <vector>

using namespace std;

int minCostClimbingStairs(vector<int> &cost)
{
    vector<int> dp;
    dp.resize(cost.size() + 1, 0);

    for (int i = 2; i < dp.size(); i++)
    {
        dp[i] = min(dp[i - 2] + cost[i - 2],dp[i - 1] + cost[i - 1]);
    }

    return dp[cost.size()];
}