#include <iostream>
#include <vector>
#include<stack>
using namespace std;

vector<int> dailyTemperatures(vector<int> &temperatures)
{
    stack<int> st;
    vector<int> res(temperatures.size(),0);


    for(int i = temperatures.size()-1;i>=0;i--)
    {

        while(!st.empty()&&temperatures[st.top()]<=temperatures[i])
        {
            st.pop();
        }

        if(!st.empty())
        {
            res[i] = st.top() - i;
        }

        st.push(i);
    }

    return res;
}

int main()
{
    return 0;
}