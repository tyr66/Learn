#include <iostream>
#include <string>
using namespace std;

inline bool legal(char &c)
{
    if (c >= 'a' && c <= 'z')
        return true;
    if (c >= 'A' && c <= 'Z')
    {
        c = 'a' + (c - 'A');
        return true;
    }
    return c >= '0' && c <= '9';
}

bool isPalindrome(string s)
{
    int lo = 0, hi = s.size() - 1;

    while (lo < hi)
    {
        while (lo < hi && !legal(s[lo]))
            lo++;
        while (lo < hi && !legal(s[hi]))
            hi--;

        if (s[lo] != s[hi])
            return false;
        
        lo++;
        hi--;
    }

    return true;
}

int main()
{
    return 0;
}