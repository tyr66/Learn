#include <iostream>
#include <iomanip>

using namespace std;

char puzzle[10][10];
int number[10][10];

int main()
{
    int N, M;
    int count = 1;

    while (cin >> N)
    {
        if (N == 0)
            break;
        cin >> M;


        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                cin >> puzzle[i][j];
            }
        }

        for (int i = 0, idx = 1; i < N; i++)
        {
            for (int j = 0; j < M; j++)
            {
                if (puzzle[i][j] == '*' )
                    continue;

                if (i - 1 < 0 || j - 1 < 0)
                    number[i][j] = idx++;
                else if (puzzle[i][j - 1] == '*' || puzzle[i - 1][j] == '*')
                    number[i][j] = idx++;
            }
        }

        if (count > 1)
            cout << endl;

        printf("puzzle #%d:\n", count++);
        printf("Across\n");

        int n = 0;

        for (int i = 0, j = 0; i < N; )
        {

            while (j < M && (puzzle[i][j] == '*' || number[i][j] == 0)) j++;

            if (j >= M)
            {
                j = 0; i++;
                continue;
            }

            cout << setw(3) << number[i][j] << '.';
 
            while (j < M && puzzle[i][j] != '*') cout << puzzle[i][j++];

            cout << endl;

        }

        printf("Down\n");

        for (int r = 0, c = 0; r < N; )
        {
            while (c < M) 
            {
                if (r - 1 < 0 && puzzle[r][c] != '*')
                    break;
                if (r - 1 >= 0 && puzzle[r - 1][c] == '*'&& puzzle[r][c] != '*')
                    break;

                c++;
            }

            if (c >= M)
            {
                c = 0;
                r++;
                continue;
            }

            cout << setw(3) << number[r][c] << '.' ;

            int i = r;

            while (i < N && puzzle[i][c] != '*') cout << puzzle[i++][c];

            cout << endl;
            c++;
        }

    }
    return 0;
}
