#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int N;
    while (cin >> N && N != 0)
    {

        queue<int> que;
        for (int i = 1; i <= N; i++) {
            que.push(i);
        }

        bool is_fir = true;
        cout << "Discarded cards:" ;

        while (que.size() != 1)
        {
            if (is_fir) {
                cout << " " << que.front();
                is_fir = false;
            } else {
                cout << ", " << que.front();
            }

            que.pop();
            que.push(que.front());
            que.pop();
        }

        cout << endl << "Remaining card: " << que.front() << endl;

    }
    return 0;
}