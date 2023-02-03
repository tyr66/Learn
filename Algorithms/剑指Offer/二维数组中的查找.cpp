#include <iostream>
#include <vector>
using namespace std;

/*

描述
在一个二维数组array中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。请完成一个函数，
输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
[
[1,2,8,9],
[2,4,9,12],
[4,7,10,13],
[6,8,11,15]
]
给定 target = 7，返回 true。

给定 target = 3，返回 false。

时间复杂度O(row+col),空间复杂度O(1)

*/

bool Find(int target, vector<vector<int>> array)
{
    int row = array.size();
    int col = array[0].size();

    int r = 0, c = col - 1;

    while (r >= 0 && r < row && c >= 0 && c < col)
    {
        if (array[r][c] == target)
            return true;

        if (array[r][c] > target)
            c--;
        else
            r++;
    }

    return false;
}

int main()
{

    return 0;
}