#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct Task
{
    bool isTar;
    int priority;
};

int main()
{
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;

    while (T-- > 0) {

        int N, tar;
        queue<Task> que;
        priority_queue<int> pque;
        cin >> N >> tar;

        for (int i = 0, val; i < N; i++) {
            cin >> val;

            if (i == tar) {
                que.push({true, val});
            } else {
                que.push({false, val});
            }
            pque.push(val);
        }

        int cnt = 0;

        while (!que.empty()) {

            Task task = que.front();
            que.pop();

            if (task.priority != pque.top()) {
                que.push(task);
            } else if (task.isTar) {
                cnt++;
                break;
            } else {
                cnt++;
                pque.pop();
            }
        }

        cout << cnt << endl;
    }
    
    return 0;
}