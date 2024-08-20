#include <iostream>
#include <cassert>

int any_odd_one(int x)
{
    return !!(0xaaaaaaaa & x);
}

void test()
{
    assert(any_odd_one(1) == 0);
    assert(any_odd_one(10) == 1);
    assert(any_odd_one(0) == 0);
    assert(any_odd_one(INT_MIN + 1) == 1);
    assert(any_odd_one(0x01001000) == 0);
    assert(any_odd_one(0x08002000) == 1);
    printf("test passed!!\n");
}

int main()
{
    test();
    return 0;
}
