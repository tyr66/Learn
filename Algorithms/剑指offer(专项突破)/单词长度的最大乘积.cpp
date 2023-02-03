#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
时间复杂度：O(L+N^2),L为string数组所有字符的个数，N为string数组的长度
*/

int maxProduct(vector<string> &words)
{
    vector<int> mask;
    mask.resize(words.size(), 0);
    int length = words.size();

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < words[i].size(); j++)
        {
            mask[i] = mask[i] | (1 << (words[i][j] - 'a'));
        }
    }

    unsigned long long res = 0;
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            if (!(mask[i] & mask[j]))
            {
                unsigned long long value = words[i].size() * words[j].size();
                res = max(res, value);
            }
        }
    }

    return static_cast<int>(res);
}

int main()
{

    return 0;
}