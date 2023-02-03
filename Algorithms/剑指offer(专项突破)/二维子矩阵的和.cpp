#include <iostream>
#include <vector>
using namespace std;

class NumMatrix
{
public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        if (matrix.empty() || matrix[0].empty())
        {
            row = col = 0;
            return;
        }

        row = matrix.size();
        col = matrix[0].size();
        mt.resize(matrix.size() + 1);

        for (int i = 0; i <= row; i++)
            mt[i].resize(col + 1, 0);

        for (int i = 1; i <= row; i++)
        {
            for (int j = 1; j <= col; j++)
            {
                mt[i][j] = matrix[i - 1][j - 1] + mt[i - 1][j] + mt[i][j - 1]-mt[i-1][j-1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        if (row == 0 || col == 0)
            return 0;

        row1++;
        col1++;
        row2++;
        col2++;

        if (row1 <= 0 || row1 > row || col1 <= 0 || col1 > col)
            return 0;
        if (row2 <= 0 || row2 > row || col2 <= 0 || col2 > col)
            return 0;

        return mt[row2][col2] - mt[row2][col1-1] - mt[row1-1][col2]+mt[row1-1][col1-1];
    }

private:
    vector<vector<int>> mt;
    int row;
    int col;
};

int main()
{

    return 0;
}