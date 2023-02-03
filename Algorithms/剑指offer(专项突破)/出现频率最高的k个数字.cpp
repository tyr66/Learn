#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

/*
思路： 哈希 + 堆 或者 哈希 + 快速排序的切分
    堆加哈希表 时间复杂度 ：O(nlogk)
    堆 + 快速排序切分 时间复杂度：O(n)
*/

// 

 vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> res;
    unordered_map<int, int> ump;
    auto compare = [](pair<int, int>& a, pair<int, int>&b){return a.second > b.second;};
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);

    for (auto it : nums)
    {
        ump[it]++;
    }

    for (auto &it : ump)
    {
        if (pq.size() < k)
        {
            pq.push(it);
        }
        else
        {
            if (it.second > pq.top().second)
            {
                pq.pop();
                pq.push(it);
            }
        }
    }

    while (!pq.empty())
    {
        res.push_back(pq.top().first);
        pq.pop();
    }

    return res;
}
