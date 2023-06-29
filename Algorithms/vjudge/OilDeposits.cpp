#include <iostream>
#include <queue>

using namespace std;

const int MAX_M = 100 + 5;
const int MAX_N = 100 + 5;

char mines[MAX_M][MAX_N];
int dir[16] = { 0, 1, 0,-1, 1,0, -1,0, 1,1, 1,-1, -1,1, -1,-1 };

void bfs(int m, int n, int M, int N)
{
  queue<int> que;
  mines[m][n] = '*';
  que.push(m); que.push(n);

  while (!que.empty())
  {
    int i = que.front(); que.pop();
    int j = que.front(); que.pop();

    for (int l = 0; l < 16; l += 2)
    {
      int _i = i + dir[l];
      int _j = j + dir[l + 1];

      if (_i < 0 || _i >= M)
        continue;
      if (_j < 0 || _j >= N)
        continue;

      if (mines[_i][_j] == '@') {
        mines[_i][_j] = '*';
        que.push(_i); que.push(_j);
      }
    }
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int M, N;

  while (cin >> M && cin >> N && M != 0 && N != 0)
  {

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        cin >> mines[i][j];
      }
    }

    int cnt = 0;

    for (int i = 0; i < M; i++) {
      for (int j = 0; j < N; j++) {
        if (mines[i][j] == '@') {
          bfs(i, j, M, N);
          cnt++;
        }
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
