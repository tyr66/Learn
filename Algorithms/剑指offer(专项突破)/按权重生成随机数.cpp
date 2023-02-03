#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

class Solution {
public:
    Solution(vector<int> &w)
    {
        total  = 0;
        arr.resize(w.size(), 0);
        for (int i = 0; i < w.size(); i++)
        {
            total += w[i];
            if (i > 0)
            {
                arr[i] = arr[i - 1] + w[i];
            }
            else
            {
                arr[i] = w[i];
            }
        }
    }

    int pickIndex()
    {
        int number = rand() % total;
        int lo = 0, hi = arr.size() - 1;

        while (lo < hi)
        {
            int mid = (lo + hi) >> 1;

            if (arr[mid] > number)
            {
                hi = mid;
            }
            else
            {
                lo = mid + 1;
            }
        }

        return lo;
    }

private:
    vector<int> arr;
    int total;
};

int main()
{
    return 0;
}