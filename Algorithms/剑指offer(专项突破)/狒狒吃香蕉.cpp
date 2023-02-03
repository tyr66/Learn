#include <iostream>
#include <vector>

using namespace std;

int canEat(vector<int> &piles, int k, int h)
{
    int count = 0;
    for (auto p : piles)
    {
        count += (p % k == 0 ? p / k : p / k + 1);
    }
    return count - h;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int lo = 1;
    int hi = INT_MIN;

    for (int i = 0; i < piles.size(); i++)
    {
        if (piles[i] > hi)
        {
            hi = piles[i];
        }
    }

    while (lo < hi)
    {
        int mid = (lo + hi) >> 1;
        int res = canEat(piles, mid, h);

         if (res > 0)
        {
            lo = mid + 1;
        } else {
            hi = mid ;
        }
    }

    return lo;
}