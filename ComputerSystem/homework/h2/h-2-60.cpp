#include <iostream>

using Pointer  = unsigned char*;
bool is_error;

bool is_little_endian() {
    int n = 1;
    char* p = (char*)&n;
    return *p & 0x01;
}


unsigned replace_byte(unsigned x, int i, unsigned char b)
{
    unsigned char* p = (unsigned char*)&x;

    while(i > 0) {
        p++;
        i--;
    }

    *p = b;

    return x;
}


// 更好的解决方案
unsigned replace_byte_2(unsigned x, int i, unsigned char b)
{
    is_error = false;

    if (i < 0) {
        printf("i is negative\n");
        is_error = true;
        return 0;
    }

    if (i >= sizeof(x)) {
        printf("i is bigger than sizeof(x)\n");
        is_error = true;
        return 0;
    }

    unsigned mask = ((unsigned)0xff) << (i << 3);
    unsigned v = ((unsigned)b) << (i << 3);

    return (x & ~mask) | v;
}


void test()
{
    unsigned res = replace_byte_2(0x12345678, 4, 0xab);

    if (!is_error) 
        printf("0x1245678 ,2 , 0xab = %.8x\n", res);

    res = replace_byte_2(0x12345678, -1, 0xab);
    if (!is_error)
        printf("0x1245678 ,2 , 0xab = %.8x\n", res);

    res = replace_byte_2(0x12345678, 2, 0xab);
    if (!is_error)
        printf("0x1245678 ,2 , 0xab = %.8x\n", res);

    res = replace_byte_2(0x12345678, 0, 0xab);
    if (!is_error)
        printf("0x1245678 ,0 , 0xab = %.8x\n", res);
}


int main()
{
    test();
}
