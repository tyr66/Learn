#include <iostream>
#include <vector>
#include <string>

using namespace std;
/*
    时间复杂度：O(n*2^n)
    字符串s在最坏情况下，分割出一个回文串需要O(2^n)的时间复杂度，最坏情况下有n个回文子串(字符串s中所有的字符都相同)
    空间复杂度：O(n^2)
*/
void generatePartitions(vector<vector<string>>&res, vector<string>&arr, string&s, int i, vector<vector<bool>>&dp)
{
    if (i >= s.size())
    {
        res.push_back(arr);
        return;
    }

    for (int j = i; j < s.size(); j++)
    {
        if (dp[i][j])
        {
            arr.push_back(s.substr(i, j - i + 1));
            generatePartitions(res, arr, s, j + 1, dp);
            arr.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> strs;
    vector<vector<bool>> dp;

    dp.assign(s.size(), vector<bool>(s.size(), true));    
    

    for (int i = s.size() - 1; i>=0;  i--)
    {
        for (int j = i + 1; j < s.size(); j++)
        {
            dp[i][j] = dp[i + 1][j - 1] && s[i] == s[j];
        }
    }
    
    generatePartitions(res, strs, s, 0, dp);

    return res;
}