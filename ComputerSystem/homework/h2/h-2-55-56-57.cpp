#include <iostream>

using Pointer = unsigned char*;

void print_byte(Pointer pointer, size_t len)
{
    for (size_t i = 0; i < len; i++) {
        printf("%p\tox%.2x\n", pointer + i, pointer[i]);
    }
    printf("\n");
}

template<typename T>
void show_byte(T n) {
    print_byte((Pointer)&n , sizeof(n));
}

int main()
{
    int n = 1;
    show_byte(n);

    double d = 1.0;
    show_byte(d);

    short s = 2;
    show_byte(s);

    long l = LONG_MAX;
    show_byte(l);
}
