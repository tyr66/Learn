#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    if (nums.empty())
        return 0;
    if (nums.size() == 1)
        return nums[0];

    int ppp1 = 0, pp1 = 0, p1 = 0;
    int cur1 = 0;

    for (int i = 0; i < nums.size() - 1; i++)
    {
        cur1 = max(ppp1, pp1) + nums[i];
        ppp1 = pp1;
        pp1 = p1;
        p1 = cur1;
    }

    int ppp2 = 0, pp2 = 0, p2 = 0;
    int cur2 = 0;

    for (int i = 1; i < nums.size(); i++)
    {
        cur2 = max(ppp2, pp2) + nums[i];
        ppp2 = pp2;
        pp2 = p2;
        p2 = cur2;
    }

    cur1 = max(p1, pp1);
    cur2 = max(p2, pp2);

    return max(cur1, cur2);
}