#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int N;
    cin >> N;

    while (N-- > 0)
    {
        getline(cin, str);

        if (str.empty())
        {
            N++;
            continue;
        }

        int score = 0;
        int count = 0;
        for (char c : str)
        {
            if (c == 'O') {
                score += ++count;
            }else {
                count = 0;
            }
        }

        cout << score << endl;

    }
    return 0;
}
