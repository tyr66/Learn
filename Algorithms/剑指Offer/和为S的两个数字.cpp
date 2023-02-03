#include <iostream>
#include <vector>
using namespace std;

vector<int> FindNumbersWithSum(vector<int> array, int sum)
{
    if (array.empty())
        return {};

    vector<int> res;

    int lo = 0, hi = array.size() - 1;

    while (lo < hi)
    {
        int val = array[lo] + array[hi];

        if (val == sum)
        {
            break;
        }

        if (val > sum)
            hi--;
        else
            lo++;
    }

    if (lo < hi)
    {
        res.push_back(array[lo]);
        res.push_back(array[hi]);
    }

    return res;
}

int main()
{

    return 0;
}