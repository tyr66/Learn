#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 时间复杂度 O(n^2) ,最坏情况为{70,60, 50, 40 ,30,80} 
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        int n = temperatures.size();

        for (int i = n - 1; i >= 0; i--)        
        {
            int j = i + 1;
            while (j < n && temperatures[j] <= temperatures[i] && res[j] != 0)
            {
                j += res[j];
            }

            if (j < n && temperatures[j] > temperatures[i])
                res[i] = j - i + 1;
        }

        return res;
    }
};

// 时间复杂度O(n), 因为每一个节点最多只访问两次，当访问了第二次后就会被移出栈.
class Solution_stack {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        int n = temperatures.size();
        stack<pair<int,int>> st;

        for (int i = n - 1; i >= 0; i--)        
        {
            while (!st.empty() && temperatures[i] >= st.top().first)
            {
                st.pop();
            }

            if (!st.empty())
                res[i] = st.top().second - i;
            st.push({temperatures[i], i});
        }

        return res;
    }
};