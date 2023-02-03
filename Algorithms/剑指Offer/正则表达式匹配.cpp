#include <iostream>
#include <vector>
using namespace std;

bool dp[27][27];

 char get_char(string& str, int idx)
{
    return idx < 1 ? ' ' : str[idx - 1];
}

 bool isSame(char a,char b)
{
    return a == b || a == '.' || b == '.';
}

bool match(string str, string pattern)
{
    if (pattern.size() == 0)
        return str.size() == 0;

    dp[0][0] = true;

    for (int j = 1; j <= pattern.size(); j++)
    {
        if (get_char(str, 0) == get_char(pattern, j))
            dp[0][j] = dp[0][j - 1];
        else if (get_char(pattern, j) == '*')
            dp[0][j] = dp[0][j - 2];
    }

    for (int i = 1; i <= str.size(); i++)
    {
        char a = get_char(str, i);

        for (int j = 1; j <= pattern.size(); j++)
        {
            char b = get_char(pattern, j);

            if (isSame(a,b))
            {
                dp[i][j] |= dp[i - 1][j - 1];
            }
            else if (b == '*')
            {
                //分为三种情况，1.一个也不取，2.消除前一个字符 3.取n个
                dp[i][j] = dp[i][j - 1] || (j - 2 >= 0 && dp[i][j - 2])||(isSame(a,get_char(pattern,j-1)) && (dp[i - 1][j - 1]||dp[i-1][j]));
            }
        }
    }

    return  dp[str.size()][pattern.size()];
}

void print_dp(int r,int c)
{
    for (int i = 0; i <= r; i++)
    {
        for (int j = 0; j <= c; j++)
        {

            if (dp[i][j])
                cout << "1 ";
            else
                cout << "0 ";

        }
        cout << endl;
    }
}

void test()
{
    string str = "abc";
    string pattern = ".*";

    match(str,pattern);
    print_dp(str.size(),pattern.size());
}

int main()
{
    test();
    return 0;
}