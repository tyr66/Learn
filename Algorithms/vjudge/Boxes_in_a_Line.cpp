#include <iostream>
using namespace std;

const int MAX = 100000 + 5;
int nt[MAX];
int pv[MAX];

void link(int x, int y)
{
  nt[x] = y;
  pv[y] = x;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N, M;
  int case_ik = 1;

  while (cin >> N >> M)
  {
    for (int i = 1; i <= N; i++) {
      nt[i] = i + 1;
      pv[i] = i - 1;
    }

    nt[N] = 0; nt[0] = 1; pv[0] = N;

    bool isf<LeftMouse>ip = false;
    int op;
    int X, Y;

    // cout << "debug: ";
    // for (int i = nt[0]; i != 0; i = nt[i])
    //   cout << i << " ";
    // cout << endl;
    
    while (M-- > 0) {
      cin >> op;
      if (op == 4) {
        isflip = !isflip;
        continue;
      }

      cin >> X >> Y;

      if (op != 3 && isflip) op = 3 - op; // 调整方向 
      if (op == 1 && pv[Y] == X) continue;
      if (op == 2 && nt[Y] == X) continue;

      int RX = nt[X], LX = pv[X], RY = nt[Y], LY = pv[Y];

      if (op == 1) {
        link(LX, RX);link(LY, X);link(X, Y);
      } else if (op == 2) {
        link(LX, RX); link(Y, X);link(X, RY);
      } else {

        if (nt[X] == Y) {
          link(X, RY); link(LX, Y); link(Y, X);
        } else if (nt[Y] == X) {
          link(Y, RX); link(LY, X); link(X, Y);
        } else {
          link(LX, Y); link(Y, RX); link(LY, X); link(X, RY);
        }

      }  
    }

    long long res = 0;
    long long sum = 0;

    // cout << "debug: ";
    // for (int i = nt[0]; i != 0; i = nt[i])
    //   cout << i << " ";
    // cout << endl;

    for (int i = nt[0], j = 1; i != 0; i = nt[i], j++) {
      sum += i;
      if (j % 2 != 0) res += i;
    }

    if (isflip && N % 2 == 0)
      printf("Case %d: %lld\n", case_id, sum - res);
    else 
      printf("Case %d: %lld\n", case_id, res);

    case_id++;
  }
  return 0;
}
