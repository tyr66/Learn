#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
using namespace std;

const int NODE_N = 52 + 5;
vector<int> adj[NODE_N];
int indegree[NODE_N];

int get_node_id(char c, char s) {
    return (c - 'A') * 2 + (s == '+' ? 0 : 1);
}

bool has_cycle()
{
    int cnt = 0;
    queue<int> que;

    for (int i = 0; i < NODE_N; i++)
        for (auto v : adj[i]) indegree[v]++;

    for (int i = 0; i < NODE_N; i++)
        if (indegree[i] == 0) que.push(i);

    cnt = que.size();

    while (!que.empty())
    {
        int n = que.front(); que.pop();

        for (auto v : adj[n]) {
            if (--indegree[v] == 0) {
                que.push(v); cnt++;
            }
        }
    }

    return cnt == NODE_N;
}

void connect(char c1, char s1, char c2, char s2)
{
    if (c1 == '0' || c2 == '0')
        return;
    adj[get_node_id(c1, s1) ^ 1].push_back(get_node_id(c2, s2));
}

void clear_state()
{
    memset(indegree, 0, sizeof(indegree));
    for (int i = 0; i < NODE_N; i++)
        adj[i].clear();
}


int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w",stdout);

    int N;
    while (cin >> N)
    {
        string s;

        for (int k = 0; k < N; k++)
        {
            cin >> s;

            for (int i = 0; i < 4; i++) {
                for (int j = 0; j < 4; j++) {
                    if (i != j) {
                        connect(s[i * 2], s[i * 2 + 1], s[j * 2], s[j * 2 + 1]);
                    }
                }
            }
        }

        if (!has_cycle())
            cout << "unbounded" << endl;
        else 
            cout << "bounded" << endl;

        clear_state();

    }
    return 0;
}

