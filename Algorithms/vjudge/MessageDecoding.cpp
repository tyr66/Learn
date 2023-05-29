#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void generateMap(unordered_map<string, char>& ump, const string& head)
{
    string str = "0";
    string mode = "1";
    int count = 1;

    for (char c : head)
    {
        ump[str] = c;

        int bit = count - 1;
        bool increase = true;

        while (increase)
        {
            if (str[bit] == '0') {
                str[bit] = '1';
                increase = false;
            } else {
                str[bit--] = '0';
            }
        }

        if (str == mode)
        {
            str.clear();
            count++;
            str.resize(count, '0');
            mode.resize(count, '1');
        }
    }
}

int main()
{
    string head;

    while (getline(cin, head))
    {
        if (head == "\n" || head.empty())
            continue;

        string res;
        bool is_eof = false;
        unordered_map<string, char> ump;

        generateMap(ump, head);

        char mark[3];

        while (cin >> mark[0] && cin >> mark[1] && cin >> mark[2])
        {
            if (mark[0] == '0' && mark[1] == '0' && mark[2] == '0')
                break;

            int len = (mark[0] - '0') * 4 + (mark[1] - '0') * 2 + (mark[2] - '0');

            string mode(len, 0);
            string end(len, '1');

            while (mode != end)
            {
                for (int i = 0; i < len; i++)
                    cin >> mode[i];

                if (ump.find(mode) != ump.end())
                    res.push_back(ump[mode]);
            }
        }

        cout << res << endl;
    }


    return 0;
}
