#include <iostream>
#include <deque>
#include <string>
using namespace std;

bool is_easy(const string& str)
{
    if (str.size() == 1)
         return true;

    char mark = str[str.size() - 1];
    bool res = true;

    for (int i = str.size() - 2; i >= 0; i--)
    {
        if (str[i] == mark && i + 1 >= str.size() - i - 1) {

            int j = str.size() - 1; res = false;
            for (int k = 0; j - k > i && i - k >= 0; k++)
            {
                if (str[j - k] != str[i - k]) {
                    res = true;
                    break;
                }
            }

            if (!res)
                return false;
        }
    }

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N, L;

    // cout << is_easy("ABC") << endl;
    // cout << is_easy("ABA") << endl;
    // cout << is_easy("AA") << endl;
    // cout << is_easy("ABACABA") << endl;
    // cout << is_easy("ABCDACABCAB") << endl;
    // cout << is_easy("ABCDABCD") << endl;

    while (cin >> N >> L && N && L)
    {
        string str = "A"; N--;
        while (N != 0 && !str.empty())
        {
            bool is_find = false;

            for (int i = 0; i < L; i++) {
                str.push_back('A' + i);
                if (is_easy(str)) {
                    is_find = true;
                    break;
                }
                str.pop_back();
            }

            while (!is_find && !str.empty()) {
                int i = str[str.size() - 1] - 'A' + 1;
                str.pop_back();

                for (;i < L; i++) {
                    str.push_back('A' + i);
                    if (is_easy(str)) {
                        is_find = true;
                        break;
                    }
                    str.pop_back();
                }
            }
            N--;
        }

        for (int i = 0 , j = 0; i < str.size(); i++) {
            if (i%4 == 0 && i != 0) {
                if (++j % 16 == 0) 
                    cout << endl;
                else 
                cout << " ";
            }
            cout << str[i];
        }
        cout <<endl << str.size() << endl ;
    }

    return 0;
}
