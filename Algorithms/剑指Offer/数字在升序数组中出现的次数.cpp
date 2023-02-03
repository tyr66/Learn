#include <iostream>
#include <string>
#include <vector>
using namespace std;

int find_left_boundary(vector<int> &arr, int tar)
{

    if (arr.empty())
        return -1;

    if (arr[0] >= tar)
        return -1;

    int lo = 0, hi = arr.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] >= tar)
            hi = mid;
        else
            lo = mid + 1;
    }

    return arr[lo] >= tar ? lo - 1 : lo;
}

int find_right_boundary(vector<int> &arr, int tar)
{

    if (arr.empty())
        return 0;

    if (arr[arr.size() - 1] <= tar)
        return arr.size();

    int lo = 0, hi = arr.size() - 1;

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] <= tar)
            lo = mid + 1;
        else
            hi = mid;
    }

    return arr[lo] <= tar ? lo + 1 : lo;
}

int GetNumberOfK(vector<int> data, int k)
{

    int left_boundary = find_left_boundary(data, k);
    int right_boundary = find_right_boundary(data, k);
    return right_boundary - left_boundary - 1;
}