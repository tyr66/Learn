#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
时间复杂度：O(N^2)
空间复杂度：依照具体的排序算法而定
*/

vector<vector<int>> threeSum(vector<int> &nums)
{
    vector<vector<int>> res;

    sort(nums.begin(), nums.end());
    int len = nums.size() - 2;

    for (int a = 0; a < len; a++)
    {
        int b = a + 1;
        int c = nums.size() - 1;

        while (b < c)
        {
            int sum = nums[b] + nums[c];

            if (sum == -nums[a])
            {
                res.push_back({nums[a], nums[b++], nums[c--]});

                while (b < nums.size() && nums[b-1] == nums[b])
                    b++;
                while (c > b && nums[c] == nums[c+1])
                    c--;
            }
            else if (sum > -nums[a])
            {
                c--;
            }
            else
                b++;
        }

        while (a + 1 < len && nums[a] == nums[a + 1])
            a++;
    }

    return res;
}

int main()
{

    return 0;
}