#include <iostream>
#include <vector>
/*
状态转移方程
dp[i][0] = dp[i−1][0]+I(s[i]=‘1’)
dp[i][1] ​= min(dp[i−1][0],dp[i−1][1])+I(s[i]=‘0’)

下面的解法并没有按照上面状态转移方程，但最好按照上面的状态转移方程来实现
*/
using namespace std;

int minFlipsMonoIncr(string s)
{
    int prev_zero = 0;
    int prev_one = 0;
    int prev_incr = 0;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '0')
        {
            prev_incr = min(min(prev_incr + 1, prev_zero + 1), prev_one + 1);
            prev_one = prev_one + 1;
        }
        else
        {
            prev_incr = min(min(prev_incr, prev_zero), prev_one);
            prev_zero = prev_zero + 1;
        }
        
    }

    return min(min(prev_zero, prev_one), prev_incr);
}