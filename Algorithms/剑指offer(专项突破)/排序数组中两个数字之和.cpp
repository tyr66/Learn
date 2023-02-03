#include <iostream>
#include <vector>
using namespace std;

vector<int> twoSum(vector<int> &numbers, int target)
{
    vector<int> res;

    int left = 0, right = numbers.size() - 1;

    while (left < right)
    {
        int sum = numbers[left] + numbers[right];

        if (sum == target)
            break;
        else if (sum > target)
            right--;
        else
            left++;
    }

    if (left < right)
    {
        res.push_back(left);
        res.push_back(right);
    }

    return res;
}

int main()
{

    return 0;
}