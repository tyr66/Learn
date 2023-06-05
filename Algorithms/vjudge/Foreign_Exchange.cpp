#include <iostream>
#include <map>
#include <set>

using namespace std;

int main()
{
    int N;
    //freopen("output.txt", "w", stdout);

    while (cin >> N && N != 0)
    {
        int from, to;
        set<pair<int,int>> pairSet;
        int cnt = 0;

        for (int i = 0; i < N; i++) {
            cin >> from >> to;
            auto pa = make_pair(to, from);

            if (pairSet.count(pa)) {
                cnt--;
            } else {
                pairSet.insert(make_pair(from, to));
                cnt++;
            }
        }

        if (cnt == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}