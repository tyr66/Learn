#include <iostream>
#include <vector>
using namespace std;

vector<int> printMatrix(vector<vector<int>> matrix)
{
    if(matrix.size() == 0)
    return {};

    vector<int> res;
    int top_i = 0,top_j = 0;
    int down_i = matrix.size()-1,down_j = matrix[0].size()-1;

    while(top_i<=down_i&&top_j<=down_j)
    {
        for(int i = top_i, j= top_j;j<=down_j;j++)
            res.push_back(matrix[i][j]);
        for(int i = top_i+1,j = down_j;i<=down_i;i++)
            res.push_back(matrix[i][j]);
        for(int i = down_i,j = down_j-1;j>=top_j&&top_i!=down_i;j--)
            res.push_back(matrix[i][j]);
        for(int i = down_i-1,j = top_j;i>top_i&&top_j!=down_j;i--)
            res.push_back(matrix[i][j]);

        top_i++;
        top_j++;
        down_i--;
        down_j--;
    }

    return res;
}

int main()
{

    return 0;
}