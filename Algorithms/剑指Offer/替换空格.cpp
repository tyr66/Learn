#include <iostream>
#include <string>
using namespace std;

string replaceSpace(string s)
{
    string res;
    int spaceCount = 0;

    for (int i = 0; i < s.size(); i++)
        if (s[i] == ' ')
            spaceCount++;

    int newLen = s.size() + spaceCount * 2;
    
    res.resize(newLen);

    int p = 0;

    for(int i = 0;i<s.size();i++)
    {
        if(s[i] == ' ')
        {
            res[p++] = '%';
            res[p++] = '2';
            res[p++] = '0';

        }else
        {
            res[p++] = s[i];
        }
    }

    return res;
}

int main()
{

    return 0;
}