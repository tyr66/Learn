#include <iostream>
#include <vector>
#include <string>
#include <cstring>

using namespace std;
const int MAX = 100000 + 5;
int next_char[MAX];
char ch[MAX];

void func();

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    char c;
    int i = 1, prev = 0;

    while (scanf("%s", ch + 1) == 1) 
    {
        int cur,last;
        int len = strlen(ch + 1);
        next_char[0] = 0;
        cur = last = 0;

        for (int i = 1; i <= len; i++) {
            if (ch[i] == '[') {
                cur = 0;
            } else if (ch[i] == ']') {
                cur = last;
            } else {
                next_char[i] = next_char[cur];
                next_char[cur] = i;
                if (last == cur) last = i;
                cur = i;
            }
        }

        for (int i = next_char[0]; i != 0; i = next_char[i])
            cout << ch[i];
        cout << endl;
    }
    return 0;
}


void func()
{
  cout << "test" << endl;
}
