#include <iostream>
#include <vector>
#include <string>
#include<unordered_map>
using namespace std;

int char_hash[26];

void get_hashstr(const string &str,string& res)
{
    memset(char_hash, 0, sizeof(char_hash));

    for (int i = 0; i < str.size(); i++)
    {
        char_hash[str[i] - 'a']++;
    }


    for (int i = 0; i < 26; i++)
    {
        res[i] = (char_hash[i]+'0');
    }
}

vector<vector<string>> groupAnagrams(vector<string> &strs)
{
    vector<vector<string>> res;
    unordered_map<string,int> ump;
    string hashStr ;
    hashStr.resize(26,0);
    int idx;

    for(int i = 0;i<strs.size();i++)
    {
        get_hashstr(strs[i],hashStr);

        if(ump.find(hashStr) == ump.end())
        {
            idx = res.size();
            ump[hashStr] = res.size();
            res.push_back({});
        }else
        {
            idx = ump[hashStr];
        }

        res[idx].push_back(strs[i]);
    }

    return res;
}

int main()
{
    return 0;
}