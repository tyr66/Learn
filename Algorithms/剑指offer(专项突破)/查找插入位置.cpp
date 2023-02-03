#include <iostream>
#include <vector>

using namespace std;

int searchInsert(vector<int> &nums, int target)
{
    int lo = 0, hi = nums.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        if (nums[mid] >= target)
        {
            hi = mid ;
        } else {
            lo = mid + 1;
        }
    }

    if (nums[hi] >= target)
        return hi;

    return lo + 1;
}