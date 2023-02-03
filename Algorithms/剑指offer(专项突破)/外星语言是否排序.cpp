#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isAlienSorted(vector<string> &words, string order)
{
    vector<int> char_hash(26, 0);
    int len = words.size() - 1;

    for (int i = 0; i < order.size(); i++)
        char_hash[order[i] - 'a'] = i;

    for (int i = 0, j = 0; i < len; i++)
    {
        j = 0;
        string &a = words[i];
        string &b = words[i + 1];

        while (j < a.size() && j < b.size() && char_hash[a[j]-'a'] == char_hash[b[j] - 'a'])
        {
            j++;
        }

        if (j >= b.size() && a.size() > b.size())
            return false;

        if (j < a.size() && j < b.size() && char_hash[a[j]-'a'] > char_hash[b[j] - 'a'])
            return false;
    }

    return true;
}

int main()
{
    return 0;
}