#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

bool is_operator(char c)
{
    if (c == '*' || c == '+' || c == '-' || c == '/')
        return true;
    return false;
}

int caculate(int a, int b, char o)
{
    int result = 0;

    switch (o)
    {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        result = a / b;
        break;
    }

    return result;
}

int get_number(const string &a)
{
    int res = 0;
    int i = 0;
    int sign = a[0] == '-' ? -1 : 1;

    if (a[0] == '-' || a[0] == '+')
        i++;

    for (; i < a.size(); i++)
    {
        res = res * 10 + (a[i] - '0');
    }
    
    return res*sign;
}

int evalRPN(vector<string> &tokens)
{
    int res = 0;
    stack<int> number_st;

    for (int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i].size() == 1&&is_operator(tokens[i][0]))
        {
            int b = number_st.top();
            number_st.pop();
            int a = number_st.top();
            number_st.pop();
            number_st.push(caculate(a, b, tokens[i][0]));
        }
        else
        {
            number_st.push(get_number(tokens[i]));
        }
    }

    return number_st.top();
}

int main()
{
    return 0;
}