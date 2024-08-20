#include <iostream>
#include <cassert>
int leftmost_one(unsigned x)
{
    x |= x >> 1;
    x |= x >> 2;
    x |= x >> 4;
    x |= x >> 8;
    x |= x >> 16;

    return (x >> 1) + (x & 0x1);
}

void test()
{
    assert(leftmost_one(0) == 0);
    assert(leftmost_one(0x00010000) == 0x00010000);
    assert(leftmost_one(0x80000000) == 0x80000000);
    assert(leftmost_one(0x0a030103) == 0x08000000);
    assert(leftmost_one(0x00000001) == 0x00000001);
    assert(leftmost_one(0x000fffff) == 0x00080000);

    printf("test passed\n");
}

int main()
{
    test();
    return 0;
}
