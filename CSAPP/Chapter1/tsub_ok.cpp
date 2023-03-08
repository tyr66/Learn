#include <iostream>

using namespace std;

int add_ok(int x, int y)
{
    int sum = x + y;

    if (x >= 0 && y >= 0 && sum < 0) return 0;
    if (x < 0 && y < 0 && sum >= 0) return 0;

    return 1;
}

// 存在bug
int tsub_ok(int x, int y)
{
    return add_ok(x, -y);    
}

int fix_tsub_ok(int x, int y)
{
    if (y == INT_MIN && x >= 0)
        return 0;
    if (y == INT_MIN && x < 0)
        return 1;

    return add_ok(x, -y);
}

int main()
{
    // 应该检测出溢出
    cout << tsub_ok(1, INT_MIN) << endl;// 输出1
    // 不应该发生溢出
    cout << tsub_ok(-1, INT_MIN) << endl; // 输出0


    cout <<fix_tsub_ok(1, INT_MIN) << endl; // 输出0
    cout <<fix_tsub_ok(-1, INT_MIN) << endl; // 输出1
    return 0;
}
