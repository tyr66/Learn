#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 思路： 
// 方法1：排序 ------> 时间复杂度 O(nlogn)
// 方法2：three-way partitioning + indexing ，时间复杂度O(n)
// 一下解决方案使用方法2进行实现
class Solution
{
public:
    void wiggleSort(vector<int> &nums)
    {
        int n = nums.size();

#define A(i) nums[(1 + i * 2) % (n | 1)]

        auto midIt = nums.begin() + n / 2;
        nth_element(nums.begin(), midIt, nums.end());
        int mid = *midIt;

        // 基础的三向切分是在数组上按照 0->1->2->3->.....->n 的顺序进行切分的，但是这里
        // 通过索引的方式让数组按照 1->3->5->7->9->0->2->4->6->8 的顺序进行切分
        int i = 0, k = 0, j = n - 1;
        while (k <= j)
        {
            if (A(k) > mid)
                swap(A(k++), A(i++));
            else if (A(k) < mid)
                swap(A(k), A(j--));
            else
                k++;
        }
    }
};