#include <iostream>
#include <vector>
#include <string>
using namespace std;

int minCut(string s)
{
    vector<vector<bool>> isPalindrome;
    vector<int> dp;

    int n = s.size();
    isPalindrome.resize(n, vector<bool>(n, true));

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 1; j < n; j++)
        {
            isPalindrome[i][j] = isPalindrome[i + 1][j - 1] && (s[i] == s[j]);
        }
    }
    
    dp.resize(n, INT_MAX);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >=0; j--)
        {
            if (isPalindrome[j][i])
            {
                dp[i] = min(dp[i], j == 0? 1 : dp[j - 1] + 1);
            }
        }
    }
    
    return dp[n - 1];
}