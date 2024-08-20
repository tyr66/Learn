#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

#define GETI(i) ('8' - (i) + 1)
#define GETJ(j) ((j) - 'a' + 1)

const int MAX_R = 10;
const int MAX_C = 10;
int board[MAX_R][MAX_C];
bool visited[MAX_R][MAX_C];
int movei[8] = {1, -1, 2, -2, 1, -1, 2, -2};
int movej[8] = {2, 2, 1, 1, -2,-2, -1, -1};

int bfs(int ori_i, int ori_j, int tar_i, int tar_j)
{
    // cout << ori_i << " " << ori_j << ", :" << tar_i << " " << tar_j << endl;
    if (ori_i == tar_i  && ori_j == tar_j)
        return 0;

    memset(visited, 0, sizeof(visited));
    queue<int> que;
    que.push(ori_i);que.push(ori_j);
    visited[ori_i][ori_j] = true;
    int cnt = 2;
    int path_cnt = 0;

    while (!que.empty())
    {
        int i = que.front(); que.pop();
        int j = que.front(); que.pop();
        cnt-=2;


        for (int k = 0; k < 8; k++) {
            int ni = i + movei[k];
            int nj = j + movej[k];

            // printf("%d, %d -> %d %d\n", i, j, ni, nj);

            if (ni < 1 || ni > 8 || nj < 1 || nj > 8) continue;
            if (ni == tar_i && nj == tar_j) return path_cnt + 1;
            if (visited[ni][nj]) continue;

            que.push(ni); que.push(nj);
            visited[ni][nj] = true;
        }

        if (cnt == 0) {
            cnt = que.size();
            path_cnt++;
        }
    }

    return -1;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char ori_i,ori_j;
    char tar_i, tar_j;

    while (cin >> ori_j >> ori_i >> tar_j >> tar_i)
    {
        int res = bfs(GETI(ori_i), GETJ(ori_j), GETI(tar_i), GETJ(tar_j));
        printf("To get from %c%c to %c%c takes %d knight moves.\n", ori_j, ori_i, tar_j, tar_i, res);
    }

    return 0;
}
