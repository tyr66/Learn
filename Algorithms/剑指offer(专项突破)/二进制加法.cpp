#include <iostream>
#include <string>
using namespace std;

char char_add(char a, char b, bool &is_carry)
{
    if (a == '1' && b == '1')
    {
        is_carry = true;
        return'0';
    }

    is_carry = false;

    return a == '1' || b == '1' ? '1' : '0';
}

string addBinary(string a, string b)
{
    if (a.empty() || b.empty())
        return a.empty() ? b : a;

    string res;
    bool is_carry = 0;
    int i = a.size() - 1, j = b.size() - 1;

    while (i >= 0 || j >= 0)
    {
        if (i < 0)
        {
            res.push_back(char_add(b[j--], is_carry ? '1' : '0', is_carry));
        }
        else if (j < 0)
        {
            res.push_back(char_add(a[i--], is_carry ? '1' : '0', is_carry));
        }
        else
        {

            bool tmp = false;
            char add_res = char_add(b[j--], a[i--], tmp);
            res.push_back(char_add(add_res, is_carry ? '1' : '0', is_carry));
            is_carry = tmp || is_carry;
        }
    }

    if (is_carry)
        res.push_back('1');

    i = 0;
    j = res.size() - 1;

    while (i < j)
        swap(res[i++], res[j--]);

    return res;
}

int main()
{

    return 0;
}