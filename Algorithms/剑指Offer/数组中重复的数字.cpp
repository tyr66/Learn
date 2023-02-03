#include <iostream>
#include <vector>
using namespace std;

/*
描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任意一个重复的数字。
例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。存在不合法的输入的话输出-1

数据范围：0\le n \le 10000 \0≤n≤10000
时间复杂度 O(n),空间复杂度O(1)
*/

int duplicate(vector<int> &numbers)
{

    if (numbers.size() <= 0)
        return -1;

    int numbersLen = numbers.size();

    for (int i = 0; i < numbersLen; i++)
    {
        if (numbers[i] < 0 || numbers[i] >= numbersLen)
            return -1;

        while (numbers[i] != i)
        {
            if (numbers[numbers[i]] == numbers[i])
                return numbers[i];

            swap(numbers[i], numbers[numbers[i]]);
        }
    }

    return -1;
}

int main()
{

    return 0;
}
