#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAnagram(string s, string t)
{
    if (s.size() != t.size()||s==t)
        return false;

    vector<int> char_map;
    char_map.resize(26, 0);

    for (int i = 0; i < s.size(); i++)
    {
        char_map[s[i] - 'a']++;
    }

    for (int i = 0; i < t.size(); i++)
    {
        char_map[t[i] - 'a']--;
        if (char_map[t[i] - 'a'] < 0)
            return false;
    }

    return true;
}

int main()
{
    return 0;
}