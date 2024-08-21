#include <iostream>

void test()
{
    int n = (int)-1e100;
    std::cout << "(int)1e10 = " << n << std::endl;

    double m = -1.999;
    int k = (int)m;
    std::cout << "-1.999 = " << k << std::endl;

    k = -1 / 3;
    std::cout << "-1/3 = " << k << std::endl;
}

void test2()
{
    int x = -15213;
    std::cout << "x = -15213, x >> 1 = " << ((x + (1 << 1) - 1) >> 1) << " ,x / 2 = " << x / 2 << std::endl;
    double y = -1.933;
    std::cout << "-1.333 to int = " << (int)y << std::endl;
    int z = (-6 + 5 - 1)/5;
    std::cout << "-6 / 5 = " << z << std::endl;
}

int main() {

    test2();
    return 0;
}
