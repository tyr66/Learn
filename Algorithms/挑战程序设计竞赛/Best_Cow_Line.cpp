#include <iostream>

using namespace std;

char arr[2001];

// 思路: 贪心算法,
// 每次选择两端头尾中最小的项,如果两端相同则查看下一个头以及下一个尾直到不相同
// 尽可能早的选到较小的那一端
int main()
{
    int n;
    while (cin >> n)
    {
        for (int i = 0 ; i < n; i++)
        {
            cin >>arr[i];
        }

        bool left = false;
        int left_idx = 0, right_idx = n - 1;
        int count = 0;
        int idx = 0;

        while (left_idx <= right_idx)
        {

            for (int i = 0; left_idx + i <right_idx - i; i++)
            {
                if (arr[left_idx + i] < arr[right_idx - i])
                {
                    left = true;
                    break;
                } else if (arr[left_idx +i] > arr[right_idx - i])
                {
                    left = false;
                    break;
                }
            }

            if (left)
                cout << arr[left_idx++];
            else 
                cout << arr[right_idx--];

            if (++count % 80 == 0)
                cout << endl;
        }

        cout << endl;
    }
    return 0;
}
