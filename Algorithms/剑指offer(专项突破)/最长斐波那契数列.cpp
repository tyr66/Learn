#include <vector>
#include <iostream>
#include <unordered_map>
/*
    不使用哈希表进行优化的时间复杂度：O(n^3)
    使用哈希表进行优化的时间复杂度：O(n^2)
*/
using namespace std;
// 时间复杂度O(n^3)
// 空间复杂度O(n^2)
// 超时
int lenLongestFibSubseq_OutofTime(vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }

    vector<vector<int>> dp;
    int ans = 0;
    int n = arr.size();
    dp.resize(n, vector<int>(n, 0));

    for (int i = 2; i < arr.size(); i++)
    {
        for(int j = i - 1; j >= 0; j--)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                if ((arr[k] + arr[j]) == arr[i])
                {
                    dp[i][j] = max(dp[i][j], max(3, dp[j][k] + 1));
                }
            }
            
            ans = max(ans, dp[i][j]);
        }
    }

    return ans;
}

// 使用哈希表进行优化
// 时间复杂度：O(n^2)
// 空间复杂度: O(n^2)
int lenLongestFibSubseq(vector<int> &arr)
{
    if (arr.empty())
    {
        return 0;
    }

    // 哈希表中保存的是索引而不是长度
    // 否则无法处理输入为[.......,22,....,44,......]的情况
    unordered_map<int,int> ump;
    vector<vector<int>> dp;
    int ans = 0;
    int n = arr.size();
    dp.resize(n, vector<int>(n, 0));
    
    for (int i = 0; i < n; i++)
    {
        ump[arr[i]] = i;
    }

    for (int i = 0; i<n; i++)
    {

        for (int j = i - 1; j >=0 && arr[j]*2 > arr[i] ; j--)
        {
            int remain = arr[i] - arr[j];
            int k = -1;

            if (ump.count(remain))
            {
                k = ump[remain];
            }
            
            if (k >= 0)
            {
                dp[j][i] = max(dp[j][i], max(3, dp[k][j] + 1));
                ans = max(dp[j][i], ans);
            }
        }
    }
    return ans;
}