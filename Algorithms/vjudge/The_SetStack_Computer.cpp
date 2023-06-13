#include <iostream>
#include <set>
#include <map>
#include <string>
#include <stack>
using namespace std;

typedef set<int> Set;

map<Set, int> SetToInt; // 将集合转成整数
map<int, Set> IntToSet; // 将整数转为集合
map<int, int> setCnt; // 将整数转成数量
int IDX = 0;

int generateSet(Set&a)
{
    int id;

    if (SetToInt.find(a) == SetToInt.end()) {
        // 该集合不存在
        SetToInt[a] = IDX;
        IntToSet[IDX] = a;
        setCnt[IDX] = a.size();
        id = IDX++;
    } else
        id = SetToInt[a];

    return id;
}

int getCmdID(const string&cmd)
{
    if (cmd == "PUSH")
        return 0;
    if (cmd == "DUP")
        return 1;
    if (cmd == "ADD")
        return 2;
    if (cmd == "UNION")
        return 3;
    if (cmd == "INTERSECT")
        return 4;
    return -1;
}

void PUSH(stack<int>&st)
{
    st.push(0);
}

void DUP(stack<int>&st)
{
    st.push(st.top());
}

void UNION(stack<int>&st)
{
    Set a = IntToSet[st.top()];
    st.pop();
    Set b = IntToSet[st.top()];
    st.pop();

    for (auto id : b) {
        a.insert(id);
    }
    
    st.push(generateSet(a));
}

void INTERSECT(stack<int>&st)
{
    Set a = IntToSet[st.top()];
    st.pop();
    Set b = IntToSet[st.top()];
    st.pop();
    Set c;

    for (auto id : b) {
        if (a.find(id) != a.end()) {
            c.insert(id);
        }
    }
    st.push(generateSet(c));
}

void ADD(stack<int>&st)
{
    int fir = st.top();
    st.pop();
    Set b = IntToSet[st.top()];
    st.pop();
    b.insert(fir);

    st.push(generateSet(b));
}


int main()
{
    int N;
    cin >> N;
    //freopen("output.txt", "w", stdout);
    Set nil;
    SetToInt[nil] = IDX;
    IntToSet[IDX] = nil;
    setCnt[IDX] = IDX;
    IDX++;

    while (N-- > 0)
    {

        int cnt;
        string cmd;
        cin >> cnt;

        stack<int> st;

        for (int i = 0; i < cnt; i++) {
            cin >> cmd;

            switch (getCmdID(cmd))
            {
            case 0:
                PUSH(st);
                break;
            case 1:
                DUP(st);
                break;
            case 2:
                ADD(st);
                break;
            case 3:
                UNION(st);
                break;
            case 4:
                INTERSECT(st);
                break;
            }

            cout << setCnt[st.top()] << endl;
        }
    
        cout << "***" << endl;
    }

    return 0;
}
