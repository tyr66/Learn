#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int findMaxLength(vector<int> &nums)
{
    int count = 0;
    int res = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;

    for (int i = 0; i < nums.size(); i++)
    {
        count += nums[i] == 1 ? 1 : -1;

        if (mp.find(count) == mp.end())
        {
            
            mp[count] = i;
        }
        else 
        {
            res = max(res, i - mp[count]);
        }
    }

    return res;
}

int main()
{

    return 0;
}