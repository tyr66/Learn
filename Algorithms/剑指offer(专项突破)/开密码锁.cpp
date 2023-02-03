#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

// 思路： 双向宽度优先搜索
// 时间复杂度： O(k*b^d) 其中d为位数，b为每一位的可能数字,k为 每一个字符串可转变的不同字符串数
// 在本题中d的值为 4， b的值为 10， k 的值为8(“0000” 总共可以转杯为 "0001", "0009", ... , 中字符串)
class Solution
{
public:
    int openLock(vector<string> &deadends, string target)
    {

        if (target.empty())
            return -1;

        if (target == "0000")
            return 0;

        int len = 0;
        unordered_map<string, int> ump;
        queue<string> forward_queue;
        queue<string> backward_queue;
        backward_queue.push(target);
        forward_queue.push("0000");

        int forward_step = 2, backward_step = 2;
        int forward_cnt = 1, backward_cnt = 1;
        for (string &end : deadends)
        {
            ump[end] = 0;
        }
        
        if (ump.count("0000") || ump.count(target))
            return -1;

        ump["0000"] = 1;
        ump[target] = -1;

        while (!forward_queue.empty() && !backward_queue.empty())
        {
            string forward_str = forward_queue.front();
            string backward_str = backward_queue.front();
            forward_queue.pop();
            backward_queue.pop();

            for (int i = 1, j = 0; i <= 8; i++)
            {
                char tmp = forward_str[j];

                if (i & 1)
                    forward_str[j] = tmp == '9' ? '0' : tmp + 1;
                else
                    forward_str[j] = tmp == '0' ? '9' : tmp - 1;

                if (ump.count(forward_str) == 0)
                {
                    ump[forward_str] = forward_step;
                    forward_queue.push(forward_str);
                }
                else if (ump[forward_str] < 0)
                {
                    return forward_step + abs(ump[forward_str]) - 2;
                }

                forward_str[j] = tmp;
                if ((i & 1) == 0)
                    j++;
            }

            for (int i = 1, j = 0; i <= 8; i++)
            {
                char tmp = backward_str[j];

                if (i & 1)
                    backward_str[j] = tmp == '9' ? '0' : tmp + 1;
                else
                    backward_str[j] = tmp == '0' ? '9' : tmp - 1;

                if (ump.count(backward_str) == 0)
                {
                    ump[backward_str] = -backward_step;
                    backward_queue.push(backward_str);
                }
                else if (ump[backward_str] > 0)
                {
                    return backward_step + ump[backward_str] - 2;
                }

                backward_str[j] = tmp;

                if ((i & 1) == 0)
                    j++;
            }

            if (--forward_cnt == 0)
            {
                forward_cnt = forward_queue.size();
                forward_step++;
            }

            if (--backward_cnt == 0)
            {
                backward_cnt = backward_queue.size();
                backward_step++;
            }
        }

        return -1;
    }
};