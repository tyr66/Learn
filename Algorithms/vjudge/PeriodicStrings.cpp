#include <iostream>
#include <string>
using namespace std;

int main()
{
    int N;
    string str;
    cin >> N;

    while (N-- > 0)
    {
        cin >> str;

        int len = str.size() / 2;
        int min_periodic = str.size();
        bool is_find = false;

        for (int i = 1; i <= len; i++)
        {
            if (str.size() % i != 0)
                continue;


            is_find = true;

            for (int j = 0; j < str.size() && is_find; j+=i)
            {
                for (int k = 0; k < i && is_find; k++)
                {
                    if (str[k] != str[j + k])
                        is_find = false;
                }

            }

            if (is_find)
            {
                min_periodic = i;
                break;
            }
        }

        if (N != 0)
            cout << min_periodic << endl << endl;
        else 
            cout << min_periodic << endl;
    }
    return 0;
}
