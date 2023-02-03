#include <iostream>
#include <vector>
using namespace std;

int dp[61];

int cutRope(int number)
{
    dp[1] = 1;
    dp[2] = 1;

    for(int n = 3;n<=number;n++)
    {
        for(int i = 1;i<=n/2;i++)
        {
            dp[n] = max(dp[n],dp[i]*dp[n-i]);
            dp[n] = max(dp[n],dp[n-i]*i);
            dp[n] = max(dp[n],dp[i]*(n-i));
            dp[n] = max(dp[n],i*(n-i));
        }
    }

    return dp[number];
}