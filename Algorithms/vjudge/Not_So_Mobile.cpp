#include <iostream>

using namespace std;

// int cnt = 0;

int blance()
{
  int wl, dl;
  int wr,dr;

  cin >> wl >> dl >> wr >> dr;
  //cnt++;

  if (wl == 0) {
    wl = blance();
  }

  if (wr == 0) {
    wr = blance();
  }

  if (wl > 0 && wr > 0 && wl * dl == wr * dr)
    return wl + wr;

  return -1;
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int N;
  cin >> N;
  while (N-- > 0) {
    if (blance() > 0)
      cout << "YES" << endl;
    else 
      cout << "NO" << endl;

    /* cout << cnt << endl;
    cnt = 0; */
    if (N != 0)
    cout << endl;
  }
  return 0;
}
