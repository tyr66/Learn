#include <iostream>
#include <vector>
using namespace std;

const char HAS_ARRIVE = '.';

int dirs[] = {0, 1, 0, -1, 1, 0, -1, 0};

bool backtrace(vector<vector<char>> &m, int r, int c, string &word, int idx)
{

    if (idx >= word.size())
        return true;

    bool res = false;
    char save = m[r][c];

    m[r][c] = HAS_ARRIVE;

    for (int k = 0; k < 8 && !res; k += 2)
    {
        int i = r + dirs[k];
        int j = c + dirs[k + 1];

        if (i < 0 || i >= m.size())
            continue;
        if (j < 0 || j >= m[0].size())
            continue;
        if (m[i][j] == HAS_ARRIVE || m[i][j] != word[idx])
            continue;

        res |= backtrace(m, i, j, word, idx + 1);
    }

    m[r][c] = save;

    return res;
}

bool hasPath(vector<vector<char>> &matrix, string word)
{
    if (matrix.size() == 0)
        return word.size() == 0;

    int row = matrix.size();
    int col = matrix[0].size();
    bool res = false;

    for (int i = 0; i < row&&!res; i++)
    {
        for (int j = 0; j < col&&!res; j++)
        {   
            if(matrix[i][j] == word[0])
            {
                res|=backtrace(matrix,i,j,word,1);
            }
        }
    }

    return res;
}

int main()
{

    return 0;
}