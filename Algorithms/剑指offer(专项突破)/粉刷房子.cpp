#include <iostream>
#include <vector>

using namespace std;

int minCost(vector<vector<int>> &costs)
{
    if (costs.empty())
    {
        return 0;
    }

    int n = costs.size();
    int m= costs[0].size();

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int min_value = INT_MAX;
            for (int k = 0; k < m; k++)
            {
                if (k != j)
                {
                    min_value = min(costs[i - 1][k], min_value);
                }
            }
            costs[i][j] = min_value + costs[i][j];
        }
    }

    int res = INT_MAX;

    for (int j = 0; j<m; j++)
    {
        res = min(costs[n-1][j], res);
    }
    
    return res;
}