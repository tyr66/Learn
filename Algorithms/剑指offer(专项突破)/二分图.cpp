#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int getOppositeSet(int set)
    {
        return set == 1 ? 0 : 1;
    }

    bool isBipartite(vector<vector<int>> &graph)
    {
        vector<int> nodes;
        nodes.resize(graph.size(), -1);
        bool res = true;
        queue<int> que;

        for (int i = 0; i < graph.size() && res; i++)
        {
            if (nodes[i] != -1)
                continue;

            que.push(i);
            nodes[i] = 0;

            while (!que.empty() && res)
            {
                int n = que.front();
                que.pop();

                for (int j = 0; j < graph[n].size(); j++)
                {
                    int m = graph[n][j];

                    if (nodes[m] == -1)
                    {
                        nodes[m] = getOppositeSet(nodes[n]);
                        que.push(m);
                    }
                    else if (nodes[m] == nodes[n])
                    {
                        res = false;
                        break;
                    }
                }
            }
        }

        return res;
    }
};