#include <iostream>
#include <cassert>

// 条件1 : !(~x)
// 条件2 : !(x)
// 条件3 : !(~(x | ~0xff))
// 条件4 : !(x >> ((sizeof(x) - 1) << 3) & 0xff)
bool judge(int x) 
{
    bool res = !(~x) ;
    res = res || !x;
    res = res || !(~(x | ~0xff)) ;
    res = res || !((x >> ((sizeof(int) - 1) << 3)) & 0xff);
    return res;
}

bool A(int x) {
    return !(~x);
}
bool B(int x) {
    return !x;
}
bool C(int x) {
    return !(~(x | ~0xff)) ;
}
bool D(int x) {
    return !((x >> ((sizeof(int) - 1) << 3)) & 0xff);
}

void test()
{
    assert(!A(0));
    assert(B(0));
    assert(!C(0));
    assert(D(0));

    assert(A(-1));
    assert(!B(-1));
    assert(C(-1));
    assert(!D(-1));

    assert(!A(0x123456ff));
    assert(!B(0x123456ff));
    assert(C(0x123456ff));
    assert(!D(0x123456ff));

    assert(!A(0x00123456));
    assert(!B(0x00123456));
    assert(!C(0x00123456));
    assert(D(0x00123456));

    printf("test passed!!!\n");

}

int main()
{
    test();
    return 0;
}
