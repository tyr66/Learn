#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

// 思路：floyd 算法或者是宽度优先搜索
class Solution {
public:
    void add_node(string&str)
    {
        if (ump.count(str))
            return ;
        ump[str] = node_cnt++;
    }
    
    void build_graph(vector<vector<string>>&equations, vector<double>&values)
    {
        for (int i = 0; i < equations.size(); i++)
        {
            add_node(equations[i][0]);    
            add_node(equations[i][1]);
        }
        
        graph.resize(node_cnt, vector<double>(node_cnt, INT_MAX));
        
        for (int i = 0; i < equations.size(); i++)
        {
            int n = ump[equations[i][0]];
            int m = ump[equations[i][1]];
            
            graph[n][m] = values[i];
            graph[m][n] = 1.0 / values[i];
            graph[n][n] = graph[m][m] = 1;
        }
    }
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        
        if (equations.size() != values.size())
            return {};
        
        vector<double> res;
        build_graph(equations, values);

        for (int k = 0; k < node_cnt; k++)
        {
            bool hasRelax = false;
            for (int i = 0; i < node_cnt; i++)
            {
                for (int j = 0; j < node_cnt; j++)
                {
                    if (graph[i][k] != INT_MAX && graph[k][j] != INT_MAX)
                    {
                        hasRelax = true;
                        graph[i][j] = min(graph[i][j], graph[i][k]*graph[k][j]);
                    }
                }
            }

            if (!hasRelax)
                break;
        }
        
        for (auto&it : queries)
        {
            if (ump.count(it[0]) != 0 && ump.count(it[1]) != 0)
            {
            int n = ump[it[0]];
            int m = ump[it[1]];
            res.push_back(graph[n][m] == INT_MAX ? -1 : graph[n][m]);
            } else {
                res.push_back(-1);
            }
        }

        return res;
    }
private:
        int node_cnt = 0;
        unordered_map<string, int> ump;
        vector<vector<double>> graph;
};