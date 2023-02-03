#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string s,int lo,int hi)
{
    while(s[lo] == s[hi])
    {
        lo++;
        hi++;
    }

    return lo>=hi;
}

bool validPalindrome(string s)
{
    int lo = 0, hi = s.size() - 1;
    int chance = 1;
    while (lo < hi)
    {
        if (s[lo] == s[hi])
        {
            lo++;
            hi--;
        }
        else if (chance > 0)
        {
            return isPalindrome(s,lo+1,hi)||isPalindrome(s,lo,hi-1);
        }
        else
            return false;
    }

    return true;
}

int main()
{
    return 0;
}