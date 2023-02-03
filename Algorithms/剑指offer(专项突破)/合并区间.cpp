#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(vector<int>&left, vector<int>&right)
{
    if (left[0] != right[0])
     return left[0] < right[0];

    return left[1] < right[1];
}
vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    vector<vector<int>> res;
    sort(intervals.begin(), intervals.end(), compare );

    for (auto&interval : intervals)
    {
        if (res.empty())
        {
            res.push_back(interval);
            continue;
        }
        auto& top = *(res.end() - 1);
    
        if (top[1] >= interval[0])
        {
            top[1] = max(top[1], interval[1]);
        } else {
            res.push_back(interval);
        }
    }
    return res;
}