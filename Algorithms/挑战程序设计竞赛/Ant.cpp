#include <iostream>

using namespace std;

int ans[1000001];

int main()
{
    int n;
    int l, m;
    cin>>n;

    while (cin>>l>>m)
    {
        if (cin.eof())
            break;
        
        for (int i = 0; i < m; i++)
        {
            cin>>ans[i];
        }

        int earliest_time = INT_MIN;
        int latest_time= INT_MIN;

        for (int i = 0; i < m; i++)
        {
            earliest_time = max(earliest_time, min(ans[i], l - ans[i]));
            latest_time = max(latest_time, max(ans[i], l - ans[i]));
        }

        printf("%d %d\n", earliest_time, latest_time);
    }
    return 0;
}