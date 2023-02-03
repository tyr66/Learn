#include <iostream>
#include <vector>
using namespace std;

int move_count = 0;
int matrix[100][100];
int dirs[8] = {0, 1, 0, -1, 1, 0, -1, 0};
int g_rows, g_cols;
int g_threshold;

int decomposeNumber(int a, int b)
{
    int res = 0;

    while (a != 0 || b != 0)
    {
        if (a != 0)
        {
            res += a % 10;
            a /= 10;
        }
        if (b != 0)
        {
            res += b % 10;
            b /= 10;
        }
    }
    return res;
}

void move(int r, int c)
{
    move_count++;
    matrix[r][c] = 1;

    for (int k = 0; k < 8; k += 2)
    {
        int i = r + dirs[k];
        int j = c + dirs[k + 1];

        if (i < 0 || i >= g_rows)
            continue;
        if (j < 0 || j >= g_cols)
            continue;
        if (matrix[i][j] == 1)
            continue;
        if (decomposeNumber(i, j) > g_threshold)
            continue;

        move(i,j);
    }
}

int movingCount(int threshold, int rows, int cols)
{
    g_threshold = threshold;
    g_cols = cols;
    g_rows = rows;

    move(0,0);
    
    return move_count;
}

int main()
{
    return 0;
}