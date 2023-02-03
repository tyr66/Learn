#include <iostream>
#include <string>
#include <vector>
using namespace std;

string minWindow(string s, string t)
{
    int lo = 0, hi = 0;
    string res;
    int min_len = INT_MAX;
    int len = 0;
    vector<int> char_hash;
    vector<int> count_hash;
    count_hash.resize(128, 0);
    char_hash.resize(128, 0);

    for (int i = 0; i < t.size(); i++)
        char_hash[t[i]]++;

    while (hi < s.size())
    {
        if (char_hash[s[hi]] != 0)
        {
            len = count_hash[s[hi]] < char_hash[s[hi]]?len+1:len;
            count_hash[s[hi++]]++;
        }
        else
        {
            lo = lo == hi ? hi + 1 : lo;
            hi++;
        }
        
        while(lo<hi&&(char_hash[s[lo]]==0||count_hash[s[lo]] > char_hash[s[lo]]))
        {
            if(count_hash[s[lo]] > char_hash[s[lo]])
                count_hash[s[lo]]--;
            lo++;
        }

        if(len == t.size()&&(min_len>hi - lo))
        {
            min_len = hi - lo;
            res = s.substr(lo,hi-lo);
        }
    }

    return res;
}

int main()
{
    return 0;
}