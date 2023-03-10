#include <iostream>
#include <string>
#include <string.h>

using namespace std;

int alphaHash[128];
int tarHash[128];


int main()
{
    string a, b;

    while (cin >> a && cin >> b)
    {
        bool is_ok = false;

        memset(alphaHash + 'A', 0, sizeof(int)*26);
        memset(tarHash + 'A', 0, sizeof(int) * 26);

        for (int i = 0; i < a.size(); i++)
        {
            tarHash[a[i]]++;
            alphaHash[b[i]]++;
        }

        for (int i = 'A'; i <= 'Z'; i++)
        {
            if (alphaHash[i] == 0)
                continue;

            is_ok = false;

            for (int j = 'A'; j <= 'Z'; j++)
            {
                if (alphaHash[i] != 0 && alphaHash[i] == tarHash[j])
                {
                    tarHash[j] = 0;
                    is_ok = true;
                    break;
                }
            }

            if (!is_ok)
                break;
        }

        if (is_ok) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }

    }

    return 0;
}
