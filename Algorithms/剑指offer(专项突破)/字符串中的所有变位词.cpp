#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<int> findAnagrams(string s, string p)
{
    if (s.empty() || p.empty())
        return {};
    if (p.size() > s.size())
        return {};

    int lo = 0, hi = 0;
    int len = 0;
    vector<int> res;
    vector<int> str_hash;
    vector<int> count_hash;
    str_hash.resize(26, 0);
    count_hash.resize(26, 0);

    for (int i = 0; i < p.size(); i++)
        str_hash[p[i] - 'a']++;

    while (hi < s.size())
    {
        int hi_idx = (s[hi] - 'a');
        if (str_hash[hi_idx] > 0 && count_hash[hi_idx] < str_hash[hi_idx])
        {
            hi++;
            len++;
            count_hash[hi_idx]++;
        }
        else if (str_hash[hi_idx] == 0)
        {
            while (lo < hi)
            {
                count_hash[s[lo++] - 'a']--;
            }
            lo = ++hi;
            len = 0;
        }
        else
        {
            while (lo < hi && count_hash[hi_idx] >= str_hash[hi_idx])
            {
                count_hash[s[lo++] - 'a']--;
                len--;
            }
        }

        if (len == p.size())
        {
            count_hash[s[lo] - 'a']--;
            res.push_back(lo++);
            len--;
        }
    }

    return res;
}

int main()
{

    return 0;
}