#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <iomanip>
#include <cstring>
#include <vector>
using namespace std;

#define ROW(x) (x) - 'A'
#define COL(x) (x) - '0'

struct Edge
{
    int i;
    int j;
    int sign;
};

struct Cell
{
    int value;
    string str{""};
    bool evaluate;

    std::vector<Edge> adjList;
};

const int MAX_R = 20 + 5;
const int MAX_C = 10 + 5;

int visited[MAX_R][MAX_C];
Cell sheet[MAX_R][MAX_C];

int r,c;

bool isDigit(const string& str)
{
    for (int i = str[0] == '-' ? 1 : 0; i < str.size(); i++) {
        if (!isdigit(str[i]))
            return false;
    }

    return true;
}

void buildGraph(string& str, int i, int j)
{
    int idx;
    int sign = 1;
    while ((idx = str.find_first_of("-+")) != string::npos)
    {

        string s = str.substr(0, idx);

        if (isDigit(s)) {
            sheet[i][j].value += stoi(s) * sign;
        } else {
            sheet[i][j].adjList.push_back({ROW(s[0]), COL(s[1]), sign});
        }

        sign = str[idx] == '-' ? -1 : 1;
        str = str.substr(idx + 1, str.size() - idx -1);
    }

    if (isDigit(str)) {
        sheet[i][j].value += stoi(str) * sign;
    } else {
        sheet[i][j].adjList.push_back({ROW(str[0]), COL(str[1]), sign});
    }

}

bool dfs(int i, int j)
{
    if (visited[i][j] == 1 || visited[i][j] == 2)
        return false;

    if (sheet[i][j].evaluate)
        return true;

    visited[i][j] = 1;
    int sum = 0;
    for (auto&edge : sheet[i][j].adjList)
    {
        if (!dfs(edge.i, edge.j))
        {
            visited[i][j] = 2;
            return false;
        }

        sum += edge.sign * sheet[edge.i][edge.j].value;
    }

    sheet[i][j].value += sum;
    sheet[i][j].evaluate = true;
    visited[i][j] = 0;
    return true;
}


bool caulateSheet()
{
    bool res = true;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (visited[i][j] == 0 && !sheet[i][j].evaluate) {

                if (dfs(i, j)) {
                    sheet[i][j].evaluate = true;
                }
                else {
                    res = false;
                    sheet[i][j].evaluate = false;
                }
            }
        }
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> r >> c && r && c)
    {
        memset(visited, 0, sizeof(visited));
        memset(sheet, 0, sizeof(sheet));

        string str = "\n";
        getline(cin, str);

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {

                getline(cin, str);
                sheet[i][j].adjList.clear();
                sheet[i][j].value = 0;
                sheet[i][j].str = str;
                sheet[i][j].evaluate = false;

                if (isDigit(str)) {
                    sheet[i][j].value = stoi(str);
                    sheet[i][j].evaluate = true;
                } else {
                    buildGraph(str, i, j);
                }
            }
        }

        if (caulateSheet()) {

            cout << " ";
            for (int j = 0; j < c; j++)
                cout << setw(6) << j;
            cout << endl;

            for (int i = 0; i < r; i++) {
                cout << (char)('A' + i);
                for (int j = 0; j < c; j++)
                    cout <<setw(6) << sheet[i][j].value;
                cout << endl;
            }
        } else {

            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (!sheet[i][j].evaluate) {
                        cout << (char)('A' + i) << j << ": " << sheet[i][j].str << endl;
                    }
                }
            }
        }

        cout << endl;
    }

    return 0;
}
