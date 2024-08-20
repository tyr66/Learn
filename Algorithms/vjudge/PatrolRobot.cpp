#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
    int i;
    int j;
    int cnt;
};

const int MAX_N = 20 + 5;
int grid[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N][MAX_N];
int N, M, K;
int movei[4] = {0,0, 1, -1};
int movej[4] = {1, -1, 0, 0};

int bfs(int i, int j)
{
    if (N == M && N == 1)
        return 0;

    memset(visited, 0, sizeof(visited));
    queue<Node> que;
    que.push({i, j, 0});
    int path_cnt = 0;
    int cnt = 1;
    visited[i][j][0] = true;

    while (!que.empty())
    {
        Node n = que.front(); que.pop();

        for (int W = 0; W < 4; W++) {
            int ni = n.i + movei[W];
            int nj = n.j + movej[W];

            if (ni < 1 || ni > N || nj < 1 || nj > M) continue;
            if (ni == N && nj == M) return path_cnt+1;
            if (visited[ni][nj][n.cnt]) continue;
            if (n.cnt + 1 > K && grid[ni][nj] == 1) continue;

            if (grid[ni][nj] == 1) {
                que.push({ni, nj, n.cnt + 1});
            } else {
                que.push({ni, nj, 0});
            }
            visited[ni][nj][n.cnt] = true;
        }

        if(--cnt == 0) {
            cnt = que.size();
            path_cnt++;
        }
    }
    
    return -1;
}

int main()
{
    freopen("input.txt", "r" ,stdin);
    freopen("output.txt", "w", stdout);
    int T; cin >> T;

    while (T-- > 0)
    {
        cin >> N >> M >> K;
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                cin >> grid[i][j];
            }
        }

        int res = bfs(1,1);

        cout << res << endl;
    }

    return 0;
}

