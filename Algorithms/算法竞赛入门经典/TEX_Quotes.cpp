#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    int count = 1;

    while (std::getline(std::cin, str))
    {
        if (str.empty())
            continue;

        for (char c : str)
        {
            if (c != '"')
            {
                cout << c;
                continue;
            }else if (count & 1){
                cout << "``";
                count++;
            } else {
                cout << "''";
                count++;
            }
        }

        cout << endl;
    }

    return 0;
}
