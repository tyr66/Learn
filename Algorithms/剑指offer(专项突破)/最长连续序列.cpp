#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 思路： 哈希表
// 时间复杂度: O(n), 通过均摊分析得出。空间复杂度：O(n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> uset;
        int max_length = 0;
        for (auto n : nums)
            uset.insert(n);
        
        for (auto n : nums)
        {
            if (uset.count(n - 1) == 0)
            {
                int length = 1;
                while (uset.count(n + 1))
                {
                    length++;
                    n++;
                }

                max_length = max(length,max_length);
            }
        }
        
        return max_length;
    }
};