#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void get_permutation(vector<string> &res, string &str, int i)
{
    if (i >= str.size())
    {
        res.push_back(str);
        return;
    }

    for (int j = i; j < str.size(); j++)
    {

        if (j != i && str[i] == str[j]) //有重复字符时，跳过
            continue;

        swap(str[i], str[j]);
        get_permutation(res, str, i + 1);
        swap(str[i], str[j]);

        while (j + 1 < str.size() && str[j] == str[j + 1])
            j++;
    }
}

vector<string> Permutation(string str)
{
    vector<string> res;

    sort(str.begin(), str.end());

    get_permutation(res, str, 0);

    return res;
}

int main()
{

    return 0;
}