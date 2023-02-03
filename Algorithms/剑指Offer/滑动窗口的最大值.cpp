#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> maxInWindows(const vector<int> &num, unsigned int size)
{
    if (size > num.size() || num.empty())
        return {};

    deque<int> dequeue;
    vector<int> res;
    int lo = 0, hi = 0;

    while (hi < num.size())
    {
        if (dequeue.empty())
        {
            dequeue.push_back(num[hi]);
        }
        else
        {
            while (!dequeue.empty() && dequeue.back() < num[hi])
                dequeue.pop_back();
            dequeue.push_back(num[hi]);
        }

        hi++;

        if (hi - lo == size)
        {
            res.push_back(dequeue.front());
            if (dequeue.front() == num[lo])
                dequeue.pop_front();
            lo++;
        }
    }

    return res;
}

int main()
{

    return 0;
}