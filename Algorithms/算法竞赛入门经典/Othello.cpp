#include <iostream>

using namespace std;

#define MAX_ROW 8
#define MAX_COL 8

char board[MAX_ROW + 1][MAX_COL + 1];

int dir[] = {0, 1, 0, -1, 1, 0, -1, 0, 1, 1, 1, -1, -1, 1, -1, -1};

void count_board(int * w_cnt, int *b_cnt)
{
    int w = 0, b = 0;

    for (int i = 1; i <= MAX_ROW; i++)
    {
        for (int j = 1; j <= MAX_COL; j++)
        {
            if (board[i][j] == 'B')
                b++;
            else if (board[i][j] == 'W')
                w++;
        }
    }

    *w_cnt = w;
    *b_cnt = b;
}

int is_legal(int r, int c, char color)
{
    if (board[r][c] != '-')
        return false;

    int cnt = 0;
    bool end = false;
    int res = 0;
    int mask = 1;

    for (int k = 0; k < sizeof(dir) / sizeof(int) ; k+=2)
    {
        int i = r + dir[k], j = c + dir[k + 1];
        cnt = 0;
        end = false;

        while (i > 0 && i < MAX_ROW && j > 0 && j < MAX_COL)
        {

            if (board[i][j] == color) {
                end = true;
                break;
            } else if (board[i][j] == '-') {
                cnt = 0;
                break;
            } else {
                cnt++;
            }

            i += dir[k];
            j += dir[k + 1];

        }

        if (cnt != 0 && end) {
            res = res | mask;
        }


        mask = mask << 1;
    }

    return res;
}

void list_move(char cur_player)
{
    int cnt = 0;

    for (int i = 1; i <= MAX_ROW; i++)
    {
        for (int j = 1; j <= MAX_COL; j++)
        {
            if (is_legal(i, j, cur_player)) {

                if (cnt == 0)
                    printf("(%d,%d)", i,j);
                else 
                    printf(" (%d,%d)", i,j);

                cnt++;
            }
        }
    }

    if (cnt == 0) 
        printf("No legal move.\n");
    else 
        printf("\n");

}

char move(char cur_player)
{
    char char_r,char_c;
    cin >> char_r >> char_c;

    int r = char_r - '0';
    int c = char_c - '0';

    if (!is_legal(r, c, cur_player))
        cur_player = cur_player == 'B' ? 'W' : 'B';

    int legaldir = is_legal(r, c, cur_player);

    board[r][c] = cur_player;

    for (int k = 0; k < sizeof(dir) / sizeof(int); k+=2, legaldir = legaldir >> 1)
    {
        if ((legaldir & 1) == 0)
            continue;

        int i = r + dir[k], j = c + dir[k + 1];

        while (board[i][j] != cur_player) {
            board[i][j] = cur_player;
            i += dir[k];
            j += dir[k + 1];
        }
    }

    int w_cnt = 0, b_cnt = 0;
    count_board(&w_cnt, &b_cnt);

    printf("Black - %2d White - %2d\n", b_cnt, w_cnt);

    return cur_player = cur_player == 'B' ? 'W' : 'B';
}


int main()
{
    int N;
    cin >> N;

    while (N-- > 0)
    {
        for (int i = 1; i <= MAX_ROW; i++)
        {
            for (int j = 1; j <= MAX_COL; j++)
            {
                cin >> board[i][j];
            }
        }

        char cur_player, cmd;
        cin >> cur_player;

        while (cin >> cmd && cmd != 'Q')
        {
            switch(cmd)
            {
                case 'L':
                    list_move(cur_player);
                    break;

                case 'M':
                    cur_player = move(cur_player);
                    break;
            }
        }

        for (int i = 1; i <= MAX_ROW; i++)
        {
            for (int j = 1;  j <= MAX_COL; j++)
            {
                cout << board[i][j];
            }
            cout << endl;
        }

        if (N != 0)
        cout << endl;
    }

    return 0;
}
