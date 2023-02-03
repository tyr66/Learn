#include <iostream>
#include <vector>

using namespace std;

int rob(vector<int> &nums)
{
    int p = 0, pp = 0, ppp = 0;
    int cur = nums[0];

    for (int i = 0; i < nums.size(); i++)
    {
        cur = max(ppp, pp) + nums[i];
        ppp = pp;
        pp = p;
        p = cur;
    }

    if (nums.size() > 1)
        return max(cur, p);
    return cur;
}