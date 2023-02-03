#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
    思路1：堆 + 归并思想
*/
// 未优化版 时间复杂度 O(klog(min(n, m))) 其中 n,m 分别为数组 nums1 和 nums2 的长度
vector<vector<int>> kSmallestPairs(vector<int> &nums1, vector<int> &nums2, int k)
{
    vector<int>& short_arr = nums1.size() > nums2.size() ? nums2 : nums1;
    vector<int>& long_arr = nums1.size() > nums2.size() ? nums1 : nums2;
    vector<vector<int>> res;

    auto compare = [&](pair<int, int>& a, pair<int, int>& b)
    {
        return a.first + long_arr[a.second] > b.first + long_arr[b.second];
    };
    priority_queue<pair<int,int>, std::vector<pair<int, int>>, decltype(compare)> pq(compare);
    
    for (auto v : short_arr) {
        pq.push({v, 0});
    }

    k = min(k, (int)(nums1.size() * nums2.size()));
    bool isswap = nums1.size() > nums2.size();

    for (int i = 0; i < k; i++)
    {
        auto it = pq.top();

        if (isswap)
            res.push_back({long_arr[it.second], it.first});
        else 
            res.push_back({it.first, long_arr[it.second]});

        pq.pop();
        it.second++;

        if (it.second < long_arr.size()) {
            pq.push(it);
        }
    }

    return res;
}

// 优化版 时间复杂度 O(k log(k) 
/*
vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        auto cmp = [&nums1, &nums2](const pair<int, int> & a, const pair<int, int> & b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> ans;   
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < min(k, m); i++) {
            pq.emplace(i, 0);
        }
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top(); 
            pq.pop();
            ans.emplace_back(initializer_list<int>{nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/qn8gGX/solution/he-zui-xiao-de-k-ge-shu-dui-by-leetcode-eoce6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/


/*
思路2：二分查找
https://leetcode.cn/problems/qn8gGX/solution/he-zui-xiao-de-k-ge-shu-dui-by-leetcode-eoce6/
*/
