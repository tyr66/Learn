#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

bool h_edges[10][10];
bool v_edges[10][10];

bool has_square(int i, int j, int sz)
{
    bool res = true;

    for (int k = 0; k < sz && res; k++)
        res = h_edges[i][j + k];

    for (int k = 0; k < sz && res; k++)
        res = h_edges[i + sz][j + k];

    for (int k = 0; k < sz && res; k++)
        res = v_edges[i + k][j];

    for (int k = 0; k < sz && res; k++)
        res = v_edges[i + k][j + sz];

    return res;
}

int main()
{
    int N, M;
    int idx = 1;

    while (cin >> N && cin >>M)
    {

        memset(h_edges, 0, sizeof(h_edges) * sizeof(int));
        memset(v_edges, 0, sizeof(h_edges) * sizeof(int));

        for (int i = 0; i < M; i++)
        {
            char type = 0;
            int from, to;

            cin >> type >> from >> to;

            if (type == 'H')
                h_edges[from][to] = true;
            else 
                v_edges[to][from] = true;
        }

        if (idx != 1)
            printf("\n**********************************\n\n");

        printf("Problem #%d\n\n", idx++);

        bool no_square = true;

        for (int sz = 1; sz < N; sz++)
        {
            int cnt = 0;

            for (int i = 1; i <= N - sz; i++)
            {
                for (int j = 1; j <= N - sz; j++)
                {
                    if (has_square(i, j, sz))
                        cnt++;
                }
            }

            if (cnt != 0) {
                no_square = false;
                printf("%d square (s) of size %d\n", cnt, sz);
            }
        }

        if (no_square)
            printf("No completed squares can be found.\n");
    }

    return 0;
}
