#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define Original_Price 10000

bool person[20001];

struct Edge
{
    int to;
    int cost;

    bool operator()(Edge& a, Edge& b)
    {
        return a.cost > b.cost;
    }

    Edge(int _to, int _cost)
    {
        to = _to;
        cost = _cost;
    }

    Edge()
    {
    }
};

int main()
{

    int count;
    cin >> count;
    vector<vector<Edge>> edges;
    priority_queue<Edge, vector<Edge>, Edge> pq;

    while (count--)
    {
        int N, M, R;

        while (cin >> N >> M >> R)
        {
            edges.clear();
            edges.resize(N + M);

            for (int i = 0; i < R; i++)
            {
                int from, to, cost;
                cin >> from >> to >> cost;

                edges[from].push_back(Edge(N + to, Original_Price - cost));
                edges[N + to].push_back(Edge(from, Original_Price - cost));
            }

            int total_cost = 0;
            int total = N + M;

            for (int i = 0; i <total ; i++)
            {
                if (person[i])
                    continue;

                total_cost += Original_Price;
                person[i] = true;

                for (int j = 0; j < edges[i].size(); j++)
                    if (!person[edges[i][j].to])
                        pq.push(edges[i][j]);

                while (!pq.empty())
                {
                    Edge e = pq.top();
                    pq.pop();

                    if (person[e.to]) continue;

                    person[e.to] = true;

                    total_cost += e.cost;

                    for (int i = 0; i < edges[e.to].size(); i++)
                        if (!person[edges[e.to][i].to])
                            pq.push(edges[e.to][i]);
                }
            }

            cout << total_cost << endl;

            memset(person, 0, (N + M) * sizeof(bool));
        }

    }
    return 0;
}
