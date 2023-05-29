#include <iostream>
#include <string.h>
using namespace std;

#define PALLET_CNT 6

int w[PALLET_CNT];
int h[PALLET_CNT];
bool vis[PALLET_CNT];
int pair_w[3];
int pair_h[3];

/*
 * 找出三个不同的面, 然后判断第一和第二个面组出的面是否和第三个面相等
 * */

int main()
{
    int n = 0;

    while (cin >> w[n] && cin >> h[n])
    {
        if (++n < PALLET_CNT)
            continue;

        memset(vis, 0, sizeof(vis));

        int pair_cnt = 0;

        n = 0;

        for (int i = 0; i < PALLET_CNT; i++)
        {
            if (vis[i])
                continue;

            for (int j = 0; j < PALLET_CNT; j++)
            {
                if (i == j || vis[j])
                    continue;

                if (w[i] == w[j] && h[i] == h[j]) {
                    vis[i] = vis[j] = true;
                    pair_w[pair_cnt] = w[i];
                    pair_h[pair_cnt] = h[i];
                    pair_cnt++;
                    break;
                } else if (w[i] == h[j] && h[i] == w[j]) {
                    vis[i] = vis[j] = true;
                    pair_w[pair_cnt] = w[i];
                    pair_h[pair_cnt] = h[i];
                    pair_cnt++;
                    break;
                }
            }
        }

        if (pair_cnt != 3)
        {
            cout << "IMPOSSIBLE" << endl;
            continue;
        }

        if (pair_w[0] == pair_w[1] || pair_w[0] == pair_h[1])
        {
            // 第二块板可能需要旋转
            if (pair_w[0] == pair_h[1])
                swap(pair_w[1], pair_h[1]);

            if (pair_w[2] == pair_h[0] && pair_h[2] == pair_h[1])
            {
                cout << "POSSIBLE" << endl;
                continue;
            }

            if (pair_h[2] == pair_h[0] && pair_w[2] == pair_h[1])
            {
                cout << "POSSIBLE" << endl;
                continue;
            }
        } 

        if (pair_h[0] == pair_w[1] || pair_h[0] == pair_h[1]) {

            // 第二块板可能需要旋转
            if (pair_h[0] == pair_h[1])
                swap(pair_w[1], pair_h[1]);
            
            if (pair_w[2] == pair_w[0] && pair_h[2] == pair_h[1])
            {
                cout << "POSSIBLE" << endl;
                continue;
            }

            if (pair_h[2] == pair_w[0] && pair_w[2] == pair_h[1])
            {
                cout << "POSSIBLE" << endl;
                continue;
            }
        }

        cout << "IMPOSSIBLE" << endl;

    }
    return 0;
}
