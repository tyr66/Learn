#include <iostream>
#include <vector>
using namespace std;

int singleNumber(vector<int> &nums)
{
    int bits[32];
    memset(bits, 0, 32 * sizeof(int));

    for (int i = 0; i < 32; i++)
    {
        int mark = 1 << i;

        for (int j = 0; j < nums.size(); j++)
        {
            if (mark & nums[j])
                bits[i]++;
        }
    }

    int res = 0;
    long long val = 1;
    for (int i = 0; i < 32; i++)
    {
        if (bits[i] % 3 == 1)
            res += val;
        val = val << 1;
    }

    return res;
}

int main()
{
    return 0;
}