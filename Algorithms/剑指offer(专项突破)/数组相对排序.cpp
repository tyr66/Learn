#include <iostream>
#include <vector>

using namespace std;
int bucket[10001];

vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2)
{
    vector<int> res;
    int max_value = INT_MIN;
    for (auto n : arr1)
    {
        bucket[n]++;
        max_value = max(max_value, n); 
    }

    for (auto n : arr2)
    {
        for (int i = 0; i < bucket[n]; i++) 
        {
            res.push_back(n);
        }
        bucket[n] = 0;
    }

    for (int i = 0; i <= max_value; i++)
    {
        while (bucket[i] != 0)
        {
            res.push_back(i);
            bucket[i]--;
        }
    }

    return res;
}