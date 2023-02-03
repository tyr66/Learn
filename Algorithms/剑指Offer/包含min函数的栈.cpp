#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    void push(int value)
    {
        value_stack.push(value);
        if (min_stack.empty() || value < min_stack.top())
            min_stack.push(value);
        else
            min_stack.push(min_stack.top());
    }
    void pop()
    {
        if (value_stack.empty())
            throw;

        value_stack.pop();
        min_stack.pop();
    }
    int top()
    {
        if (value_stack.empty())
            throw;

        return value_stack.top();
    }
    int min()
    {
        if (min_stack.empty())
            throw;

        return min_stack.top();
    }

private:
    stack<int> value_stack;
    stack<int> min_stack;
};