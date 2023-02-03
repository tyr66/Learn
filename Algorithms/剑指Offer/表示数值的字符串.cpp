#include <iostream>
#include <string>
using namespace std;

bool is_noSign_integer(string& str, int& lo)
{
    int count = 0;

    while (lo<str.size() && ((str[lo] >= '0' && str[lo] <= '9') || (str[lo] == ' ')))
    {
        if(str[lo]!=' ')
            count++;

        lo++;
    }

    return count >= 1;
}

bool is_sign_integer(string& str, int& lo)
{
    while (lo < str.size() && str[lo] == ' ')lo++;

    if (lo >= str.size())
        return false;

    if (str[lo] == '-' || str[lo] == '+')
        lo++;

    return is_noSign_integer(str, lo);
}

bool isNumeric(string str)
{
    int lo = 0;
    bool isNumber = is_sign_integer(str, lo);

    while (lo<str.size() && str[lo] == ' ')lo++;
        
    if (lo < str.size() && str[lo] == '.')
    {
        lo++;
        isNumber = is_noSign_integer(str, lo)||isNumber;
    }

    while (lo < str.size() && str[lo] == ' ')lo++;

    if (lo < str.size() && (str[lo] == 'e' || str[lo] == 'E'))
    {
        lo++;
        isNumber = isNumber && is_sign_integer(str, lo);
    }

    return isNumber && lo == str.size();
}

int main()
{

    string str = "    .2  ";

    if (isNumeric(str))
    {
        cout << "true";
    }
    else

    {
        cout << "false";
    }
    return 0;
}