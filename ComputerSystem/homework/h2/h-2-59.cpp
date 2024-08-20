#include <iostream>

using Word = unsigned char*;

bool is_little_endian() {
    int n = 1;
    char* p = (char*)&n;
    return *p & 0x01;
}

Word clip(Word x, Word y)
{

    Word res = 0;
    unsigned char* p = (unsigned char*) &res;
    unsigned char* px = (unsigned char*) &x;
    unsigned char* py = (unsigned char*) &y;
    bool little_end = is_little_endian();

    for (size_t i = 0; i < sizeof(res); i++) {

        if (little_end) {
            p[i] = i == 0 ? px[i] : py[i];
        } else {
            p[i] = i == sizeof(Word) - 1 ? px[i] : py[i];
        }
    }
    return res;
}

void print_word(Word x, Word y, Word w)
{
    printf("%p clip %p = %p\n", x, y, w);

}

void test() {

    Word x = (Word)0x89ABCDEF;
    Word y = (Word)0x76543210;

    Word res = clip(x, y);

    print_word(x, y, res);


    x = (Word)0x00000001;
    y = (Word)0x12345678;
    res = clip(x, y);
    print_word(x, y, res);
}


int main()
{
    test();

    return 0;
}
