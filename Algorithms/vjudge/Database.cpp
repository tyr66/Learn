#include <iostream>
#include <map>
#include <string>
#include <set>
#include <vector>
using namespace std;

const int MAXR = 10000 + 5;
const int MAXC = 10 + 5;
int N, M;
string strs[MAXR][MAXC];

int main()
{
    freopen("output.txt", "w", stdout);

    while (cin >> N >> M)
    {
        int id = 0;
        map<string, int> strToID;
        map<pair<int, int>, vector<int>> pairMap;
        
        cin.get();
        
        for (int i = 0; i < N; i++)
        {
            string s;

            getline(cin, s);
            cin.get();

            for (int j = 0; j < M; j++)
            {
                if (j != M - 1) {

                    int pos = s.find(',');
                    strs[i][j] = s.substr(0, pos);
                    strToID[strs[i][j]] = id++;
                    s = s.substr(pos + 1, s.size() - pos - 1);
                } else {
                    strs[i][j] = s;
                    strToID[strs[i][j]] = id++;
                }
            }
        }

        bool is_find = false;

        for (int c1 = 0; c1 < M; c1++)
        {
            for (int c2 = c1 + 1; c2 < M; c2++)
            {
                for (int r = 0; r < N; r++)
                {
                    auto pair =  make_pair(strToID[strs[r][c1]], strToID[strs[r][c2]]);

                    if (pairMap.find(pair) != pairMap.end()) {
                        for (auto r1 : pairMap[pair]) {
                            cout << r1 + 1 << " " << r + 1 << endl;
                            cout << c1 + 1 << " " << c2 + 1 << endl;
                        }

                        is_find = true;
                    }

                    pairMap[pair].push_back(r);
                }

                pairMap.clear();
            }
        }

        if (is_find)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }

    return 0;
}