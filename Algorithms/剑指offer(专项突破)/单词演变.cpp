#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// 思路：先建图，在进行bfs。关键在于如何高效的建立图，建立图的方法可以参考：https://leetcode.cn/problems/om3reC/solution/dan-ci-yan-bian-by-leetcode-solution-8v7s/
// 优化在数据量很大的情况下，搜索空间可能会非常大，为了降低搜索空间我们可以使用双向bfs，分别从起点和终点开始。
class Solution
{
public:
    void build_graph(vector<string>& wordlist, string& beginword)
    {
        word_to_graph(beginword);

        for (int i = 0; i < wordlist.size(); i++)
        {
            word_to_graph(wordlist[i]);
        }
    }

    void word_to_graph(string& word)
    {
        if (ump.count(word) != 0)
            return;

        int idx = add_node(word);

        for (char& c : word)
        {
            char tmp = c;
            c = '*';
            add_edge(idx, add_node(word));
            c = tmp;
        }
    }

    int add_node(const string& word)
    {
        if (ump.count(word) != 0)
            return ump[word];

        int idx = node_count;
        ump[word] = node_count++;
        adj_list.emplace_back();
        return idx;
    }

    void add_edge(int from, int to)
    {
        if (from >= node_count || to >= node_count)
            return;

        adj_list[from].push_back(to);
        adj_list[to].push_back(from);
    }

    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        if (wordList.empty())
            return 0;

        int begin_path = 1, end_path = 1;
        int begin_count = 0, end_count = 0;
        vector<int> arrived;
        queue<int> begin_queue;
        queue<int> end_queue;

        build_graph(wordList, beginWord);

        if (ump.count(beginWord) == 0 || ump.count(endWord) == 0)
            return 0;

        arrived.resize(node_count, 0);
        begin_queue.push(ump[beginWord]);
        end_queue.push(ump[endWord]);

        arrived[ump[beginWord]] = 1;
        arrived[ump[endWord]] = -1;
        begin_count = end_count = 1;

        while (!begin_queue.empty() && !end_queue.empty())
        {
            int begin_n = begin_queue.front();
            begin_queue.pop();
            int end_n = end_queue.front();
            end_queue.pop();

            for (int to : adj_list[begin_n])
            {
                if (arrived[to] < 0)
                    return (begin_path + 1 + abs(arrived[to])) / 2;

                if (arrived[to] > 0)
                    continue;

                arrived[to] = begin_path + 1;
                begin_queue.push(to);
            }

            for (int to : adj_list[end_n])
            {
                if (arrived[to] > 0)
                    return (end_path + 1 + arrived[to]) / 2;

                if (arrived[to] < 0)
                    continue;

                arrived[to] = -end_path - 1;
                end_queue.push(to);
            }

            if (--begin_count == 0)
            {
                begin_path++;
                begin_count = begin_queue.size();
            }
            if (--end_count == 0)
            {
                end_path++;
                end_count = end_queue.size();
            }
        }
        return 0;
    }

private:
    unordered_map<string, int> ump;
    vector<vector<int>> adj_list;
    int node_count = 0;
};
