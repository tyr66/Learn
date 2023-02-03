#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makePermution(vector<vector<int>>&res,  vector<int>&nums, int i)
{
    if (i >= nums.size())
    {
        res.push_back(nums);
        return;
    }
    
    for( int j = i; j < nums.size(); j++)
    {
        swap(nums[j], nums[i]);
        makePermution(res, nums, i + 1);
        swap(nums[j], nums[i]);
    }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> res;
    makePermution(res, nums,0);
    return res;
}