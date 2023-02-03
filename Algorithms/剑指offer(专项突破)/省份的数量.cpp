#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 思路： 宽度或者是深度优先搜索，以及并查集 本题并查集的时间复杂度更优
// 时间复杂度 宽度或者深度优先搜索 O(n^2)
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {

        int cnt = isConnected.size();
        vector<int> arrived;
        queue<int> que;
        int num = 0;
        arrived.resize(cnt, 0);
        
        for (int i = 0; i < cnt; i++)
        {
            if (arrived[i] != 0)
                continue;
            
            que.push(i);
            arrived[i] = ++num;
            while (!que.empty())
            {
                int n = que.front();
                que.pop();
                
                for (int j = 0; j < cnt; j++)
                {
                    if (isConnected[n][j] && arrived[j] == 0)
                    {
                        que.push(j);
                        arrived[j] = num;
                    }
                }
            }
        }
        
        return num;
    }
};