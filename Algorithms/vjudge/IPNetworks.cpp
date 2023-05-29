#include <iostream>
#include <string.h>
using namespace std;

unsigned char ipbits[1000][32];
int N;

int get_n()
{
    for (int k = 0; k < 32; k++)
    {
        for (int i = 1; i < N; i++)
        {
            if (ipbits[i][k] != ipbits[i - 1][k])
            {
                return k;
            }
        }
    }

    return 32;
}

int main()
{
    while (cin >> N)
    {
        int n;

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                cin >> n;
                getchar();

                for (int k = 7; k >= 0; k--)
                {
                    ipbits[i][j * 8 + k] = n & 1;
                    n = n >> 1;
                }
            }
        }

        int bytes[4];
        int masks[4];
        memset(bytes, 0 ,sizeof(bytes));
        memset(masks, 0, sizeof(masks));
        n = get_n();

        for (int i = 0; i < 4; i++)
        {
            int byte = 0;
            int mask = 0;
            unsigned int bit = 128;

            for (int j = 0; j < 8; j++)
            {
                if (i * 8 + j < n)
                {
                    byte += (bit * ipbits[0][i * 8 + j]);
                    mask += bit;
                }
                bit = bit >> 1;
            }

            bytes[i] = byte;
            masks[i] = mask;
        }

        printf("%d.%d.%d.%d\n", bytes[0], bytes[1], bytes[2], bytes[3]);
        printf("%d.%d.%d.%d\n", masks[0], masks[1], masks[2], masks[3]);

    }
    return 0;
}
