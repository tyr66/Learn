#include <iostream>
#include <string.h>

using namespace std;

char strs[50][1000];
int genes[5];
char res[1000];

int charToInt(char c)
{
    switch (c) {

        case 'A':
            return 0;
        case 'C':
            return 1;
        case 'G':
            return 2;
        case 'T':
            return 3;
    }

    return -1;
}

int main()
{
    int N;
    
    cin >> N;

    while (N-- > 0)
    {
        int R,C;
        cin >> R >> C;

        for (int i = 0; i < R; i++)
        {
            for (int j = 0; j < C; j++)
            {
                cin >> strs[i][j];
            }
        }


        int sum = 0;

        for (int j = 0; j < C; j++)
        {
            memset(genes, 0, sizeof(genes));

            int count = 0;
            char max_char = 0;

            for (int i = 0; i < R; i++)
            {
                int idx = charToInt(strs[i][j]);
                genes[idx]++;

                if (genes[idx] > count) {

                    count = genes[idx];
                    max_char = strs[i][j];

                } else if (genes[idx] == count) {
                    max_char = min(strs[i][j], max_char);
                }
            }

            res[j] = max_char;
            sum += R - count;
        }

        for (int j = 0; j < C; j++)
        {
            cout << res[j];
        }
        cout << endl << sum << endl;
    }


    return 0;
}
