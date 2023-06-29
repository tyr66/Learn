#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define INDEX(c) ((c) - 97)

const int NODE_SIZE = 26 + 5;

int graph[NODE_SIZE][NODE_SIZE];
int in_degree[NODE_SIZE];
int out_degree[NODE_SIZE];
bool visited[NODE_SIZE];

void init()
{
    memset(graph, 0, sizeof(graph));
    memset(in_degree, 0, sizeof(in_degree));
    memset(out_degree, 0, sizeof(out_degree));
    memset(visited, 0, sizeof(visited));
}

int dfs(int u)
{
    visited[u] = true;
    int res = 1;

    for (int v = 0; v < 26; v++)
    {
        if (graph[u][v] && !visited[v])
            res += dfs(v);
    }

    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;

    while (T-- > 0)
    {
        int N; cin >> N;
        string str;

        init();

        for (int i = 0, u, v; i < N; i++) {
            cin >> str;
            u = INDEX(str[0]); v = INDEX(str[str.size() - 1]);
            graph[u][v]++;
            graph[v][u]++;
            out_degree[u]++; in_degree[v]++;
        }

        int in_degree_cnt = 0, out_degree_cnt = 0;
        bool flag = true;
        for (int i = 0; i < 26; i++) {
            if (abs(in_degree[i] - out_degree[i]) >= 2) {
                flag = false;
                break;
            }
            if (in_degree[i] - out_degree[i] == 1) in_degree_cnt++;
            if (out_degree[i] - in_degree[i] == 1) out_degree_cnt++;
        }

        if (flag && in_degree_cnt + out_degree_cnt > 2)
            flag = false;
        if (in_degree_cnt == 2 || out_degree_cnt == 2)
            flag = false;

        if (flag) {

            for (int i = 0; i < 26; i++) {
                if (in_degree[i] || out_degree[i])
                {
                    dfs(i); break;
                }
            }

            for (int i = 0; i < 26; i++)
            {
                if ((out_degree[i] > 0 || in_degree[i] > 0) && !visited[i]) {
                    flag = false; break;
                }
            }
        }

        if (flag)
            cout << "Ordering is possible." << endl;
        else
            cout << "The door cannot be opened." << endl;

    }

    return 0;
}
