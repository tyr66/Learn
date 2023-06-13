#include <stack>
#include <string>
#include <map>
#include <iostream>

struct Dim
{
    int n,m;
};

using namespace std;

long long cal(stack<Dim>&st)
{
    stack<Dim> calSt;
    while (!st.empty() && st.top().m != -1) {
        calSt.push(st.top());
        st.pop();
    }

    long long res = 0;
    while (calSt.size() > 1) {
        Dim a = calSt.top(); calSt.pop();
        Dim b = calSt.top(); calSt.pop();
        
        if (a.n != b.m) {
            return -1;
        }
        
        res +=a.m *b.m * b.n;

        //cout << "res == " << res << endl;

        calSt.push({b.n, a.m});
    }

    st.top().m = calSt.top().m;
    st.top().n = calSt.top().n;

    return res;
}

int main()
{
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    int N;
    map<char,Dim> matrixs;
    string str;
    cin >> N;

    char c;
    for (int i = 0; i < N; i++) {
         cin >> c; cin >> matrixs[c].m >> matrixs[c].n;
    }

    while (cin >> str)
    {
        stack<Dim> st;
        long long res = 0;
        bool is_failed = false;
        for (int i = 0; i <str.size(); i++) {
            if (str[i] == '(') {
                st.push({-1, -1});
            } else if (isalpha(str[i])) {
                st.push(matrixs[str[i]]);
            } else {
                long long cnt = 0;
                if ((cnt = cal(st)) < 0) {
                    is_failed = true;
                    break;
                }
                res += cnt;
            }
        }

        if (is_failed)
            cout << "error" << endl;
        else 
            cout << res << endl;
        
    }

    
    return 0;
}