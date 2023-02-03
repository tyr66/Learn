#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 思路： 并查集
// 时间复杂度： O(n^2m + nlog(n)),其中n为字符串的个数,m 为字符串的长度。遍历数组判断每一对字符串是否相似需要O(n^2m)的时间复杂度，在最坏情况下我们需要合并n次并查集，
// 每一次需要O(logn)的时间，通过均摊分析我们额外总共需要O(nlogn)的时间去合并并查集. 
// 空间复杂度：O(n)
class Solution {
public:
    int numSimilarGroups(vector<string>& strs) {
        if (strs.empty())
            return 0;

        unordered_map<string, int> ump;
        int n = strs.size();
        int m = strs[0].size();
        int cnt = 0;
        unset.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++)
            unset[i] = i;
            
        for (int i = 0; i < n; i++) 
        {
            for (int j = i + 1; j < n; j++)
            {
                // 优化1 ： 减少重复的计算
                if (getparent(i) == getparent(j))
                    continue;
                int diff_cnt = 0;
                for (int k = 0; k < m; k++)
                {
                    if (strs[i][k] == strs[j][k])
                        continue;
                    if (diff_cnt > 2)
                        break;
                    diff_cnt++;
                }

                if (diff_cnt == 2 || diff_cnt == 0)
                {
                    un(i, j);
                }
            }

        }

        for (int i = 0; i < n; i++)
            if (unset[i] == i)
            cnt++;
        
        return cnt;
    }

private:
    int getparent(int k)
    {
        if (unset[k] == k)
            return k;
        return unset[k] = getparent(unset[k]);
    }
    void un(int i, int j)
    {
        int i_par = getparent(i);
        int j_par = getparent(j);

        if (i_par == j_par)
            return;

        if (rank[i_par] > rank[j_par])        
        {
            unset[j_par] = i_par;
            return;
        }

        unset[i_par] = j_par;
        
        if (rank[i_par] == rank[j_par])
            rank[j_par]++;
    }

private:
    vector<int> unset;
    vector<int> rank;
};