#include <iostream>
#include <vector>
/*
    存在迭代时的解决方案
    https://leetcode.cn/problems/TVdhkn/solution/suo-you-zi-ji-by-leetcode-solution-my7d/
*/
using namespace std;

void getSubsets(vector<int>& nums, int i, vector<int>&arr, vector<vector<int>>&res)
{
    if (i >= nums.size())
    {
        res.push_back(arr);
        return;
    }

    getSubsets(nums, i + 1, arr, res);

    arr.push_back(nums[i]);
    getSubsets(nums, i + 1, arr, res);
    arr.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {

    vector<int> arr;
    vector<vector<int>> res;

    getSubsets(nums, 0, arr, res);


    return res;
}