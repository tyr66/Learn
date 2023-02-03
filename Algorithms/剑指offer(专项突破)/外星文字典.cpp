#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

#define START 97
#define END 123
class Solution {
public:
    string alienOrder(vector<string>& words) {
        if (words.empty())
            return "";
        if (words.size() == 1)
            return words[0];

        graph.resize(128, vector<bool>(128, false));
        indegrees.resize(128, -1);
        int total_cnt = 0;

        for (int k = 0; k < words.size() - 1; k++)
        {
            string& a = words[k];
            string& b = words[k + 1];
            bool iscompare = false;
            
            for (int i = 0; i < a.size() || i < b.size(); i++)
            {
                if (i < a.size() && indegrees[a[i]] == -1)
                {
                    indegrees[a[i]] = 0;
                    total_cnt++;
                }
                if (i < b.size() && indegrees[b[i]] == -1)
                {
                    indegrees[b[i]] = 0;
                    total_cnt++;
                }
                if (i < a.size() && i < b.size() )
                {
                    if (a[i] != b[i] && !iscompare)
                    {
                        iscompare = true;
                        if (!graph[a[i]][b[i]])
                        {
                            graph[a[i]][b[i]] = true;
                        indegrees[b[i]]++;
                        }
                        
                        
                    }
                } else if (!iscompare && a.size() > b.size())
                {
                    return "";
                }
            }
        }
        
        queue<int> que;        
        string res;
        int cnt = 0;
        for (int i = START; i < END; i++)
        {
            if (indegrees[i] == 0)
            {
                cnt++;
                res.push_back(i);
                que.push(i);
            }
        }

        while (!que.empty())
        {
            int n = que.front();
            que.pop();
            
            for (int i= START; i < END; i++)
            {
                if (graph[n][i] &&--indegrees[i] == 0)
                {
                    que.push(i);
                    cnt++;
                    res.push_back(i);
                }
            }
        }
        return cnt == total_cnt ? res : "";
    }

private:
    vector<vector<bool>> graph;
    vector<int> indegrees;
};