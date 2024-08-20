#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int MAX_N = 1000 + 5;
double x[MAX_N], y[MAX_N], r[MAX_N];
int visited[MAX_N];
int N;
double leftBorder, rightBorder;

#define SQUARE(x) (x) * (x)

bool is_collide(int i, int j)
{
    double sqDist = SQUARE(x[i] - x[j]) + SQUARE(y[i] - y[j]);
    double sqR = SQUARE(r[i] + r[j]);
    return sqDist < sqR;
}

void caluateBorder(int i)
{
    // 和左边界相交
    if (x[i] - r[i] < 0)
    {
        double pos = y[i] - sqrt(SQUARE(r[i]) - SQUARE(x[i]));
        leftBorder = min(leftBorder, pos);
    }
    // 和右边界相交
    if (x[i] + r[i] > 1000)
    {
        double pos = y[i] - sqrt(SQUARE(r[i]) - SQUARE(1000 - x[i]));
        rightBorder = min(rightBorder, pos);
    }
}

bool dfs(int c)
{
    if (visited[c]) return false;

    visited[c] = 1;

    if (y[c] - r[c] < 0) return true; // 能从上边界连接到下边界


    for (int i = 0; i < N; i++)
    {
        if (visited[i] == 0 && is_collide(i, c) && dfs(i))
            return true;
    }

    caluateBorder(c);

    return false;
}

int main()
{
    while (cin >> N)
    {
        for (int i = 0; i < N; i++) cin >> x[i] >> y[i] >> r[i];
        memset(visited, 0, sizeof(visited));
        
        leftBorder = rightBorder = 1000;
        bool can_arrived = true;

        for (int i = 0; i < N; i++)
        {
            if (y[i] + r[i] > 1000 && dfs(i)) {
                can_arrived = false;
                break;
            }
        }

        if (!can_arrived)
            cout << "IMPOSSIBLE" << endl;
        else {
            printf("0.00 %.2lf 1000.00 %.2lf\n", leftBorder, rightBorder);
        }
    }
    return 0;
}
