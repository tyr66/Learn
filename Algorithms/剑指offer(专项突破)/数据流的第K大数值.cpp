#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int>& nums):pq(nums.begin(), nums.end()), _k(k) {

        while (pq.size() > k) {
            pq.pop();
        }
    }
    
    int add(int val) {

        if (pq.size () < _k)
        {
            pq.push(val);
            return pq.top();
        }

        if (val <= pq.top()) {
            return pq.top();
        }

        pq.pop();
        pq.push(val);
        return pq.top();
    }

private:
    priority_queue<int, vector<int>, std::greater<int>> pq;
    int _k;
};