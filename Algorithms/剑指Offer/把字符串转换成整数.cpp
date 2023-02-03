#include <iostream>
#include <string>
using namespace std;

string str_max_int = "+2147483647";
string str_min_int = "-2147483648";

bool is_vaild(const string &s)
{
    int signal_limit = 1;
    int number_count = 0;

    for (int i = 0; i < s.size() && number_count == 0 && signal_limit >= 0; i++)
    {
        if (s[i] == ' ')
            continue;

        if (s[i] == '+' || s[i] == '-')
        {
            --signal_limit;
            continue;
        }

        if (s[i] >= '0' || s[i] <= '9')
        {
            number_count++;
        }
        else
            return false;
    }

    return number_count > 0;
}

string get_number_str(const string &s)
{
    int signal_limit = 1;
    string str_number;
    bool is_prev_zero = true;

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
            continue;

        if (s[i] == '+' || s[i] == '-')
        {
            if (--signal_limit < 0)
                break;
            str_number.push_back(s[i]);
            continue;
        }

        if (s[i] >= '0' && s[i] <= '9')
        {
            if (signal_limit == 1)
            {
                --signal_limit;
                str_number.push_back('+');
            }

            if(s[i] != '0'||!is_prev_zero)
            {
                str_number.push_back(s[i]);
                is_prev_zero = false;
            }
        }
        else
            break;
    }

    if(str_number.size() == 1)
    str_number.push_back('0');

    return str_number;
}
bool is_outof_range(const string &number)
{
    if (number.size() != str_max_int.size())
        return number.size() > str_max_int.size();

    for (int i = 1; i < number.size(); i++)
    {
        if (number[i] > str_max_int[i])
            return true;
    }

    return false;
}

int str_to_int(const string &number)
{
    int value = 0;
    for (int i = 1; i < number.size(); i++)
    {
        value = value * 10 + (number[i] - '0');
    }

    return number[0] == '-' ? -value : value;
}

int StrToInt(string s)
{
    if (!is_vaild(s))
        return 0;

    string number_str = get_number_str(s);

    if (is_outof_range(number_str))
        return number_str[0] == '-' ? INT_MIN : INT_MAX;

    return str_to_int(number_str);
}