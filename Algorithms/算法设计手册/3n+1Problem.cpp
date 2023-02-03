#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, int> dp;

int get_max_length(int n)
{
    if (n & 1)
        n = 3*n + 1;
    else 
        n = n >> 1;
    
    if (dp.count(n))
        return dp[n] + 1;
    
    dp[n] = get_max_length(n);
    return dp[n] + 1; 
}

int main()
{
    int n,m;
    dp[1] = 1;
    while (cin>>n>>m)
    {
        int max_length = -100;
        for (int i = n; i<=m; i++)
        {
            if (dp.count(i))
                max_length = max(max_length, dp[i]);
            else 
                max_length = max(max_length, get_max_length(i));


            max_length = max(max_length, dp[i]);
        }

        printf("%d %d %d\n", n, m, max_length);
    }
}