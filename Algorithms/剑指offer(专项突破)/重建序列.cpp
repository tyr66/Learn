#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 思路： 拓扑排序
// 时间复杂度： O(n + m) 其中n + m 为构建的图中所有节点的入度的总和加上入度为零的节点数
class Solution {
public:
    bool sequenceReconstruction(vector<int>& nums, vector<vector<int>>& sequences) {

        if (nums.empty() || sequences.empty())
            return false;
        
        int node_cnt = nums.size();
        vector<int> indegrees;
        vector<vector<int>> graph;
        queue<int> que;

        indegrees.resize(nums.size() + 1, 0);        
        graph.resize(node_cnt +1 , vector<int>());
        
        // 有可能 nums 中的数据 不在 [1, nums.size()] 的范围内
        for (auto n : nums)
        {
            if (n < 1 || n > node_cnt)
                return false;
        }
        
        for (auto& arr : sequences)
        {
            for (int i = 0; i + 1 < arr.size() ;i++)
            {
                // 有可能出现sequences[i]序列中数字的范围不在 [1, nums.size()]的情况
                if (arr[i] < 1 || arr[i] > node_cnt)
                    return false;
                if (arr[i + 1] < 1 || arr[i + 1] > node_cnt)
                    return false;
                graph[arr[i]].push_back(arr[i + 1]);
                indegrees[arr[i + 1]]++;
            }
        }
        
        for (int i = 1; i <= nums.size(); i++)
        {
            if (indegrees[i] == 0)
            {
                que.push(i);
                node_cnt--;
            }
        }
       
        while (que.size() == 1)
        {
            int n = que.front();
            que.pop();
            
            for (auto m : graph[n])
            {
                if (--indegrees[m] == 0)
                {
                    que.push(m);
                    node_cnt--;
                }
            }
        }
        
        return node_cnt == 0;
    }

};