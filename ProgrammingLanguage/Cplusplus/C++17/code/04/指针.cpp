#include <iostream>

void func(int* a, int* b, int* c) {
    *a = *c;
    *a = *b;
}

void func2(int* __restrict a, const int* b, const int* c) {
    *a = *c;
    *a = *b;
}

int func3(int *a) {

    *a = 42;
    return *a;
}

int func4(volatile int *a) {

    *a = 42;
    return *a;
}

void func5(int *a) {
    a[0] = 123;
    a[1] = 456;
}

void func6(int *a){
    a[0] = 123;
    a[2] = 456;
}

void func7(int* a) {
    a[0] = 123;
    a[1] = 456;
    a[2] = 789;
    a[3] = 10;
}


// 需要开启=march=native 才能启用AVX
void func8(int* a) {

    a[0] = 0;
    a[1] = 1;
    a[2] = 2;
    a[3] = 3;
    a[4] = 4;
    a[5] = 5;
    a[6] = 6;
    a[7] = 7;
}

void func9(int *a, int N) {
    for (int i = 0; i < N; i++)
        a[i] = 0;
}

