#include <iostream>
#include <vector>

using namespace std;

int quickSelect(vector<int> &nums, int lo, int hi)
{
    int i = lo + 1, j = hi;
    int k = lo;

    while (i <= j)
    {
        if (nums[k] < nums[i])
        {
            swap(nums[i], nums[j--]);
        }
        else if (nums[k] > nums[i])
        {
            swap(nums[i++], nums[k++]);
        }
        else
        {
            i++;
        }
    }

    return k;
}

int findKthLargest(vector<int> &nums, int k)
{
    int lo = 0;
    int hi = nums.size() - 1;

    while (lo < hi)
    {
        int idx = quickSelect(nums, lo, hi);

        if (idx == k)
            break;
        if (idx > k)
            hi = idx - 1;
        else
            lo = idx + 1;
    }

    return nums[k];
}