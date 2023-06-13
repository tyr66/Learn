#include <iostream>
#include <string>
using namespace std;

int get_length(string& a, string& b)
{

    bool is_find = true;
    int len = a.size();

    for (int i = 0; i < a.size(); i++)
    {
        is_find = true;
        len = a.size();

        for (int j = 0; j < b.size(); j++)
        {
            if (i + j < a.size() && (a[i + j] - '0') + (b[j] - '0') > 3)
            {
                is_find = false;
                break;
            }

            if (i + j >= a.size())
            {
                len = a.size() + b.size() - j;
                break;
            }
        }

        if (is_find)
        {
            return len;
        }
    }

    return a.size() + b.size();
}

int main()
{
    string a, b;

    while (cin >> a && cin >> b)
    {
        cout << min(get_length(a, b), get_length(b, a)) << endl;
    }
    return 0;
} 
