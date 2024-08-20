#include <iostream>

static int other(int a) {
    return a;
}

int func(int b) {
    return other(b);
}
