#include <iostream>
#include <vector>
#include<queue>
using namespace std;

class RecentCounter
{
public:
    RecentCounter()
    {
    }

    int ping(int t)
    {
        que.push(t);

        while(que.front()<t-3000)
        {
            que.pop();
        }

        return que.size();
    }

private:
    queue<int> que;
};

int main()
{
    return 0;
}