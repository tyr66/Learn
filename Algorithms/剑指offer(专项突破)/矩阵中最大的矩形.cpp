#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int maximalRectangle(vector<string>& matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return 0;

    vector<int> heights(matrix[0].size(), 0);
    vector<int> max_heights(matrix[0].size(),0);
    stack<int> st;
    int res = INT_MIN;
    int row = matrix.size();
    int col = heights.size();

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (matrix[i][j] == '0')
                heights[j] = 0;
            else
                heights[j] = 1 + heights[j];
            max_heights[j] = 0;
        }

        for (int j = 0; j < col; j++)
        {

            while (!st.empty() && heights[st.top()] >= heights[j])
            {
                max_heights[st.top()] += heights[st.top()] * (j - st.top());
                st.pop();
            }

            int w = st.empty() ? j + 1 : j - st.top();
            max_heights[j] += w * heights[j];
            st.push(j);
        }

        while (!st.empty())
        {
            max_heights[st.top()] += heights[st.top()] * (col - st.top());
            st.pop();
        }

        for (int j = 0; j < col; j++)
        {
            res = max(res, max_heights[j] - heights[j]);
        }
    }

    return res;
}

int main()
{
    vector<string> matrix = { "10100", "10111", "11111", "10010" };
    cout << maximalRectangle(matrix);
    return 0;
}