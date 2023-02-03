#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool IsPopOrder(vector<int> pushV, vector<int> popV)
{
    stack<int> st;
    int i = 0, j = 0;

    for (; i < pushV.size(); i++)
    {
        st.push(pushV[i]);

        while (!st.empty() && j < popV.size() && st.top() == popV[j])
        {
            st.pop();
            j++;
        }
    }

    while (!st.empty() && j < popV.size() && st.top() == popV[j])
    {
        st.pop();
        j++;
    }

    return i == pushV.size()&&j == popV.size()&&st.empty();
}

int main()
{
    return 0;
}