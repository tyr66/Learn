#include <iostream>
#include <map>
#include <vector>
#include <string.h>
#include <queue>
using namespace std;

map<int, int> colorMap;

struct Edge
{
    int from;
    int to;
    int color;
};

const int MAX_N = 100000 + 5;
std::vector<int> graph[MAX_N];
std::vector<Edge> edges;
std::vector<int> res;
bool vis[MAX_N];
int dist[MAX_N];

int N,M;

void cal_distance()
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0, sizeof(dist));
    queue<int> que; que.push(N);
    vis[N] = true;

    while (!que.empty())
    {
        int u = que.front(); que.pop();

        for (auto& e_idx : graph[u]) {
            auto& e = edges[e_idx];

            int v = (u == e.from) ? e.to : e.from;

            if (!vis[v]) {
                dist[v] = dist[u] + 1;
                que.push(v);
                vis[v] = true;
            }
        }
    }
}

void cal_res()
{
    vector<int> next{1};
    memset(vis, 0, sizeof(vis));

    for(int i = dist[1]; i > 0; i--)
    {
        int min_color = 0x3fffffff;

        for (auto u : next) {

            for (auto idx : graph[u]) {
                auto& e = edges[idx];
                int v = (u == e.from) ? e.to : e.from;

                if (dist[v] + 1 == dist[u] && e.color < min_color)
                    min_color = e.color;
            }
        }

        res.push_back(min_color);

        std::vector<int> tmp_next;


        for (auto u : next) {

            for (auto idx : graph[u]) {
                auto& e = edges[idx];
                int v = (u == e.from) ? e.to : e.from;

                if (dist[v] + 1 == dist[u] && e.color == min_color && !vis[v]) {
                    vis[v] = true;
                    tmp_next.push_back(v);
                }
            }
        }

        next = std::move(tmp_next);
    }
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    while (cin >> N >> M) {

        edges.clear(); res.clear();
        fill(graph,graph + N + 1, std::vector<int>());

        for (int i = 0, u, v, c; i < M; i++)
        {
            cin >> u >> v >> c;
            edges.push_back({u, v, c});
            graph[u].push_back(edges.size() - 1);
            graph[v].push_back(edges.size() - 1);
        }

        cal_distance();
        cal_res();

        // 输出最短距离
        std::cout << dist[1] << std::endl;

        if (!res.empty())
        {
            std::cout << res[0];

            for (int i = 1; i < res.size(); i++)
                std::cout << " " << res[i];

            std::cout << std::endl;
        }
    }

    return 0;
}
