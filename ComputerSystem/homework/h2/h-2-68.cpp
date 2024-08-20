#include <iostream>
#include <cassert>

int lower_one_mask(int x)
{
    int n = x >> 1;
    int m = x - n;

    int res = ((int)-1) << n << m;
    return ~res;
}

void test()
{
    assert(lower_one_mask(0) == 0);
    assert(lower_one_mask(7) == 0x0000007f);
    assert(lower_one_mask(32) == -1);
    assert(lower_one_mask(1) == 0x00000001);

    printf("test passed!!\n");
}

int main()
{
    test();
    return 0;
}
