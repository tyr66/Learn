#include <iostream>
#include <vector>
using namespace std;

int maxValue(vector<vector<int>> &grid)
{
    if(grid.size() == 0)
    return 0;

    vector<int> dp;
    int row = grid.size();
    int col = grid[0].size();
    dp.resize(col+1,0);

    for(int i = 1;i<=row;i++)
    {
        for(int j = 1;j<=col;j++)
        {
            dp[j] = grid[i-1][j-1]+max(dp[j],dp[j-1]);
        }
    }

    return dp[col];
}

int main()
{

    return 0;
}