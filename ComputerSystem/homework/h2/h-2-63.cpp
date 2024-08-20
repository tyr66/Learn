#include <iostream>
#include <cassert>

unsigned srl(unsigned x, int k)
{
    unsigned v = x >> k;
    size_t w = sizeof(int) << 3;
    unsigned mask = (int)(-1) << (w - k);
    return v & (~mask);
}

int sra(int x, int k)
{
    int xsrl = (unsigned) x >> k;
    size_t w = sizeof(int) >> 3;
    int a = 1 << (w - 1);
    int mask = (int)-1 << (w - k);
    mask &= !(x & a) - 1;
    return xsrl | mask;
}

void test()
{
    int x = 0xa1234567;
    int k = 4;
    assert(srl(x, k) == 0x0a123456);
    assert(sra(x, k) == (x >> k));

    x = 0x71234567;
    k = 4;
    assert(srl(x, k) == (x >> k));
    assert(sra(x, k) == (x >> k));

    printf("test passed!!\n");
}

int main()
{
    test();
    return 0;
}
