#include <iostream>
#include <vector>
using namespace std;

/*
解法：
1.Brian Kernighan 算法 时间复杂度O(nlogn)

2.动态规划——最高有效位-------
                           |
3.动态规划——最低有效位       - 时间复杂度O(n)
                           |
4.动态规划——最低设置位-------
*/

vector<int> countBits(int n)
{
    vector<int> res;
    res.push_back(0);

    for(int i =1;i<=n;i++)
    {
        res.push_back(res[i&(i-1)]+1);
    }

    return res;
}

int main()
{

    return 0;
    ;
}