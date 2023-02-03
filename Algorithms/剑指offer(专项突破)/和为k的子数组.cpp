#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

//复杂度：时间O(n^2)，空间：O(1)
int subarraySum(vector<int> &nums, int k)
{
    int sum = 0;
    int tmp_sum = 0;
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        tmp_sum = sum;

        for (int j = 0; j <= i; j++)
        {
            if (tmp_sum == k)
                count++;
            tmp_sum -= nums[j];
        }
    }

    return count;
}

int subarraySum2(vector<int> &nums, int k)
{
    unordered_map<int,int>mp;
    int sum = 0;
    int count = 0;
    for(int i = 0;i<nums.size();i++)
    {
        sum+=nums[i];

        if(mp.find(sum - k)!=mp.end())
        {
            count+=mp[sum-k];
        }

        mp[sum]++;
    }

    return count;
}


int main()
{

    return 0;
}