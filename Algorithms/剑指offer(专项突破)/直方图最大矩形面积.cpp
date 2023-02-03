#include <iostream>
#include <vector>
#include<stack>
using namespace std;

int largestRectangleArea(vector<int> &heights)
{
    stack<int> left_st;
    stack<int> right_st;
    vector<int> max_heights(heights.size(),0);

    int res = INT_MIN;
    int i = 0,j = heights.size()-1;

    while(i<heights.size()&&j>=0)
    {

        while(!left_st.empty()&&heights[left_st.top()]>=heights[i])
        {
            left_st.pop();
        }

        int len = left_st.empty()? i+1:i - left_st.top();
        max_heights[i]+=len*heights[i];

        while(!right_st.empty()&&heights[right_st.top()]>=heights[j])
        {
            right_st.pop();
        }

        len = right_st.empty()? heights.size() - j:right_st.top() - j;
        max_heights[j]+= len*heights[j];

        left_st.push(i);
        right_st.push(j);

        i++;
        j--;
    } 

    for(int i = 0;i<heights.size();i++)
    {
        //消除重复的部分
        res = max(res,max_heights[i]-heights[i]);
    }

    return res;
}