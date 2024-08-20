#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 16;
int arr[MAX_N + 1];
bool isUse[MAX_N + 1];
bool is_prime[MAX_N * 2 + 1];
int N;
int idx=1;

void generate_prime()
{
    int len = MAX_N * 2;
    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i <= len; i++) {
        if (is_prime[i]) {

            for (int j = 2; j * i <= len; j++) {
                is_prime[j * i] = false;
            }

        }
    }
}

void slove(int k)
{
    if (k == N) {
        for (int i = 0; i < N; i++)
            if (i == 0) cout << arr[i];
            else cout << " " << arr[i];
        cout << endl;
        return;
    }

    for (int i = 2; i <= N; i++) {
        if (!isUse[i] && is_prime[arr[k - 1] + i]) {

            if ((k + 1) % N == 0) {
                if (is_prime[i + 1]) {
                    arr[k] = i;
                    isUse[i] = true;
                    slove(k + 1);
                    isUse[i] = false;
                }
            } else {

                arr[k] = i;
                isUse[i] = true;
                slove(k + 1);
                isUse[i] = false;
            }
        }
    }

}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    generate_prime();
    while (cin >> N)
    {
        memset(arr, 0, sizeof(arr));
        memset(isUse, 0, sizeof(isUse));

        arr[0] = 1; isUse[1] = true;

        if (idx != 1)
            cout << endl;
        printf("Case %d:\n", idx++);
        slove(1);


    }


    return 0;
}
