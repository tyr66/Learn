#include <iostream>
#include <map>
using namespace std;

void scanf_tree(map<int, int>& distToSum, int dist)
{
  int left, right;

  if (cin >> left && left != -1) {
    distToSum[dist - 1] += left;
    scanf_tree(distToSum, dist - 1);
  }

  if (cin >> right && right != -1) {
    distToSum[dist + 1] += right;
    scanf_tree(distToSum, dist + 1);
  }
}

int main()
{
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  map<int, int> distToSum;
  int cnt = 1;
  int root;
  while (cin >> root && root != -1)
  {
    bool is_first = true;
    distToSum[0] = root;
    scanf_tree(distToSum, 0);

    cout << "Case " << cnt++ << ":" << endl;

    for (auto p : distToSum) {
      if (is_first) {
        cout << p.second;
        is_first = false;
      } else { 
        cout << " " << p.second;
      }
    }

    cout << endl << endl;

    distToSum.clear();
  }
  return 0;
}
