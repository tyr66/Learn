#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 100 + 5;

struct Build
{
    double x,y,w,d,h;
    int id;

    bool operator < (const Build&other) const {
        return x < other.x || (x == other.x && y < other.y);
    }
};

Build builds[MAX_N];
double intervals[MAX_N * 2];
int N;

void get_input()
{
    for (int i = 0; i < N; i++)
    {
        cin >> builds[i].x >> builds[i].y >> builds[i].w >> builds[i].d >> builds[i].h;
        intervals[i * 2] = builds[i].x; intervals[i * 2 + 1] = builds[i].x + builds[i].w;
        builds[i].id = i + 1;
    }
}

bool is_cover(int id, int inter_l, int inter_r)
{
    return builds[id].x <= inter_l && inter_r <= (builds[id].x + builds[id].w);
}

bool is_show(int id, int inter_l, int inter_r)
{
    if (!is_cover(id, inter_l, inter_r))
        return false;

    // 判断是否存在排在前面且比它高的建筑物

    for (int i = 0; i < N; i++)
    {
        if (i == id) continue;

        if (is_cover(i, inter_l, inter_r) && builds[i].y < builds[id].y && builds[i].h >= builds[id].h)
            return false;
    }

    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt","w", stdout);
    int case_cnt = 1;

    while (cin >> N && N != 0)
    {
        get_input();

        sort(builds, builds + N);
        sort(intervals, intervals + N * 2);
        
        int interval_cnt = std::unique(intervals, intervals + N * 2) - intervals;

        if (case_cnt != 1)
            cout << endl;

        printf("For map #%d, the visible buildings are numbered as follows:\n%d", case_cnt++, builds[0].id);
        for (int i = 1; i < N; i++)
        {
            bool showed = false;

            for (int j = 0; j < interval_cnt - 1; j++)
            {
                if (is_show(i, intervals[j], intervals[j + 1])) {
                    showed = true; break;
                }
            }

            if (showed)
            {
                cout <<" " << builds[i].id;
            }
        }

        cout << endl ;
    }

    return 0;
}
