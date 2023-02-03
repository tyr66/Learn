#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 思路：深度优先搜索 或 宽度优先搜索 (在存在环的情况下不适用)
// 时间复杂度 暂时无从下手
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<bool> arrived;
        stack<int> st;
        vector<int> path;
        int target = graph.size() - 1;
        
        arrived.resize(graph.size(), false);
        st.push(0);        

        while (!st.empty())
        {
            int n = st.top();
            path.push_back(n);
            arrived[n] = true;
            bool isFind = false;
            
            for (int i = 0; i < graph[n].size(); i++)
            {
                if (arrived[graph[n][i]])
                    continue;

                if (graph[n][i] == target)
                {
                    path.push_back(target);
                    paths.push_back(path);
                    path.pop_back();
                    continue;
                }
                
                if (!isFind)
                    isFind = true;
                st.push(graph[n][i]);
            }
            
            while (!st.empty() && arrived[st.top()])
            {
               arrived[st.top()] = false;
               st.pop(); 
               path.pop_back();
            }
        }

        return paths;
    }
};