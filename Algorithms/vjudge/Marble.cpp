#include <iostream>
#include <algorithm>

using namespace std;

int arr[10000];
int que[10000];

int main()
{
    int N, Q;
    int cnt = 1;

    while (cin >> N >> Q && N != 0 && Q != 0)
    {
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < Q; i++)
            cin >> que[i];

        sort(arr, arr + N);

        printf("CASE# %d:\n", cnt++);

        for (int i = 0; i < Q; i++)
        {
            int idx = lower_bound(arr, arr + N, que[i]) - arr;


            if (idx != N && arr[idx] == que[i]) {
                printf("%d found at %d\n", que[i], idx + 1);
            }else {
                printf("%d not found\n", que[i]);
            }
        }
    }

    return 0;
}
