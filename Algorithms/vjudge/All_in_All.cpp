#include <iostream>
#include <string>

using namespace std;

int main()
{
    string a, b;

    while (cin >> a && cin >> b)
    {
        int i = 0, j = 0;

        while (j < b.size() && i < a.size())
        {
            if (b[j] == a[i])
                i++;
            j++;
        }

        if (i == a.size())
            cout << "Yes\n";
        else 
            cout << "No\n";
    }

    return 0;
}
