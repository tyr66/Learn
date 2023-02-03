#include <iostream>
#include <vector>
using namespace std;

/*
按位统计https://blog.csdn.net/qq_35523678/article/details/102902860
时间复杂度 O(log{10}{n})
*/

int NumberOf1Between1AndN_Solution(int n)
{
    int res = 0;
    for(long long i = 1;i<=n;i*=10)
    {
        long long mark = i*10;
        res+=n/mark*i + min(max((n%mark) - i+1,(long long)0),i);
    }

    return res;
}

int main()
{
    return 0;
}