#include <iostream>
#include <string>
#include <vector>

using namespace std;

void generateIP(vector<string>&res, string&ip, string s, int i, int layer)
{
    if (layer == 0)
    {
        if (i == s.size())
        {
            res.push_back(ip);
        }
        return;
    }
    if (s.size() - i > layer * 3)
    {
        return;
    }

    int mark = ip.size();

    if (layer != 4)
    {
        ip.push_back('.');
    }

    if (s[i] == '0')
    {
        ip.push_back('0');
        generateIP(res, ip, s, i + 1, layer - 1);
    }else {

        int number = 0;
        int j = i;
        while (number <= 255 && j < s.size())
        {
            number = number * 10 + (s[j] - '0');
            ip.push_back(s[j]);
            j++;
            if (number <= 255)
            {
                generateIP(res, ip, s, j, layer - 1);
            }
        }
    }


    while (ip.size() != mark)
    ip.pop_back();
}

vector<string> restoreIpAddresses(string s)
{
    vector<string> res;
    string ip;
    generateIP(res, ip, s, 0, 4);
    return res;
}