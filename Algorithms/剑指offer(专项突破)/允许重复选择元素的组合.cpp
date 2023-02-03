#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void combinate(vector<int>& candidates, vector<int>& arr, vector<vector<int>>& res, int i, int target)
{
    if (target == 0)
    {
        res.push_back(arr);
        return;
    }

    if (i >= candidates.size() || target < candidates[i])
    {
        return;
    }

    int n = 0;
    while (target - candidates[i] >= 0)
    {
        arr.push_back(candidates[i]);
        target -= candidates[i];
        n++;
    }

    for (int j = n; j > 0; j--)
    {
        combinate(candidates, arr, res, i + 1, target);
        target += candidates[i];
        arr.pop_back();
    }

    combinate(candidates, arr, res, i + 1, target);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> res;
    vector<int> arr;
    sort(candidates.begin(), candidates.end());
    combinate(candidates, arr, res, 0, target);
    return res;
}