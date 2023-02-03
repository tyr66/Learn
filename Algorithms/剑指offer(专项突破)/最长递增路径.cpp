#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int dirs[] = {1, 0, -1, 0, 0, 1, 0, -1};

// 记忆化深度优先搜索 
// 时间复杂度: O(r * c) 其中r 为输入矩阵的行数，c为输入矩阵的列数。
// 另外有动态规划的解法 可参考：https://leetcode.cn/problems/longest-increasing-path-in-a-matrix/solution/ju-zhen-zhong-de-zui-chang-di-zeng-lu-jing-by-le-2/
class Solution
{
public:
    int dfs(int n, int m, vector<vector<int>>& matrix)
    {
        for (int k = 0; k < 8; k+=2)
        {
            int i = n + dirs[k];
            int j = m + dirs[k + 1];
            
            if (i < 0 || i >= r)
            continue;
            if (j < 0 || j>= c)
            continue;
            if (matrix[n][m] >= matrix[i][j])
            continue;

            if (graph[i][j] != 0)
            {
                graph[n][m] = max(graph[n][m], graph[i][j] + 1);
            } else {
               graph[n][m] = max(graph[n][m], dfs(i,j, matrix) + 1); 
            }
        }

        return graph[n][m];
    }

    int longestIncreasingPath(vector<vector<int>> &matrix)
    {
        queue<int> que;
        int res = 0;        
        r = matrix.size();
        c = matrix[0].size();
        
        graph.resize(r, vector<int>(c, 0));
        
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                res = max(dfs(i,j,matrix), res);
            }
        }

        return res + 1;
    }
    
private:
    vector<vector<int>> graph;
    int r;
    int c;
};