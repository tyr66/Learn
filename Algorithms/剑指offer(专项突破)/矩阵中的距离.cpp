#include<iostream>
#include <vector>
#include <queue>

using namespace std;
// 该题的质量很高，可以从中更近一步的学习最短路径的查找算法
// 本题可以使用两种解法 1. 宽度优先搜索, 2. 动态规划
// 详细题解：https://leetcode.cn/problems/2bCMpM/solution/ju-zhen-zhong-de-ju-chi-by-leetcode-solu-0sxk/ 或者
// https://leetcode.cn/problems/01-matrix/solution/01ju-zhen-by-leetcode-solution/
// 动态规划解法
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        if (mat.empty())
            return {};

        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dist;
        // m + n 小于 10^4
        dist.resize(n, vector<int>(m, INT_MAX /2));
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    dist[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (j - 1 >= 0)
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                if (i - 1 >= 0)
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
            }
        }

        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (j + 1 < m)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
                if (i + 1 < n)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
            }
        }
        
        return dist;
    }
};

// 宽度优先搜索
// 时间复杂度为： O(r*c), 空间复杂度为O(r*c)
int dirs[] = {1, 0, -1, 0, 0, 1, 0, -1};
class Solution_BFS {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    
        if (mat.empty())
            return {};

        int r = mat.size();
        int c = mat[0].size();
        queue<int> que;
        vector<vector<int>> res;

        res.resize(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (mat[i][j] == 0)
                {
                    que.push(i);
                    que.push(j);
                    res[i][j] = 1;
                }
            }
        }

        while (!que.empty())
        {
            int i = que.front();
            que.pop();
            int j = que.front();
            que.pop();

            for (int k = 0; k < 8; k += 2)
            {
                int _i = i + dirs[k];
                int _j = j +dirs[k + 1];
                
                if (_i < 0 || _i >= r)
                continue;
                if (_j < 0 || _j >= c)
                continue;
                if (res[_i][_j] != 0)
                continue;
                
                res[_i][_j] = res[i][j] + 1;
                que.push(_i);
                que.push(_j);
            }
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res[i][j]--;
            }
        }
        return res;
    }
    
};

