#include <iostream>

using namespace std;

int main()
{
    float v = (3.14f + 1e10f) - 1e10f;

    cout << v << endl; // 结果为0

    v = 3.14f + (1e10f - 1e10f); // 结果为 3.14

    cout << v << endl;


    return 0;
}
