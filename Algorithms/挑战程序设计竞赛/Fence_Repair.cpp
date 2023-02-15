#include <iostream> 
#include <algorithm>
#include <queue>
using namespace std;

typedef long long LL;

int main()
{
    int N;
    while (cin >> N)
    {
        priority_queue<LL, vector<LL>, greater<LL>> pq;

        for (int i = 0; i < N; i++) {
            LL val;
            cin >> val;
            pq.push(val);
        }

        LL cost = 0;

        while (pq.size() > 1)
        {
            LL sum = pq.top(); pq.pop();
            sum += pq.top();pq.pop();
            cost += sum;
            pq.push(sum);
        }

        cout << cost << endl;

    }
    return 0;
}
