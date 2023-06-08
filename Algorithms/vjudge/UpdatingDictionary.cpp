#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>

using namespace std;

struct Valeu
{
    string oldV;
    string newV;

public:
    Valeu()
    {
        oldV = "";
        newV = "";
    }
};

void getDictionary(string& str, map<string, Valeu> &mp, bool isOld)
{
    for (auto& c : str)
        if (c == '{' || c == '}' || c == ',' || c == ':') c = ' ';
    
    stringstream input(str);
    string key, val;

    while (input >> key >> val) {

        if (isOld)
            mp[key].oldV = val;
        else 
            mp[key].newV = val;
    }
}

void print_Set(set<string>& st)
{
    int i = 0;
    for (auto s : st) {
        if (i == 0)
            cout << s;
        else
            cout << ',' << s ;
        i++;
    }
    cout << endl;
}

int main()
{
    freopen("output.txt", "w", stdout);
    int T;
    map<string, Valeu> mp;

    set<string> addKey;
    set<string> deleteKey;
    set<string> alertKey;

    cin >> T;

    while (T-- > 0)
    {
        string str;
        mp.clear();
        addKey.clear();
        deleteKey.clear();
        alertKey.clear();

        cin >> str;
        getDictionary(str, mp, true);
        cin >> str;
        getDictionary(str, mp, false);

        for (auto p : mp)
        {
            if (p.second.newV == "") {
                deleteKey.insert(p.first);
            } else if (p.second.oldV  == "") {
                addKey.insert(p.first);
            } else if (p.second.newV != p.second.oldV) {
                alertKey.insert(p.first);
            }
        }

        if (addKey.empty() && deleteKey.empty() && alertKey.empty()) {
            cout << "No changes" << endl;
        } else {
            
            if (!addKey.empty()) {
                cout << "+";
                print_Set(addKey);
            }

            if (!deleteKey.empty()) {
                cout << "-";
                print_Set(deleteKey);
            }

            if (!alertKey.empty()) {
                cout << "*";
                print_Set(alertKey);
            }
        }

        cout << endl;

    }


    return 0;
}