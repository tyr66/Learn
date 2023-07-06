#include <iostream>
#include <cstdio>
using namespace std;

template<class Func>
void call_twice(Func const & func)
{
    cout << "sizeof func is " << sizeof(func) << endl;
    cout << func(0) << endl;
    cout << func(1) << endl;
}

void test1()
{
    int fac = 20;
    auto twice = [](int n) {return n* 2;};
    auto twice_fac = [&](int n) { return n * fac;};

    call_twice(twice);
    call_twice(twice_fac);
}

int main()
{
    test1();
    return 0;
}
