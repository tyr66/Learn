#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <string.h>


using namespace std;

const int MAX_ROW = (200 + 5) * 4;
const int MAX_COL = (50 + 5) * 4;

char IMG[MAX_ROW][MAX_COL];
char IMG_CPY[MAX_ROW][MAX_COL];
int dir[8] = { 1,0, -1,0, 0,1, 0,-1 };
char word[] = { 'W', 'A', 'K', 'J', 'S', 'D' };

void transiteToBitImg(char c, int i, int j)
{
  static const char* transition[] = { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
    "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111" };

  for (int k = 0; k < 4; k++)
    if (c >= '0' && c <= '9')
      IMG[i + 1][1 + j*4 + k] = transition[c - '0'][k];
    else
      IMG[i + 1][1 + j*4 + k] = transition[c - 'a' + 10][k];
}

void copy(int n, int m, int N, int M)
{
  queue<int> que;
  que.push(n); que.push(m);

  IMG[n][m] = '0';
  IMG_CPY[n][m] = '1';

  int i,j,_i, _j;

  while (!que.empty()) {
     i = que.front(); que.pop();
     j = que.front(); que.pop();

    for (int k = 0; k < 8; k++) {
       _i = i + dir[k];
       _j = j + dir[k + 1];

      if (_i < 1 || _i > N)
        continue;
      if (_j < 1 || _j > M)
        continue;

      if (IMG[_i][_j] == '1') {
        IMG[_i][_j] = '0';
        IMG_CPY[_i][_j] = '1';
        que.push(_i); que.push(_j);
      }
    }
  }
}

// char word[6] = {'W', 'A', 'K', 'J', 'S', 'D'}; 
char get_char(int cnt)
{
  return word[cnt];
}

void bfs(int n, int m, int N, int M)
{
  queue<int> que;
  que.push(n); que.push(m);

  IMG_CPY[n][m] = '1';

  int i,j,_i,_j;

  while (!que.empty()) {
    i = que.front(); que.pop();
    j = que.front(); que.pop();

    for (int k = 0; k < 8; k++) {
      _i = i + dir[k];
      _j = j + dir[k + 1];

      if (_i < 0 || _i > N + 1)
        continue;
      if (_j < 0 || _j > M + 1)
        continue;

      if (IMG_CPY[_i][_j] == '0') {
        IMG_CPY[_i][_j] = '1';
        que.push(_i); que.push(_j);
      }
    }
  }
}


int cnt_white(int N, int M)
{
  int cnt = 0;

  for (int i = 0; i <= N + 1; i++)
  {
    for (int j = 0; j <= M + 1; j++)
    {
      if (IMG_CPY[i][j] == '0') {
        cnt++;
        bfs(i, j, N, M);
      }
    }
  }

  return cnt - 1;
}

void print_IMG(int N, int M)
{
  char c;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      c = IMG[i][j];
      cout << IMG[i][j];
    }
    cout << endl;
  }
}

void printf_CPY_IMG(int N, int M)
{
  char c;
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      c = IMG_CPY[i][j];
      cout << IMG_CPY[i][j];
    }
    cout << endl;
  }
}


int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  char c;
  int N, M;
  int idx = 1;
  vector<char> res;

  while (cin >> N >> M && M != 0)
  {
    memset(IMG, 48, sizeof(IMG));
    res.clear();
    for (int i = 0; i < N; i++)
    {
      for (int j = 0; j < M; j++)
      {
        if (cin >> c && c != '0')
          transiteToBitImg(c, i, j);
      }
    }

    M *= 4; 

    //print_IMG(N, M);

    for (int i = 1; i <= N; i++) {
      for (int j = 1; j <= M; j++) {
        if (IMG[i][j] == '1') {
          memset(IMG_CPY, '0', sizeof(IMG_CPY));
          copy(i, j, N, M);

          //printf_CPY_IMG(N, M);
          int cnt = cnt_white(N, M);
          res.push_back(get_char(cnt));
        }
      }
    }

    sort(res.begin(), res.end());
    cout << "Case " << idx++ << ": ";
    for (auto c : res)
      cout << c;
    cout << endl;
  }

  return 0;
}
