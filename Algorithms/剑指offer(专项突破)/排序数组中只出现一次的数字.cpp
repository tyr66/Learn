#include <iostream>
#include <vector>

using namespace std;
// 方法1： 直接进行异或运算
int singleNonDuplicate(vector<int> &nums)
{
    int res = 0;

    for (auto n : nums)
    {
        res = res ^ n;
    }

    return res;
}

// 方法2：进行二分查找
int singleNonDuplicate(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];

    int lo = 0, hi = nums.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (nums[mid] == nums[mid - 1])
        {
            if ((mid + 1) % 2 == 0)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 2;
            }
        }
        else if (nums[mid] == nums[mid + 1])
        {
            if ((nums.size() - mid) % 2 == 0)
            {
                hi = mid - 1;
            } else 
            {
                lo = mid + 2;
            }
        }
        else
        {
            return nums[mid];
        }
    }

    return nums[lo];
}