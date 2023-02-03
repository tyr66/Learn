#include <iostream>
#include <vector>

using namespace std;
int mySqrt(int x)
{
    
    uint64_t res = 0;
    uint64_t lo = 0, hi = x;
    while (lo <= hi)
    {
        uint64_t mid = (lo + hi) >> 1;
        uint64_t mul = mid * mid;
        if (mul > x)
        {
            hi = mid - 1;
        }
        else if (mul < x)
        {
            lo = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return lo - 1;
}