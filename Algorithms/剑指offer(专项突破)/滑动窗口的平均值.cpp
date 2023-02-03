#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class MovingAverage
{
public:
    /** Initialize your data structure here. */
    MovingAverage(int size)
    {
        this->max_size = size;
        this->arr.resize(size + 1, 0);
        this->lo = 0;
        this->sum = 0;
        this->hi = 1;
    }

    double next(int val)
    {

        if (is_full())
        {
            sum -= front();
            pop_front();
        }

        sum += val;
        push(val);

        return sum / count();
    }

private:
    int count()
    {
        if (hi > lo)
            return hi - lo - 1;

        return arr.size() - (lo - hi) - 1;
    }

    void pop_front()
    {
        lo = (lo + 1) % arr.size();
    }

    void push(int val)
    {
        arr[hi] = val;
        hi = (hi + 1) % arr.size();
    }
    int front()
    {
        return arr[(lo + 1) % arr.size()];
    }
    bool is_full()
    {
        return lo == hi;
    }

private:
    vector<int> arr;
    double sum;
    int max_size;
    int lo;
    int hi;
};