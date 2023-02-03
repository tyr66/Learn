#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void makeCombination(vector<int> &candidates, vector<int> &arr, vector<vector<int>> &res, int i, int target)
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

    int j = i;
    while (j + 1 < candidates.size() && candidates[j] == candidates[j + 1]) 
    {
        j++;
    }
    
    makeCombination(candidates, arr, res, j + 1, target);

    arr.push_back(candidates[i]);
    makeCombination(candidates, arr, res, i + 1, target - candidates[i]);
    arr.pop_back();
}

vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
{
    vector<vector<int>> res;
    vector<int> arr;
    sort(candidates.begin(), candidates.end());

    makeCombination(candidates, arr, res, 0, target);
    return res;
}