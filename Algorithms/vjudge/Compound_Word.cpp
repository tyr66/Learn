#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    freopen("output.txt", "w", stdout);

    string word;
    set<string> strSet;
    set<string> res;

    while (cin >> word) 
        strSet.insert(word);

    for(auto str : strSet)
    {
        for (int i = 1; i < str.size(); i++)
        {
            if (strSet.count(str.substr(0, i)) && strSet.count(str.substr(i, str.size() - i)))
                res.insert(str);
        }
    }

    for (auto str : res)
        cout << str << endl;

    return 0;
}