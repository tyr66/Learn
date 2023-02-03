#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 回溯超时
// 原因是存在重复的计算
class Solution_Backtrace {
public:
    
    bool canInterleave(string&s1, string&s2, string&s3, int i, int j, int k, bool iss1)
    {
        if (k == s3.size())
        {
            return true;
        }
        
        bool res = false;
        if (iss1)
        {
            for (; i < s1.size() && !res; i++,k++)
            {
                if (s1[i] != s3[k])
                {
                    break;
                }
                
                res |= canInterleave(s1, s2, s3, i + 1, j, k+1, !iss1);
            }
        } else{
            
            for(; j < s2.size() && !res; j++, k++)
            {
                if (s2[j] != s3[k])
                {
                    break;
                }
                
                res |= canInterleave(s1, s2, s3, i, j+1,k+1, !iss1);
            }
        }
        
        return res;
    }

    bool isInterleave(string s1, string s2, string s3) {

        if (s1.size() + s2.size() != s3.size())
        {
            return false;
        }
        
        return canInterleave(s1, s2, s3, 0, 0, 0, true) || canInterleave(s1, s2, s3, 0, 0, 0, false);
    }
    
};

// 使用动态规划的解法
// 时间复杂度： O(nm), 空间复杂度：O(nm)
// 可以使用滚动数组优化，来将空间复杂度降至O(n)
class Solution_DP
{
  public:
  bool isInterleave(string s1, string s2, string s3)  
  {
    if (s1.size() + s2.size() != s3.size())
        return false;

    vector<vector<bool>> dp;
    dp.resize(s1.size() + 1, vector<bool>(s2.size() + 1, false));
    dp[0][0] = true;
    
    for(int i = 1; i <= s1.size() && s1[i - 1] == s3[i - 1]; i++)
    {
        dp[i][0] = true;
    }
    
    for (int j = 1; j <= s2.size() && s2[j - 1] == s3[j - 1]; j++)
    {
        dp[0][j] = true;
    }
    
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            dp[i][j] = (s1[i - 1] == s3[i + j - 1] && dp[i -1][j]) || (s2[j - 1] == s3[i + j - 1] && dp[i][j - 1]);
        }
    }
    
    return dp[s1.size()][s2.size()];
  }
};