#include <iostream>
#include <cassert>
// 思路：二分的思想，开始将32位的数据分为一半，然后让这两半进行异或操作，就可以前一半和后一半中同样都是奇数位的1变为0,相当于消除了2个奇数位的1，
// 以此类推一直循环直到只剩下1位的时候，这时候只需要判断是否为1
int odd_one(unsigned x)
{
    x ^= x >> 16;
    x ^= x >> 8;
    x ^= x >> 4;
    x ^= x >> 2;
    x ^= x >> 1;

    return x & 0x1;
}

void test()
{
    assert(odd_one(0xaaaaaaaa) == 0);
    assert(odd_one(0xa00a00a0) == 0);
    assert(odd_one(0xa0000000) == 0);
    assert(odd_one(0x0000000a) == 0);
    assert(odd_one(0x10000000) == 1);
    assert(odd_one(0x00000001) == 1);
    assert(odd_one(0x10008000) == 0);
    assert(odd_one(0x00108010) == 1);

    printf("test passed\n");

}

int main()
{
    test();
    return 0;
}
