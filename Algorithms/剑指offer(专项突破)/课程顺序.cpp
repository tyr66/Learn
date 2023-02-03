#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

// 思路：深度或者是广度优先搜索
// 时间复杂度：O(n + m) ，其中n为课程数，m为所有先修课程的总前置要求数
class Solution {
public:
   vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        if (numCourses <= 0 || prerequisites.empty()) 
            return {};
        
        vector<int> path;
        vector<int> indegrees;
        vector<vector<int>> graph;
        int cnt = 0;
        indegrees.resize(numCourses, 0);
        graph.resize(numCourses, vector<int>());

        for (auto& it : prerequisites)
        {
            indegrees[it[0]]++;
            graph[it[1]].push_back(it[0]);
        }

        queue<int> que;
        for (int i = 0; i < numCourses; i++)
        {
            if (indegrees[i] == 0)    
            {
                cnt++;
                que.push(i);
                path.push_back(i);
            }
        }
        
        while (!que.empty())
        {
            int n = que.front();
            que.pop();
            
            for (auto m : graph[n])
            {
                if (--indegrees[m] == 0)
                {
                    que.push(m);
                    cnt++;
                    path.push_back(m);
                }
            }
        }
        
        return cnt == numCourses ? path : vector<int>();
    }
};