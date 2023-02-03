#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> vis;
void makePermute(vector<vector<int>> &res, vector<int> &nums, vector<int> &arr, int k)
{
    if (k == 0)
    {
        res.push_back(arr);
        return;
    }

    for (int i = 0; i < nums.size(); i++)
    {
        if ((i - 1 >= 0 && nums[i] == nums[i - 1] && !vis[i - 1]) || vis[i])
            continue;

        arr.push_back(nums[i]);
        vis[i] = 1;
        makePermute(res, nums, arr, k - 1);
        vis[i] = 0;
        arr.pop_back();
    }
}

vector<vector<int>> permuteUnique(vector<int> &nums)
{
    vector<vector<int>> res;
    vector<int> arr;
    sort(nums.begin(), nums.end());
    vis.resize(nums.size(), 0);
    makePermute(res, nums, arr, nums.size());
    return res;
}