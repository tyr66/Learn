#include <iostream>
using namespace std;

int res[10001][10];

int main()
{
    int N;
    cin >> N;

    int max_vaild = 0;

    while (N-- > 0)
    {
        int n;
        cin >> n;


        for (int i = max_vaild + 1; i <= n; i++)
        {
            int m = i;
            while (m > 0)
            {
                res[i][m % 10]++;
                m /= 10;
            }

            for (int j = 0; j < 10; j++)
            {
                res[i][j] += res[i - 1][j];
            }
        }

        if (max_vaild < n)
            max_vaild = n;

        for (int i = 0; i < 10; i++)
            if (i == 9)
                cout << res[n][i] << endl;
            else 
                cout << res[n][i] << " "; 
    }
    return 0;
}
