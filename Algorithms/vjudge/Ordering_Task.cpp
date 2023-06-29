#include <iostream>
#include <string.h>
#include <stack>

using namespace std;

const int MAX_N = 100 + 5;
int G[MAX_N][MAX_N];
int visited[MAX_N];
int top_list[MAX_N];
int top_order;
int N, M;

bool dfs(int u)
{
    visited[u] = -1;

    for (int v = 1; v <= N; v++)
    {
        if (!G[u][v]) continue;
        if (visited[v] == -1) return false;
        if (!visited[v] && dfs(v) == false) return false;
    }

    visited[u] = 1;
    top_list[top_order--] = u;
    return true;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (cin >> N >> M && N != 0)
    {
        memset(visited, 0, sizeof(visited));
        memset(G, 0, sizeof(G));

        for (int i = 0, n, m; i < M; i++) {
            cin >> n >> m; G[n][m] = 1;
        }

        top_order = N;
        bool has_cycle = false;

        for (int u = 1; u <= N && !has_cycle; u++) {
            if (!visited[u]) {
                has_cycle = !dfs(u);
            }
        }

        if (has_cycle) {
            //cout << "has cycle" << endl;
            continue;
        }

        for (int i = 1; i <= N; i++)
            cout << top_list[i] << " " ;
        cout << endl;
    }

    return 0;
}
