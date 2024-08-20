#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int N; cin >> N;
    getchar();

    while (N-- > 0)
    {
        stack<char> st;
        string str; getline(cin, str);
        int cnt = 0;

        for (auto c : str)
        {
            if (c == '[' || c == '(')
                st.push(c);
             else if (c == ']' || c == ')') {

                if (st.empty()) break;
                if (c== ']' && st.top() != '[') break;
                if (c == ')' && st.top() != '(') break;
                st.pop();
            }
            cnt++;
        }

        if (st.empty() && cnt == str.size())
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;

    }

    return 0;
}
