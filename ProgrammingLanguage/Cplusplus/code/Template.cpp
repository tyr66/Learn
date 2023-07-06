#include <iostream>

using namespace std;

constexpr bool is_negative(int n)
{
    return n < 0;
}

template<bool debug>
int  sum(int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res += i;
        if constexpr (debug) 
            cout << i << " th:" << res<< endl;
    }

    return res;
}

int main()
{
    constexpr bool debug = is_negative(-10);
    cout << sum<debug>(10) << endl;

    for (int i = -2; i < 10; i++)
        cout << i << " is negative " << is_negative(i) << endl;

    return 0;
}
