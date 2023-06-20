#include <iostream>

using namespace std;

const int MAX = 20;

// bool nodes[1 << MAX];

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int N;
  cin >> N;
  int D, I;

  while (cin >> D && D != -1) 
  {
    cin >> I;

    // memset(nodes, 0, sizeof(bool) * (1 << D));
    int id = 1;
    I--;

    while (id * 2 < (1 << D)) {
      if (I % 2 == 0) {
        id = id * 2 ;
        I = I / 2;
      } else {
        id = id * 2 + 1;
        I = I / 2;
      }
    }

    cout << id << endl;

  }


  return 0;
}
