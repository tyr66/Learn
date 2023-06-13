#include <iostream>
#include <stack>

using namespace std;
int a[1002];

int main()
{
    freopen("output.txt", "w", stdout);
    int N;

    while (cin >> N && N != 0)
    {
        while (true)
        {
            stack<int> st;

            for (int i = 1; i <= N; i++)
            {
                cin >> a[i];
                if (a[1] == 0) break;
            }

            if (a[1] == 0)
                break;

            int j = 1;
            for (int i = 1; i <= N; i++)
            {

                st.push(i);

                while (!st.empty() && st.top() == a[j])
                {
                    st.pop();
                    j++;
                }
            }

            while (!st.empty() && st.top() == a[j])
            {
                st.pop();
                j++;
            }

            if (st.empty())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }

        cout << endl;
    }

    return 0;
}