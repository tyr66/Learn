#include <iostream>
#include <vector>
using namespace std;

int peakIndexInMountainArray(vector<int> &arr)
{
    int lo = 0, hi = arr.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (mid - 1 >= lo && arr[mid] > arr[mid - 1]) {
            lo = mid;
        } else {
            hi = mid;
        }
    }

    return lo;
}