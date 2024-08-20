#include <iostream>

struct Data {
    int a[2];
    double d;
};

double func(int i) {
    Data a;
    a.d = 3.14;
    a.a[i] = 1073741824;
    return a.d;
}

int main()
{
    std::cout << func(0) << std::endl;
    std::cout << func(1) << std::endl;
    std::cout << func(2) << std::endl;
    std::cout << func(3) << std::endl;
    std::cout << func(4) << std::endl;
    std::cout << func(5) << std::endl;
    std::cout << func(6) << std::endl;
    return 0;
}
