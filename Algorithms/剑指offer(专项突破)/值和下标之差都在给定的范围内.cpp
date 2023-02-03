#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
解题思路：
    桶的思想，将数轴划分为段 [0,t] 映射到 0， [-t, 0) 映射到 -1 依此类推，由此分布在同一段中的数都
    满足 abs(nums[i] - nums[j]) <= t ，使用滑动窗口的思想然后遍历数组获取该数的段id，如果当前id中
    已经存在元素，那么满足条件结果为真，否则查看相邻的段是否存在元素，如果有检查是否满足 
    abs(nums[i] - nums[j]) <= t 这个条件如果满足结果为真。要注意将超过 abs(i - j) <= k 这个限制条件
    的元素从字典中删除
*/
int getBucketID(int n, long long mask)
{
    if (n >= 0)
        return n / mask;

    return n / mask - 1;
}

bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t)
{

    unordered_map<long long, int> ump;

    long long mask = t + 1ll;
    long long llt = t;

    for (int i = 0; i < nums.size(); i++)
    {
        long long bucketID = getBucketID(nums[i], mask);

        if (ump.count(bucketID))
            return true;
        
        if (ump.count(bucketID + 1) && llabs(nums[ump.at(bucketID + 1)] - (long long)nums[i]) <= llt)
            return true;

        if (ump.count(bucketID - 1) && llabs(nums[ump.at(bucketID - 1)] - (long long)nums[i]) <= llt)
            return true;


        if (i >= k) {
            ump.erase(getBucketID(nums[i - k], mask));
        }
        
        if (k != 0)
        ump[bucketID] = i;
    }

    return false;
}

int main()
{
    std::vector<int> arr = {1, 2 };
    cout << containsNearbyAlmostDuplicate(arr, 0, 1);
    return 0;
}