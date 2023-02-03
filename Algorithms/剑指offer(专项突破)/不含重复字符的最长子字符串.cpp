#include <iostream>
#include <string>
#include <vector>
using namespace std;

int lengthOfLongestSubstring(string s)
{
    vector<int> char_hash;
    char_hash.resize(128, 0);

    int lo = 0, hi = 0;
    int res = 0;

    while (hi < s.size())
    {
        while (lo < hi && char_hash[s[hi]])
        {
            char_hash[s[lo++]] = 0;
        }

        char_hash[s[hi]] = 1;
        res = max(res, hi - lo);
        hi++;
    }

    return res;
}

int main()
{
    return 0;
}