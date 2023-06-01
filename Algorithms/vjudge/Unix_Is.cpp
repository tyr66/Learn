#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX_COL_NUM = 60;

void print(const string&s, int n, char c)
{
    cout << s;

    for (int i = 0; i < n - s.size(); i++) {
        cout << ' ';
    }

}

int main()
{
    string str;
    int N;
    vector<string> file_name;
    freopen("output.txt", "w", stdout);

    while (cin >> N)
    {
        file_name.clear();
        int max_size = -1;
        int col, row;

        for (int i = 0; i < N; i++) {
            cin >> str;
            file_name.push_back(str);
            max_size = max((int)str.size(), max_size);
        }

        sort(file_name.begin(), file_name.end());
        col = 62 / (2 + max_size);
        row = (file_name.size() - 1) / col + 1;

        print("", 60, '-');

        cout << endl;

        for(int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                int idx = i + j * row;

                if (idx >= file_name.size())
                    break;
                
                if (j != col - 1)
                print(file_name[idx], max_size + 2, ' ');
                else 
                print(file_name[idx], max_size, ' ');
            }

            cout << endl;
        }
    }

    return 0;
}