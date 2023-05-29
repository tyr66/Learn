#include<iostream>
#include <iomanip>
using namespace std;

bool dole_queue[22];

int main()
{
    int N, K, M;


    while (cin >> N && cin >> K && cin >> M)
    {
        if (N == 0 && K ==0 && M == 0)
            break;

        int i = 1, j = N;
        int count = N;

        for (int k = 1; k <= N; k++)
            dole_queue[k] = true;

        while (count > 0)
        {
            int k = 0;

            while (k < K) {
                if (dole_queue[i]) k++;
                i = i + 1 > N ? 1 : i + 1;
            }

            k = 0;

            while (k < M) {
                if (dole_queue[j]) k++;
                j = j - 1 <= 0 ? N : j - 1;
            }

            i = i - 1 <= 0 ? N : i - 1;
            j = j + 1 > N ? 1 : j + 1;

            if (i == j) {
                cout << setw(3) << i;
                count -= 1;
            } else {
                cout << setw(3) << i << setw(3) << j;
                count -= 2;
            }

            dole_queue[i] = dole_queue[j] = false;

            if (count != 0)
                cout <<',';
        }

        cout << endl;
    }

    return 0;
}
