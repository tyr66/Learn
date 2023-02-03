#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define DIRECTLEN 8
int dir[] = {0, 1, 0, -1, 1, 0, -1, 0};

class Solution
{
public:
    int bfsVisit(vector<vector<int>> &grid, int r, int c, int n, int m)
    {
        int res = 0;
        queue<int> que;
        que.push(r);
        que.push(c);
        visited[r][c] = true;

        while (!que.empty())
        {
            int i = que.front();
            que.pop();
            int j = que.front();
            que.pop();
            res++;

            for (int k = 0; k < DIRECTLEN; k += 2)
            {
                int _i = i + dir[k];
                int _j = j + dir[k + 1];

                if (_i < 0 || _i >= n)
                    continue;
                if (_j < 0 || _j >= m)
                    continue;
                if (visited[_i][_j] || !grid[_i][_j])
                    continue;

                visited[_i][_j] = true;
                que.push(_i);
                que.push(_j);
            }
        }

        return res;
    }

    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        if (grid.empty())
            return 0;

        int n = grid.size();
        int m = grid[0].size();
        int res = 0;
        visited.resize(n, vector<bool>(m, false));

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (grid[i][j] && !visited[i][j])
                {
                    res = max(res, bfsVisit(grid, i, j, n, m));
                }
            }
        }
        
        return res;
    }

private:
    vector<vector<bool>> visited;
};