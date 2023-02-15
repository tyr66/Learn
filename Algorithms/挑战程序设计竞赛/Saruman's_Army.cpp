#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];

int main()
{
    int range, N;

    while (cin >> range >> N)
    {
        if (range < 0 || N < 0)
            break;

        int left = -1;
        int count = 0;
        for (int i = 0; i < N; i++)
        {
            cin >> arr[i];
        }

        sort(arr, arr + N);

        left = 0;

        while (left < N)
        {
            int i = left;

            while (i < N && arr[i] - range <= arr[left])
            {
                i++;
            }

            int j = i - 1;

            count++;

            while (j < N&& arr[i - 1] + range >= arr[j])
            {
                j++;
            }

            left = j;

        }



        cout << count<< endl;
    }

    return 0;
}
