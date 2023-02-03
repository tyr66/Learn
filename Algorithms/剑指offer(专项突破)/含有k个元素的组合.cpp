#include <iostream>
#include <vector>
/*
    迭代思路：https://leetcode.cn/problems/uUsW3B/solution/han-you-k-ge-yuan-su-de-zu-he-by-leetcod-tyqe/
*/
using namespace std;

void makeCombine(int i, int n, int k, vector<int>&arr, vector<vector<int>>&res)
{
    if (k == 0)
    {
        res.push_back(arr);
        return;
    }

    for (int j = i; j <= n; j++)
    {
        arr.push_back(j);
        makeCombine(j + 1, n, k - 1, arr, res);
        arr.pop_back();
    }
}

vector<vector<int>> combine(int n, int k)
{

    vector<vector<int>> res;
    vector<int> arr;

    makeCombine(1, n, k, arr, res);

    return res;
}