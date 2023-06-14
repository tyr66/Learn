#include <iostream>

using namespace std;

const int MAX = 100000 + 5;
int nt[MAX];
int pv[MAX];
int val[MAX];

void link(int x, int y)
{
    nt[x] = y;
    pv[y] = x;
}

int main()
{
    int N, M;
    
    while (cin >> N >> M)
    {
        for (int i = 1; i <= N; i++) {
            nt[i] = i + 1;
            pv[i] = i - 1;
            val[i] = i;
        }

        nt[N] = 0; nt[0] = 1; pv[0] = N;

        char op, X, Y;

        for (int i = 1; i <= M; i++) {
            
            cin >> op;

            if (op == '4')

            if (op == '1') {
                cin >> X >> Y;
                nt[pv[X]] = nt[X];
                pv[nt[X]] = pv[X];
                nt[pv[Y]] = X;
                pv[X] = pv[Y];
                nt[X] = Y;
                pv[Y] = X;

            } else if (op == '2') {
                cin >> X >> Y;
                nt[pv[X]] = nt[X];
                pv[nt[X]] = pv[X];
                pv[nt[Y]] = X;
                nt[X] = nt[Y];
                nt[Y] = X;
                pv[X] = Y;
            } else if (op == '3') {
                swap(val[X], val[Y]);
            } else {

                for (int i = nt[0]; i != 0; i = nt[i]) {
                    link(nt[i], i);
                }
            }

        }
            
    }

    return 0;
}