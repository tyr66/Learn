#include <iostream>

int func() {
    return 88;
}

int funcint(int a, int b, int c, int d, int e, int f){
    return a;
}

int funcpoint(int* a, int b) {
    return a[b];
}

int func_point_size_t(int* a, size_t b) {
    return a[b];
}

