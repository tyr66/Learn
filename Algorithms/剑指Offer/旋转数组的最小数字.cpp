#include <iostream>
#include <vector>
using namespace std;

int get_min(vector<int> &arr, int lo, int hi)
{
    int res = INT_MAX;

    for (; lo <= hi; lo++)
    {
        if (arr[lo] < res)
            res = arr[lo];
    }
    return res;
}

int minNumberInRotateArray(vector<int> rotateArray)
{
    int lo = 0, hi = rotateArray.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (rotateArray[mid] == rotateArray[lo] && rotateArray[mid] == rotateArray[hi])
            return get_min(rotateArray, lo, hi);

        if (rotateArray[lo] < rotateArray[hi])
            return rotateArray[lo];

        if (rotateArray[lo] <= rotateArray[mid])
        {
            // mid在左边
            lo = mid + 1;
        }
        else
        {
            // mid在右边
            hi = mid;
        }
    }

    return rotateArray[lo];
}

int main()
{

    return 0;
}