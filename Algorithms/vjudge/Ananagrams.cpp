#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    string str;
    map<string,vector<string>> dict;
    set<string> wordSet;

    while (cin >> str && str != "#")
    {
        string tmp = str;

        for (int i = 0; i < tmp.size(); i++)
            tmp[i] = tolower(tmp[i]);

        sort(tmp.begin(), tmp.end());
        dict[tmp].push_back(str);
    }

    for (auto it : dict)
    {
        if (it.second.size() == 1) {
            wordSet.insert(it.second[0]);
        }
    }

    for (auto word : wordSet) {
        cout << word << endl;
    }

    return 0;
}
