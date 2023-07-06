#include <iostream>
#include <string>
#include <string.h>

using namespace std;

const int MAX_SZ = 200 + 10;
char input[MAX_SZ][MAX_SZ];
int N;

bool is_node(char c)
{
    return c != '-' && c != '|' && c != ' ' && c != '\n' /* && c != '#' */;
}

bool has_child(int i, int j)
{
    return input[i + 1][j] == '|';
}

void get_range(int i,int j, int &lo, int &hi)
{
    lo = hi = j; i += 2;
    while (lo >= 0 && input[i][lo] == '-') lo--;
    while (hi < MAX_SZ && input[i][hi] == '-') hi++;

    lo++;hi--;
}

void solve(int i, int lo, int hi, string&res)
{
    res.push_back('(');

    for (int k = lo; input[i][k] != 0 && k <= hi && i <= N; k++)
    {
        if (is_node(input[i][k]))
        {
            res.push_back(input[i][k]);
            if (has_child(i, k)) {
                int next_lo, next_hi;
                get_range(i, k, next_lo, next_hi);
                solve(i + 3, next_lo, next_hi, res);
            }else {
                res.push_back('('); res.push_back(')');
            }
        }
    }

    res.push_back(')');
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    fgets(input[0], MAX_SZ, stdin);
    sscanf(input[0], "%d", &T);

    while (T-- > 0)
    {
        memset(input, 0, sizeof(input));

        for (N = 1; ; N++){
            fgets(input[N], MAX_SZ, stdin);

            if (input[N][0] == '#')
                break;
        }
        string res;
        N--;
        solve(1, 0, strlen(input[1]), res);
        cout << res << endl;

    }

    return 0;
}
