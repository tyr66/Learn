#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortest[5001];
int second_shortest[5001];

// 注意双向边

// wa 数据1 不存在次短路时强行次短路
// 2 1 
// 1 2 1 
//
// wa 数据2 注意 cost == shortest[to] 的情况
// 4 6
// 1 2 1
// 1 2 5
// 1 3 2
// 2 3 2
// 2 4 1
// 2 4 6

// 时间复杂度 O(ElogV)
typedef pair<int, int> P; // first 为距离,second 为顶点编号
//
struct e 
{
    int to;
    int cost;

    e(int _to, int _cost)
    {
        to = _to;
        cost = _cost;
    }
};

struct cmp
{
    bool operator()(P&a, P&b)
    {
        return a.first > b.first;
    }
};

int main()
{
    int N, R;
    vector<vector<e>> edges;

    while (cin >> N >> R)
    {
        edges.resize(N + 1);

        for (int i = 0; i < R; i++) 
        {
            int from, to, d;
            cin >> from >> to >> d;

            edges[from].push_back(e(to, d));
            edges[to].push_back(e(from, d));
        }

        for (int i = 1; i <= N; i++)
        {
            shortest[i] = INT_MAX;
            second_shortest[i] = INT_MAX;
        }

        shortest[1] = 0;

        priority_queue<P, vector<P>, cmp> pq;

        pq.push(P(0, 1));

        while (!pq.empty())
        {
            P p = pq.top();
            pq.pop();

            if (p.first > second_shortest[p.second]) continue;

            for (int i = 0; i < edges[p.second].size(); i++)
            {

                // 需要注意等于的情况
                int cost = edges[p.second][i].cost + p.first;
                int to = edges[p.second][i].to;

                if (cost < shortest[to]) {

                    second_shortest[to] = shortest[to];
                    shortest[to] = cost;
                    pq.push(P( shortest[to], to ));

                } 
                if (cost < second_shortest[to] && cost > shortest[to]) {

                    second_shortest[to] = cost;
                    pq.push(P( second_shortest[to], to));

                }
            }
        }

        cout << second_shortest[N] << endl;
    }
    return 0;
}
