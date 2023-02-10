#include <iostream>
#include <vector>
using namespace std;

int GetUglyNumber_Solution(int index)
{
    if(index == 0)
    return 0;
    int *uglyArr = new int[index + 1];
    uglyArr[1] = 1;
    int *uglyArrMult2 = uglyArr;
    int *uglyArrMult3 = uglyArr;
    int *uglyArrMult5 = uglyArr;
    int currIdx = 2;

    while (currIdx <= index)
    {
        int min_value = min(min(*uglyArrMult2 * 2, *uglyArrMult3 * 3), *uglyArrMult5 * 5);
        uglyArr[currIdx] = min_value;

        while (*uglyArrMult2 * 2 <= min_value)
            uglyArrMult2++;
        while (*uglyArrMult3 * 3 <= min_value)
            uglyArrMult3++;
        while (*uglyArrMult5 * 5 <= min_value)
            uglyArrMult5++;
        currIdx++;
    }
    int res = uglyArr[index];
    delete[] uglyArr;
    return res;
}

int main()
{
    std::cout << "skldf" << std::endl;

    return 0;
}
