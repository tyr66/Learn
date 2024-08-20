#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX_N = 18;
unsigned long long maxArr[MAX_N];
unsigned long long minArr[MAX_N];
int arr[MAX_N];

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    int id = 0;

    while (cin >> N)
    {
        memset(maxArr, 0, sizeof(maxArr));
        memset(minArr, 0, sizeof(minArr));

        for (int i = 0; i < N; i++)
            cin >> arr[i];

        if (arr[0] > 0)
            maxArr[0] = arr[0];
        else 
            minArr[0] = abs(arr[0]);

        unsigned long long res = max((unsigned long long)0, maxArr[0]);

        for (int i = 1; i < N; i++)
        {
            if (arr[i] > 0) {
                maxArr[i] = max((unsigned long long)arr[i], maxArr[i - 1] * arr[i]);
                minArr[i] = minArr[i - 1] * arr[i];
            } else {
                maxArr[i] = minArr[i - 1] * abs(arr[i]);
                minArr[i] = max(maxArr[i - 1] * abs(arr[i]), (unsigned long long)abs(arr[i]));
            }

            if (res < maxArr[i])
                res = maxArr[i];
        }

        printf("Case #%d: The maximum product is %llu.\n\n", ++id, res);
    }

    return 0;
}
