#include <iostream>
#include <vector>
using namespace std;

bool checkInclusion(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return s1.empty();
    if (s1.size() > s2.size())
        return false;

    vector<int> str_hash;
    vector<int> count_hash;
    count_hash.resize(26, 0);
    str_hash.resize(26, 0);

    for (int i = 0; i < s1.size(); i++)
        str_hash[s1[i] - 'a']++;

    int lo = 0, hi = 0;
    int len = 0;

    while (hi < s2.size())
    {
        int idx = s2[hi] - 'a';
        
        if (str_hash[idx] > 0 && count_hash[idx] < str_hash[idx])
        {
            len++;
            count_hash[idx]++;
            hi++;
        }
        else if (str_hash[idx] == 0)
        {
            len = 0;
            while (lo < hi)
            {
                count_hash[s2[lo] - 'a']--;
                lo++;
            }
            lo = ++hi;
        }
        else
        {
            while (lo < hi && count_hash[idx] >= str_hash[idx])
            {
                count_hash[s2[lo] - 'a']--;
                lo++;
                len--;
            }
        }
        if (len == s1.size())
            return true;
    }
    return len == s1.size();
}

int main()
{

    return 0;
}