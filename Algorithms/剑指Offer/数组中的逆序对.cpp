#include <iostream>
#include <vector>
using namespace std;

vector<int> tmp;

long long merge(vector<int>& arr, int lo, int mid, int hi)
{
    for (int i = lo; i <= hi; i++)
        tmp[i] = arr[i];

    int i = lo, j = mid + 1, k = lo;
    long long count = 0;

    while (i <= mid || j <= hi)
    {
        if (i == mid + 1)
        {
            arr[k++] = tmp[j++];
        }
        else if (j == hi + 1)
        {
            count += j - mid-1;
            arr[k++] = tmp[i++];
        }
        else if (tmp[i] > tmp[j])
        {
            arr[k++] = tmp[j++];
        }
        else
        {
            count += j - mid-1;
            arr[k++] = tmp[i++];
        }
    }

    return count;
}

long long get_inversePairs_count(vector<int>& arr, int lo, int hi)
{
    if (lo >= hi)
        return 0;

    int mid = (lo + hi) >> 1;

    long long count = get_inversePairs_count(arr, lo, mid);
    count += get_inversePairs_count(arr, mid + 1, hi);
    count += merge(arr, lo, mid, hi);

    return count;
}

int InversePairs(vector<int> data)
{
    tmp.resize(data.size());
    long long res = get_inversePairs_count(data, 0, data.size() - 1)%1000000007;
    return res;
}

void print_arr(vector<int>&arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    vector<int>arr = { 3,2,1 };
    cout << InversePairs(arr);
    return 0;
}