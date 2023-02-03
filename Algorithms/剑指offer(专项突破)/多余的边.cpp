#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges)
    {

        int n = edges.size() + 1;
        rank.resize(n, 0);
        unset.resize(n);

        for (int i = 0; i < n; i++)
            unset[i] = i;

        for (int k = 0; k < n; k++)
        {
            int i = edges[k][0];
            int j = edges[k][1];

            if (getparent(i) == getparent(j))
            {
                return {i, j};
            }

            un(i, j);
        }

        return {};
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