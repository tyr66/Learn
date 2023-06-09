#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <vector>

using namespace std;

struct Record{
    int pageID;
    int rowID;
};

bool operator<(const Record&a, const Record&b)
{
    if (a.pageID == b.pageID)
        return a.rowID < b.rowID;
    return a.pageID < b.pageID;
}

vector<string> pages[101];

void show_str(set<Record>& res, bool is_sep)
{
        if (res.empty())  {
        cout << "Sorry, I found nothing." << endl << "==========" << endl;
        return;
    }
        
    bool is_first = true;
    int pageID = res.begin().operator*().pageID;

    for (auto& record : res) 
    {
        if (is_first) {
            cout << pages[record.pageID][record.rowID] << endl;
            is_first = false;
        }
        else {
            if (!is_sep || (is_sep && pageID != record.pageID)) {
                cout << "----------" << endl;
                pageID = record.pageID;
            }

            cout << pages[record.pageID][record.rowID] << endl;
        }
    }

    cout << "==========" << endl;
}

void find_str(map<string, set<Record>>&wordRecord, const string& tar) 
{

    auto& res =  wordRecord[tar];

    show_str(res, true);
}

void find_or_str(map<string, set<Record>>& wordRecord, const string&a, const string&b)
{
    if (wordRecord.count(a) == 0)
    {
        find_str(wordRecord, b);
        return;
    }

    if (wordRecord.count(b) == 0)
    {
        find_str(wordRecord, a);
        return;
    }


    set<Record> records;
    auto& a_record = wordRecord[a];
    auto& b_record = wordRecord[b];
    records.insert(a_record.begin(), a_record.end());
    records.insert(b_record.begin(), b_record.end());
    show_str(records, true);
}

void find_and_str(map<string,set<Record>>& wordRecord, const string&a, const string&b)
{
    set<Record> records;
    set<int> a_pages;
    set<int> pages;
    auto& a_records = wordRecord[a];
    auto& b_records = wordRecord[b];


    for (auto& r : wordRecord[a]) {
        a_pages.insert(r.pageID);
    }

    for (auto&r : wordRecord[b]) {
        if (a_pages.count(r.pageID))
            pages.insert(r.pageID);
    }

    for (auto& r : a_records) {
        if (pages.count(r.pageID))
            records.insert(r);
    }

    for (auto& r: b_records) {
        if (pages.count(r.pageID))
            records.insert(r);
    }
    
    show_str(records, true);
}

void find_not_str(map<string, set<Record>>& wordRecord, const string& a, int N)
{
    set<int> exincludeID;

    if (wordRecord.count(a))
    {
        auto& records = wordRecord[a];

        for (auto&r : records) {
            exincludeID.insert(r.pageID);
        }
    }

    bool is_first = true;

    for (int i = 0; i < N; i++)
    {
        if (exincludeID.count(i))
            continue;
        
        if (is_first) {
            is_first = false;
        } else {
            cout << "----------" << endl;
        }

        for(auto& str : pages[i]) {
            cout << str << endl;
        }
    }

    if (is_first)
        cout << "Sorry, I found nothing." << endl;

    cout << "==========" << endl;
}

int main()
{
    freopen("output.txt", "w", stdout);

    map<string,set<Record>> wordRecord;

    int T;
    cin >> T;getchar();

    string str;
    for (int i = 0, j = 0; i < T; i++) {

        while (getline(cin, str) && str != "**********") {

            pages[i].push_back(str);

            for (auto &c : str)
            {
                if (!isalpha(c))
                    c = ' ';
                else 
                    c = tolower(c);
            }

            stringstream ss(str);
            string s;

            while (ss >> s) {
                wordRecord[s].insert({i, j});
            }

            j++;
        }

        j = 0;
    }

    int N;
    cin >> N;getchar();

    while(N-- > 0)
    {
        getline(cin, str);
        int i = str.find(' '), j = str.rfind(' ');

        if (i == str.npos && j == str.npos) { // A
            find_str(wordRecord, str);
        } else if (j - i == 3) {
            find_or_str(wordRecord, str.substr(0, i), str.substr(j + 1, str.size() - j - 1));
        } else if (j - i == 4) {
            find_and_str(wordRecord, str.substr(0, i), str.substr(j + 1, str.size() - j - 1));
        } else {
            find_not_str(wordRecord, str.substr(i + 1, str.size() - i - 1), T); 
        }
    }


    return 0;
}