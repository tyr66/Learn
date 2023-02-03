#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generate(vector<string> &res, string &str, int i, int m, int n)
{
    if (i >= str.size())
    {
        res.push_back(str);
        return;
    }

    if (m > 0)
    {
        str[i] = ')';
        generate(res, str, i + 1, m - 1, n);
    }

    if (n > 0)
    {
        str[i] = '(';
        generate(res, str, i + 1, m + 1, n - 1);
    }
}

vector<string> generateParenthesis(int n)
{
    vector<string> res;
    string str;
    str.resize(n * 2, ' ');

    generate(res, str, 0, 0, n);

    return res;
}